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

template<typename MBC>
struct PPU {
    MMU<MBC>* mmu;

    bool active = true;
    bool vblank = false;
    PPU_Mode current_mode;  // <=> STATE[0-1] || vblank, cf PPU_Mode
    i16 current_mode_remaining_cycles;

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
                            /*             u8 low = mmu.read(_VRAM_START + 16*(20*y+x) + 2*iline); */
                            /*             u8 high = mmu.read(_VRAM_START + 16*(20*y+x) + 2*iline + 1); */
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

                            mmu->set_bit(_IF, 0);  // vblank interrupt
                        }

                        if(!vblank) {  // draw line TODO sprites TODO check
                            assert(mmu->can_access_oam && mmu->can_access_vram);
                            u8 SCY = mmu->read(_SCY);
                            u8 SCX = mmu->read(_SCX);
                            u8 tile_y = ((u8)(LY+SCY))/8;
                            u8 subline = ((u8)(LY+SCY))%8;
                            for(u8 x=0 ; x <= 20 ; x++) {
                                u8 tile_x = ((u8)(8*x + SCX))/8;
                                u8 idx = mmu->read(0x9800 + 32*tile_y + tile_x);
                                u8 low = mmu->read(_VRAM_START + 16*idx + subline*2);
                                u8 high = mmu->read(_VRAM_START + 16*idx + subline*2 + 1);
                                for(u8 icol=0 ; icol<8 ; icol++) {
                                    u8 val = bit_check(low, icol) | (bit_check(high, icol) << 1);
                                    u8 g = 85*val;
                                    the_ghandler.fb[LY][(u8)(SCX+8*x+7-icol)] = Color{g,g,g};
                                }
                            }
                        }

                        // TODO LYC

                        mmu->write(_LY, LY);
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
                    break;

                default: unreachable();
            }

            u8 STAT = mmu->read(_STAT);
            u8 new_mode = vblank ? 1 : current_mode;
            STAT = (STAT & (~0x03)) | new_mode;
            mmu->write(_STAT, STAT);

            mmu->can_access_oam =  vblank || current_mode == MODE_HBLANK;
            mmu->can_access_vram = vblank || current_mode != MODE_OAM_VRAM;

        }  // mode changed

    } // update()
};
