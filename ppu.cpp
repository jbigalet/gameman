// OAM acces --- OAM + VRAM --- HBLANK
// OAM acces --- OAM + VRAM --- HBLANK
// ...................................
// VBLANK
//
//  OAM      Mode 2 (77 -83  cycles):  2_____2_____2_____2_____2_____2___________________2____
//  OAM+VRAM Mode 3 (169-175 cycles):  _33____33____33____33____33____33__________________3___
//  HBLANK   Mode 0 (201-207 cycles):  ___000___000___000___000___000___000________________000
//  VBLANK   Mode 1 (4560    cycles):  ____________________________________11111111111111_____
//

enum PPU_Mode {
    MODE_HBLANK = 0,
    MODE_VBLANK = 1,
    MODE_OAM = 2,
    MODE_OAM_VRAM = 3
};

struct Sprite {
    u8 pos_y;
    u8 pos_x;
    u8 tile_idx;

    u8 palette_bank;
    bool y_flip;
    bool x_flip;
    bool behind_background;

    bool operator<(const Sprite& s) const {
        return pos_x < s.pos_x;
    }
};

template<typename MBC>
struct PPU {
    MMU<MBC>* mmu;

    bool active = true;
    bool vblank = false;
    PPU_Mode current_mode = MODE_HBLANK;  // <=> STATE[0-1] || vblank, cf PPU_Mode
    i16 current_mode_remaining_cycles = 0;

    void enable() {
        active = true;
        current_mode = MODE_HBLANK;
        current_mode_remaining_cycles = 0;
        mmu->write(_LY, 143);  // vblank start
        vblank = true;
    }

    void disable() {
        active = false;
        vblank = true;
        mmu->can_access_oam =  true;
        mmu->can_access_vram = true;
    }

    std::vector<Color> read_palette(u16 addr) {
        u8 p = mmu->read(addr);
        std::vector<Color> palette;
        for(u8 bit=0 ; bit<8 ; bit+=2) {
            u8 val = (p >> bit) & 0b11;
            u8 g = 255-85*val;
            palette.push_back(Color{g,g,g});
        }
        return palette;
    }

    void update(u16 cycle_count) {
        // TODO handle variable mode cycles
        // atm we use 204, 4560, 80 & 172  (=456 line cycles)

        bool new_active = bit_check(mmu->read(_LCDC), 7);  // TODO could update when LCDC is actually written
        if(new_active != active) {
            if(new_active)
                enable();
            else
                disable();
        }

        if(!active) return;

        current_mode_remaining_cycles -= cycle_count;
        if(current_mode_remaining_cycles < 0) {

            // TODO some STAT conditions makes next condition to be ignored
            u8 STAT = mmu->read(_STAT);

            // do stuff + switch mode
            switch(current_mode) {
                case MODE_HBLANK:  // end of line, go to next one
                    {
                        u8 LY = mmu->read(_LY);
                        LY++;
                        if(LY > 153) {  // end of VBLANK
                            LY = 0;
                            vblank = false;
                        } else if(LY == 144) {  // start of VBLANK
                            vblank = true;

                            /* // debug: draw tiles */
                            /* for(u16 y=0 ; y<18 ; y++) */
                            /*     for(u16 x=0 ; x<20 ; x++) */
                            /*         for(u16 iline=0 ; iline<8 ; iline++){ */
                            /*             u8 low = mmu->read(_VRAM_START + 16*(20*y+x) + 2*iline); */
                            /*             u8 high = mmu->read(_VRAM_START + 16*(20*y+x) + 2*iline + 1); */
                            /*             /1* u8 low = mmu.read(0x8410 + 2*iline); *1/ */
                            /*             /1* u8 high = mmu.read(0x8410 + 2*iline + 1); *1/ */
                            /*             for(u8 icol=0 ; icol<8 ; icol++) { */
                            /*                 u8 val = bit_check(low, icol) | (bit_check(high, icol) << 1); */
                            /*                 u8 g = 85*val; */
                            /*                 the_ghandler.fb[8*y+iline][8*x+7-icol] = Color{g, g, g}; */
                            /*             } */
                            /*         } */

                            the_ghandler.handle_events();

                            assert(mmu->can_access_oam && mmu->can_access_vram);
                            the_ghandler.draw();

                            mmu->set_bit(_IF, 0);  // VBLANK interrupt

                            if(bit_check(STAT, 4)) // STAT VBLANK interrupt
                                mmu->set_bit(_IF, 1);

                            if(bit_check(STAT, 5)) // STAT OAM interrupt  (that also needs to happen at the start of vblank)
                                mmu->set_bit(_IF, 1);
                        }

                        if(!vblank) {  // draw line TODO sprites TODO check
                            assert(mmu->can_access_oam && mmu->can_access_vram);

                            // TODO window

                            // background

                            u8 LCDC = mmu->read(_LCDC);
                            u16 bck_index_start = bit_check(LCDC, 3) ? 0x9C00 : 0x9800;
                            bool tile_data_at_8000 = bit_check(LCDC, 4);  // if not, starts at 9000 & index is signed
                            u16 tile_start = tile_data_at_8000 ? 0x8000 : 0x9000;

                            // background palette
                            std::vector<Color> palette = read_palette(_BGP);

                            u8 SCY = mmu->read(_SCY);
                            u8 SCX = mmu->read(_SCX);
                            /* std::cout << "SCX: " << (i32)SCX << std::endl; */
                            u8 tile_y = ((u8)(LY+SCY))/8;
                            u8 subline = ((u8)(LY+SCY))%8;
                            u8 x = 0;
                            while(x < 160) {
                                u8 tile_x = ((u8)(x+SCX))/8;
                                u8 col_offset = ((u8)(x+SCX))%8;
                                u16 idx_idx = bck_index_start + 32*tile_y + tile_x;
                                i16 idx = tile_data_at_8000 ? mmu->read(idx_idx) : (i8)mmu->read(idx_idx);
                                u16 tile_info_start = tile_start + 16*idx + subline*2;
                                u8 low = mmu->read(tile_info_start);
                                u8 high = mmu->read(tile_info_start + 1);
                                for(u8 icol=col_offset ; icol<8 ; icol++) {
                                    u8 val = bit_check(low, 7-icol) | (bit_check(high, 7-icol) << 1);
                                    the_ghandler.fb[LY][x] = palette[val];
                                    x++;
                                }
                            }

                            // sprites
                            // TODO enable / disable sprites

                            std::vector<Sprite> todraw;
                            for(u16 isprite=0 ; isprite < 40 ; isprite++) {
                                u8 pos_y = mmu->read(_OAM_START + isprite*4);
                                if(LY+16 >= pos_y && LY+8 < pos_y) {
                                    u8 pos_x = mmu->read(_OAM_START + isprite*4+1);
                                    u8 tile_idx = mmu->read(_OAM_START + isprite*4+2);
                                    u8 flags = mmu->read(_OAM_START + isprite*4+3);

                                    u8 palette_bank = bit_check(flags, 4);
                                    bool x_flip = bit_check(flags, 5);
                                    bool y_flip = bit_check(flags, 6);
                                    bool behind_background = bit_check(flags, 7);

                                    Sprite sprite = {
                                        pos_y,
                                        pos_x,
                                        tile_idx,
                                        palette_bank,
                                        y_flip,
                                        x_flip,
                                        behind_background
                                    };

                                    todraw.push_back(sprite);
                                }
                            }

                            // sort by priority & remove the 11+th sprites
                            std::stable_sort(todraw.begin(), todraw.end());
                            if(todraw.size() > 10)
                                todraw.erase(todraw.begin()+10, todraw.end());

                            // read both palettes
                            std::vector<Color> palette0 = read_palette(_OBP0);
                            std::vector<Color> palette1 = read_palette(_OBP1);

                            for(u8 x=0 ; x<160 ; x++) {
                                for(Sprite s: todraw) {
                                    if(x+8 >= s.pos_x && x < s.pos_x) {
                                        u8 tile_x = x+8 - s.pos_x;
                                        if(!s.x_flip) tile_x = 7-tile_x;
                                        u8 tile_y = LY+16 - s.pos_y;
                                        if(s.y_flip) tile_y = 7-tile_y;
                                        u16 tile_info_start = _VRAM_START + 16*s.tile_idx + tile_y*2;
                                        u8 low = mmu->read(tile_info_start);
                                        u8 high = mmu->read(tile_info_start + 1);
                                        u8 val = bit_check(low, tile_x) | (bit_check(high, tile_x) << 1);

                                        if(val == 0)  // transparent - not drawn, check next sprite
                                            continue;

                                        // behind background & pixel is not white => not draw, check next sprite
                                        if(s.behind_background && !the_ghandler.fb[LY][x].is_white())
                                            continue;

                                        the_ghandler.fb[LY][x] = s.palette_bank == 0 ? palette0[val] : palette1[val];
                                        break;  // won the priority, go to next pixel
                                    }
                                }
                            }


                            if(bit_check(STAT, 5)) // STAT OAM interrupt
                                mmu->set_bit(_IF, 1);

                        }  // end (!vblank) <=> hblank

                        mmu->write(_LY, LY);

                        u8 LYC = mmu->read(_LYC);
                        if(LY == LYC && bit_check(STAT, 6)) // STAT LY==LYC interrupt
                            mmu->set_bit(_IF, 1);

                        // set STAT coincidence flag (0:LY!=LYC, 1:LY==LYC)
                        if(LY == LYC && !bit_check(STAT, 2))
                            STAT = bit_set(STAT, 2);
                        if(LY != LYC && bit_check(STAT, 2))
                            STAT = bit_reset(STAT, 2);
                    }

                    current_mode = MODE_OAM;
                    current_mode_remaining_cycles += 80;
                    break;

                case MODE_OAM:
                    current_mode = MODE_OAM_VRAM;
                    current_mode_remaining_cycles += 172;
                    break;

                case MODE_OAM_VRAM:
                    current_mode = MODE_HBLANK;
                    current_mode_remaining_cycles += 204;

                    if(!vblank && bit_check(STAT, 3)) // STAT HBLANK interrupt
                        mmu->set_bit(_IF, 1);
                    break;

                default: unreachable();
            }

            u8 new_mode = vblank ? 1 : current_mode;
            STAT = (STAT & (~0x03)) | new_mode;
            mmu->write(_STAT, STAT);

            /* std::cout << "current mode " << (u32)new_mode << std::endl; */

            mmu->can_access_oam =  vblank || current_mode == MODE_HBLANK;
            mmu->can_access_vram = vblank || current_mode != MODE_OAM_VRAM;

        }  // mode changed

    } // update()
};
