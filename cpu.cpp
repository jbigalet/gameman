#define DOUBLE_REG(a, b) \
    union {              \
        struct {         \
            u8 b;        \
            u8 a;        \
        };               \
        u16 a##b;        \
    }

struct Registers {
    union {
        struct {
            // flags as both bitfields & single byte
            union {
                struct {
                    bool b0 : 1;
                    bool b1 : 1;
                    bool b2 : 1;
                    bool b3 : 1;
                    bool FC : 1;
                    bool FH : 1;
                    bool FN : 1;
                    bool FZ : 1;
                };
                u8 F;
            };
            u8 A;
        };
        u16 AF;
    };

    DOUBLE_REG(B, C);
    DOUBLE_REG(D, E);
    DOUBLE_REG(H, L);
    u16 SP;
    u16 PC;
};

template<typename MBC>
struct CPU {
    Registers reg;
    MMU<MBC> mmu;
    PPU<MBC> ppu;

    bool IME = false;  // Interrupt Master Enable Flag
    bool halted = false;

    i16 last_op_cycles = 0;
    i32 cycle_until_count = 0;
    i32 cycle_until_div = 0;

    CPU() {
        reset_low_F();
        ppu.mmu = &mmu;
    }

    void cycle_count_advance(i16 cycles) {
        last_op_cycles = cycles;

        // timer

        u8 TAC = mmu.read(_TAC);  // Timer Control (bit 2 = enable ; bit 1-0 = divider)
        if(bit_check(TAC, 2)) {
            cycle_until_count -= cycles;
            if(cycle_until_count < 0) {
                i16 divider;
                switch(TAC & 0b11) {
                    case 0b00:
                        divider = 1024;
                        break;
                    case 0b01:
                        divider = 16;
                        break;
                    case 0b10:
                        divider = 64;
                        break;
                    case 0b11:
                        divider = 256;
                        break;
                    default:
                        std::cout << "TAC: " << to_bit_string(TAC) << std::endl;
                        unreachable();
                }

                u16 TIMA = (u16)mmu.read(_TIMA);  // Timer Counter

                // handle multiple increment at once
                while(cycle_until_count < 0) {
                    TIMA++;
                    cycle_until_count += divider;
                }

                /* std::cout << divider << " " << TIMA << std::endl; */

                bool overflow = false;
                if(TIMA > 0xff) {
                    u8 TMA = mmu.read(_TMA);  // Timer Modulo
                    TIMA = TMA + (TIMA-0x100);
                    overflow = true;
                }

                /* std::cout << divider << " " << TIMA << std::endl; */

                mmu.write(_TIMA, TIMA & 0xff);

                if(overflow) {
                    mmu.set_bit(_IF, 2);
                    /* std::cout << "TIMER OVERFLOW! IF=" << to_bit_string(IF) << std::endl; */
                    /* std::cout << "TIMER OVERFLOW! IE=" << to_bit_string(mmu.read(0xffff)) << std::endl; */
                    /* std::cout << "IME: " << IME << std::endl; */
                }
            }
        }

        // DIV
        cycle_until_div -= cycles;
        if(cycle_until_div < 0) {
            u8 DIV = mmu.read(_DIV);
            DIV++;
            cycle_until_div += 256;
            mmu.write(_DIV, DIV);
        }

        ppu.update(cycles);
    }


    u16 do_cycle() {

        // check interrupts to un-halt
        if(halted && mmu.read(0xff0f) != 0) {
            /* std::cout << "un-halted " << to_bit_string(mmu.read(0xff0f)) << std::endl; */
            halted = false;
        }

        // handle interrupts
        bool interrupt_handled = false;
        if(IME){
            u8 IF = mmu.read(_IF);  // interrupt flag
            u8 IE = mmu.read(_IE);  // interrupt enable
            /* std::cout << "IE: " << to_bit_string(IE) << std::endl; */
            for(u8 i=0 ; i<5 ; i++)
                if(bit_check(IF, i) && bit_check(IE, i)) {
                    /* std::cout << "interrupt! " << (i32)i << std::endl; */
                    IME = false;
                    mmu.write(_IF, bit_reset(IF, i));  // reset IF flag
                    CALL_const16(0x40 + (0x08*i));  // TODO side effects as this update the cycle count ?
                    interrupt_handled = true;
                    break;
                }
        }

        if(!interrupt_handled) {
            if(!halted)
                exec_op();
            else
                cycle_count_advance(1);  // update timer even when halted
        }

        return last_op_cycles;
    }

    void reset_low_F() {
        reg.b0 = false;
        reg.b1 = false;
        reg.b2 = false;
        reg.b3 = false;
    }

    void print_reg() {
        std::string flags = reg.FZ ? "Z" : "-";
        flags += reg.FN ? " N" : " -";
        flags += reg.FH ? " H" : " -";
        flags += reg.FC ? " C" : " -";

        std::cout << "A: " << to_hex_string(reg.A);
        std::cout << "   F: " << to_hex_string(reg.F) << " (" << flags << ")" << std::endl;

        std::cout << "B: " << to_hex_string(reg.B);
        std::cout << "   C: " << to_hex_string(reg.C) << std::endl;

        std::cout << "D: " << to_hex_string(reg.D);
        std::cout << "   E: " << to_hex_string(reg.E) << std::endl;

        std::cout << "H: " << to_hex_string(reg.H);
        std::cout << "   L: " << to_hex_string(reg.L) << std::endl;

        std::cout << "SP: " << to_hex_string(reg.SP);
        std::cout << "   PC: " << to_hex_string(reg.PC) << std::endl;
    }


    void print_reg_diff(Registers old) {
        std::string flags;
        flags += bold(reg.FZ ?  "Z" : "-", reg.FZ != old.FZ);;
        flags += bold(reg.FN ?  "N" : "-", reg.FN != old.FN);;
        flags += bold(reg.FH ?  "H" : "-", reg.FH != old.FH);;
        flags += bold(reg.FC ?  "C" : "-", reg.FC != old.FC);;

        std::string all;

        all += bold("A: " + to_hex_string(reg.A), reg.A != old.A);
        all += bold("   F: " + to_hex_string(reg.F), reg.F != old.F) + " (" + flags + ")" + "\n";

        all += bold("B: " + to_hex_string(reg.B), reg.B != old.B);
        all += bold("   C: " + to_hex_string(reg.C), reg.C != old.C) + "\n";

        all += bold("D: " + to_hex_string(reg.D), reg.D != old.D);
        all += bold("   E: " + to_hex_string(reg.E), reg.E != old.E) + "\n";

        all += bold("H: " + to_hex_string(reg.H), reg.H != old.H);
        all += bold("   L: " + to_hex_string(reg.L), reg.L != old.L) + "\n";

        all += bold("SP: " + to_hex_string(reg.SP), reg.SP != old.SP);
        all += bold("   PC: " + to_hex_string(reg.PC), reg.PC != old.PC) + "\n";

        std::cout << all << std::endl;
    }


    // post boot set values
    void postboot_init() {
        reg.AF = 0x01B0;
        reg.BC = 0x0013;
        reg.DE = 0x00D8;
        reg.HL = 0x014D;
        reg.SP = 0xFFFE;
    }

    u8 read_mem(u16 addr, bool log_history=true) {
        cycle_count_advance(4);
        return mmu.read(addr);
    }

    void write_mem(u16 addr, u8 val, bool log_history=true) {
        cycle_count_advance(4);
        mmu.write(addr, val);
    }


    u8 read_pc_u8() {
        u8 res = read_mem(reg.PC, false);
        reg.PC++;
        return res;
    }

    i8 read_pc_i8() {
        i8 res = read_mem(reg.PC, false);
        reg.PC++;
        return res;
    }

    u16 read_pc_u16() {
        u16 res = read_mem(reg.PC, false);
        reg.PC++;
        res |= read_mem(reg.PC, false) << 8;
        reg.PC++;
        return res;
    }


    // opcode implementation helpers

    void _add(u8* r, u16 toadd, bool with_carry=false) {
        u16 res = (u16)(*r) + toadd;
        u16 low = ((*r) & 0x0f) + (toadd & 0x0f);
        if(with_carry) {
            res += (u16)reg.FC;
            low += (u16)reg.FC;
        }

        (*r) = (u8)res;

        reg.FZ = (*r) == 0;
        reg.FN = false;
        reg.FH = low > 0x0f;
        reg.FC = res > 0xff;
    }

    void _sub(u8* r, u8 tosub, bool with_carry=false) {
        u16 res = (u16)(*r) - (u16)tosub;
        u16 low = ((*r) & 0x0f) - (tosub & 0x0f);
        if(with_carry) {
            res -= (u16)reg.FC;
            low -= (u16)reg.FC;
        }

        (*r) = (u8)res;

        reg.FZ = (*r) == 0;
        reg.FN = true;
        reg.FH = low > 0x0f;
        reg.FC = res > 0xff;
    }

    void _and(u8 val) {
        reg.A &= val;

        reg.FZ = reg.A == 0;
        reg.FN = false;
        reg.FH = true;
        reg.FC = false;
    }

    void _or(u8 val) {
        reg.A |= val;

        reg.FZ = reg.A == 0;
        reg.FN = false;
        reg.FH = false;
        reg.FC = false;
    }

    void _xor(u8 val) {
        reg.A ^= val;

        reg.FZ = reg.A == 0;
        reg.FN = false;
        reg.FH = false;
        reg.FC = false;
    }

    void _cp(u8 tosub) {
        u16 res = (u16)reg.A - (u16)tosub;
        u16 low = (reg.A & 0x0f) - (tosub & 0x0f);

        reg.FZ = ((u8)res) == 0;
        reg.FN = true;
        reg.FH = low > 0x0f;
        reg.FC = res > 0xff;
    }

    u8 _rotate_left(u8 val, bool through_carry=false) {
        // through_carry == false
        //     _________
        //    |         |
        //  C <- 7 <- 0 <
        //
        // through_carry == true
        //   ___________
        //  |           |
        //  C <- 7 <- 0 <
        //

        u8 rotated_bit = through_carry ? reg.FC : val >> 7;
        reg.FC = val >> 7;

        u8 res = (val << 1) | rotated_bit;

        reg.FZ = res == 0;
        reg.FN = false;
        reg.FH = false;

        return res;
    }

    u8 _rotate_right(u8 val, bool through_carry=false) {
        // through_carry == false
        //   _________
        //  |         |
        //  > 7 -> 0 -> C
        //
        // through_carry == true
        //   ___________
        //  |           |
        //  > 7 -> 0 -> C
        //

        u8 rotated_bit = through_carry ? reg.FC : val & 0x01;
        reg.FC = val & 0x01;

        u8 res = (val >> 1) | (rotated_bit << 7);

        reg.FZ = res == 0;
        reg.FN = false;
        reg.FH = false;

        return res;
    }

    u8 _shift_left(u8 val) {
        reg.FC = val >> 7;
        val <<= 1;

        reg.FZ = val == 0;
        reg.FN = false;
        reg.FH = false;

        return val;
    }

    u8 _shift_right(u8 val, bool keep_msb=false) {
        reg.FC = val & 0x01;

        if(!keep_msb)
            val >>= 1;
        else
            val = ((i8)val) >> 1;
            /* val |= val >> 6; */

        reg.FZ = val == 0;
        reg.FN = false;
        reg.FH = false;

        return val;
    }





    // opcode implementations

#define ADD_4BIT_OVERFLOW(a,b) ((a & 0x0f) + (b & 0x0f) > 0x0f)
#define ADD_8BIT_OVERFLOW(a,b) ((a & 0xff) + (b & 0xff) > 0xff)


    // usage: CE
    // flags: Z,0,H,C
    // timings: 8
    void ADC_reg8_const8(u8* r, u8 val) {
        _add(r, val, true);
    }

    // usage: 8E
    // flags: Z,0,H,C
    // timings: 8
    void ADC_reg8_mem(u8* r, u16 addr) {
        _add(r, read_mem(addr), true);
    }

    // usage: 88,89,8A,8B,8C,8D,8F
    // flags: Z,0,H,C
    // timings: 4
    void ADC_reg8_reg8(u8* to, u8* from) {
        _add(to, (*from), true);
    }

    // usage: E8
    // flags: 0,0,H,C
    // timings: 16
    void ADD_reg16_const8(u16* r, u8 val) {
        cycle_count_advance(8);

        i8 rval = (i8)val;

        reg.FZ = false;
        reg.FN = false;
        reg.FH = ADD_4BIT_OVERFLOW((*r), rval);
        reg.FC = ADD_8BIT_OVERFLOW((*r), rval);

        (*r) += rval;
    }

    // usage: 09,19,29,39
    // flags: -,0,H,C
    // timings: 8
    void ADD_reg16_reg16(u16* to, u16* from) {
        cycle_count_advance(4);

        u32 res = (u32)(*to) + (u32)(*from);

        reg.FN = false;
        reg.FH = ((*to) & 0xfff) + ((*from) & 0xfff) > 0x0fff;
        reg.FC = res > 0xffff;

        (*to) = (u16)res;
    }

    // usage: C6
    // flags: Z,0,H,C
    // timings: 8
    void ADD_reg8_const8(u8* r, u8 val) {
        _add(r, val);
    }

    // usage: 86
    // flags: Z,0,H,C
    // timings: 8
    void ADD_reg8_mem(u8* r, u16 addr) {
        _add(r, read_mem(addr));
    }

    // usage: 80,81,82,83,84,85,87
    // flags: Z,0,H,C
    // timings: 4
    void ADD_reg8_reg8(u8* to, u8* from) {
        _add(to, (*from));
    }

    // usage: E6
    // flags: Z,0,1,0
    // timings: 8
    void AND_const8(u8 val) {
        _and(val);
    }

    // usage: A6
    // flags: Z,0,1,0
    // timings: 8
    void AND_mem(u16 addr) {
        _and(read_mem(addr));
    }

    // usage: A0,A1,A2,A3,A4,A5,A7
    // flags: Z,0,1,0
    // timings: 4
    void AND_reg8(u8* r) {
        _and(*r);
    }

    // usage: 46,4E,56,5E,66,6E,76,7E
    // flags: Z,0,1,-
    // timings: 12
    void BIT_const8_mem(u8 bit, u16 addr) {
        assert(bit < 8);
        reg.FZ = ((read_mem(addr) >> bit) & 0x01) == 0;
        reg.FN = false;
        reg.FH = true;
    }

    // usage: 40,41,42,43,44,45,47,48,49,4A,4B,4C,4D,4F,50,51,52,53,54,55,57,58,59,5A,5B,5C,5D,5F,60,61,62,63,64,65,67,68,69,6A,6B,6C,6D,6F,70,71,72,73,74,75,77,78,79,7A,7B,7C,7D,7F
    // flags: Z,0,1,-
    // timings: 8
    void BIT_const8_reg8(u8 bit, u8* r) {
        assert(bit < 8);
        reg.FZ = (((*r) >> bit) & 0x01) == 0;
        reg.FN = false;
        reg.FH = true;
    }

    // usage: CD
    // flags: -,-,-,-
    // timings: 24
    void CALL_const16(u16 addr) {
        PUSH_reg16(&reg.PC);  // 12 cycles
        reg.PC = addr;
    }

    // usage: C4,CC,D4,DC
    // flags: -,-,-,-
    // timings: 24/12
    void CALL_flag_const16(bool flag, u16 addr) {
        if(flag)
            CALL_const16(addr);  // 12 cycles
    }

    // usage: 3F
    // flags: -,0,0,C
    // timings: 4
    void CCF() {
        reg.FN = false;
        reg.FH = false;
        reg.FC = !reg.FC;
    }

    // usage: 2F
    // flags: -,1,1,-
    // timings: 4
    void CPL() {
        reg.A ^= 0xff;
        reg.FN = true;
        reg.FH = true;
    }

    // usage: FE
    // flags: Z,1,H,C
    // timings: 8
    void CP_const8(u8 val) {
        _cp(val);
    }

    // usage: BE
    // flags: Z,1,H,C
    // timings: 8
    void CP_mem(u16 addr) {
        _cp(read_mem(addr));
    }

    // usage: B8,B9,BA,BB,BC,BD,BF
    // flags: Z,1,H,C
    // timings: 4
    void CP_reg8(u8* r) {
        _cp(*r);
    }

    // usage: 27
    // flags: Z,-,0,C
    // timings: 4
    void DAA() {
        // BCD correct A according to the flags (to get some insights on the previous operation)
        // http://www.z80.info/z80syntx.htm#DAA                   ok table, pretty crappy explanations
        // http://z80-heaven.wikidot.com/instructions-set:daa     description only valid for an addition (N not set)
        //                                                        but easily adaptable to the substraction case
        //                                                        & comparable to the table of the above link

        u16 a = reg.A;

        if(!reg.FN) {  // addition
            if(reg.FH || (a & 0x0f) > 0x09)
                a += 0x06;
            if(reg.FC || a > 0x9f)
                a += 0x60;

        } else {  // substraction
            if(reg.FH)
                a = (a - 0x06) & 0xff;  // only &0xff if c not set?
            if(reg.FC)
                a -= 0x60;
        }

        reg.A = (u8)a;

        reg.FZ = reg.A == 0;
        reg.FH = 0;
        reg.FC |= (a & 0x100);
    }

    // usage: 35
    // flags: Z,1,H,-
    // timings: 12
    void DEC_mem(u16 addr) {
        u8 val = read_mem(addr);
        u8 res = val - 1;
        write_mem(addr, res);

        reg.FZ = res == 0;
        reg.FN = true;
        // only possible res after getting a carry is for all the low bytes to be set
        reg.FH = (res & 0x0f) == 0x0f;
    }

    // usage: 0B,1B,2B,3B
    // flags: -,-,-,-
    // timings: 8
    void DEC_reg16(u16* r) {
        cycle_count_advance(4);
        (*r)--;
    }

    // usage: 05,0D,15,1D,25,2D,3D
    // flags: Z,1,H,-
    // timings: 4
    void DEC_reg8(u8* r) {
        u8 val = *r;
        u8 res = val - 1;
        *r = res;

        reg.FZ = res == 0;
        reg.FN = true;
        // only possible res after getting a carry is for all the low bytes to be set
        reg.FH = (res & 0x0f) == 0x0f;
    }

    // usage: F3
    // flags: -,-,-,-
    // timings: 4
    void DI() {
        // disable interrupts after the next command TODO
        IME = false;
        /* std::cout << "DI CMD" << std::endl; */
    }

    // usage: FB
    // flags: -,-,-,-
    // timings: 4
    void EI() {
        // enable interrupts after the next command TODO
        IME = true;
        /* std::cout << "EI CMD" << std::endl; */
    }

    // usage: 76
    // flags: -,-,-,-
    // timings: 4
    void HALT() {
        /* std::cout << "HALT CMD ; IF=" << to_bit_string(mmu.read(0xff0f)) << std::endl; */
        /* std::cout << " ; IE=" << to_bit_string(mmu.read(0xffff)) << std::endl; */
        mmu.write(0xff0f, 0);  // TODO not sure // not write_mem cause not actually taking cycles
        halted = true;
    }

    // usage: 34
    // flags: Z,0,H,-
    // timings: 12
    void INC_mem(u16 addr) {
        u8 val = read_mem(addr);
        u8 res = val + 1;
        write_mem(addr, res);

        reg.FZ = res == 0;
        reg.FN = false;
        reg.FH = ADD_4BIT_OVERFLOW(val, 1);
    }

    // usage: 03,13,23,33
    // flags: -,-,-,-
    // timings: 8
    void INC_reg16(u16* r) {
        cycle_count_advance(4);
        (*r)++;
    }

    // usage: 04,0C,14,1C,24,2C,3C
    // flags: Z,0,H,-
    // timings: 4
    void INC_reg8(u8* r) {
        u8 val = *r;
        u8 res = val + 1;
        *r = res;

        reg.FZ = res == 0;
        reg.FN = false;
        reg.FH = ADD_4BIT_OVERFLOW(val, 1);
    }

    // usage: C3
    // flags: -,-,-,-
    // timings: 16
    void JP_const16(u16 addr) {
        cycle_count_advance(4);
        reg.PC = addr;
    }

    // usage: C2,CA,D2,DA
    // flags: -,-,-,-
    // timings: 16/12
    void JP_flag_const16(bool flag, u16 addr) {
        if(flag)
            JP_const16(addr);  // 4 cycles
    }

    // usage: E9
    // flags: -,-,-,-
    // timings: 4
    void JP_mem(u16 addr) {
        // wrong doc =(
        // jump to addr, not to addr fetched from mem
        reg.PC = addr;
    }

    // usage: 18
    // flags: -,-,-,-
    // timings: 12
    void JR_const8(i8 offset) {
        JP_const16((i16)reg.PC + (i16)offset);  // 4 cycles
    }

    // usage: 20,28,30,38
    // flags: -,-,-,-
    // timings: 12/8
    void JR_flag_const8(bool flag, i8 offset) {
        if(flag)
            JR_const8(offset);  // 4 cycles
    }

    // usage: E0
    // flags: -,-,-,-
    // timings: 12
    void LDH_mem_reg8(u16 addr, u8* r) {
        write_mem(addr, *r);
    }

    // usage: F0
    // flags: -,-,-,-
    // timings: 12
    void LDH_reg8_mem(u8* r, u16 addr) {
        *r = read_mem(addr);
    }

    // usage: 32
    // flags: -,-,-,-
    // timings: 8
    void LD_memHLdec_reg8(u16 addr, u8* r) {
        reg.HL--;
        LD_mem_reg8(addr, r);  // 4 cycles
    }

    // usage: 22
    // flags: -,-,-,-
    // timings: 8
    void LD_memHLinc_reg8(u16 addr, u8* r) {
        LD_mem_reg8(addr, r);  // 4 cycles
        reg.HL++;
    }


    // usage: 36
    // flags: -,-,-,-
    // timings: 12
    void LD_mem_const8(u16 addr, u8 val) {
        write_mem(addr, val);
    }

    // usage: 08
    // flags: -,-,-,-
    // timings: 20
    void LD_mem_reg16(u16 addr, u16* r) {
        write_mem(addr, (u8)(*r));
        write_mem(addr+1, (u8)((*r) >> 8));
    }

    // usage: 02,12,70,71,72,73,74,75,77,E2,EA
    // flags: -,-,-,-
    // timings: 8
    void LD_mem_reg8(u16 addr, u8* r) {
        write_mem(addr, *r);
    }

    // usage: 01,11,21,31
    // flags: -,-,-,-
    // timings: 12
    void LD_reg16_const16(u16* r, u16 val) {
        (*r) = val;
    }

    // usage: F8
    // flags: 0,0,H,C
    // timings: 12
    void LD_reg16_const8(u16* r, u8 val) {
        cycle_count_advance(4);

        i8 rval = (i8)val;

        reg.FZ = false;
        reg.FN = false;
        reg.FH = ADD_4BIT_OVERFLOW(reg.SP, rval);
        reg.FC = ADD_8BIT_OVERFLOW(reg.SP, rval);

        (*r) = reg.SP + rval;
    }

    // usage: F9
    // flags: -,-,-,-
    // timings: 8
    void LD_reg16_reg16(u16* to, u16* from) {
        cycle_count_advance(4);
        (*to) = *from;
    }

    // usage: 06,0E,16,1E,26,2E,3E
    // flags: -,-,-,-
    // timings: 8
    void LD_reg8_const8(u8* r, u8 val) {
        (*r) = val;
    }

    // usage: 0A,1A,46,4E,56,5E,66,6E,7E,F2,FA
    // flags: -,-,-,-
    // timings: 8
    void LD_reg8_mem(u8* r, u16 addr) {
        (*r) = read_mem(addr);
    }

    // usage: 3A
    // flags: -,-,-,-
    // timings: 8
    void LD_reg8_memHLdec(u8* r, u16 addr) {
        reg.HL--;
        LD_reg8_mem(r, addr);
    }

    // usage: 2A
    // flags: -,-,-,-
    // timings: 8
    void LD_reg8_memHLinc(u8* r, u16 addr) {
        LD_reg8_mem(r, addr);
        reg.HL++;
    }


    // usage: 40,41,42,43,44,45,47,48,49,4A,4B,4C,4D,4F,50,51,52,53,54,55,57,58,59,5A,5B,5C,5D,5F,60,61,62,63,64,65,67,68,69,6A,6B,6C,6D,6F,78,79,7A,7B,7C,7D,7F
    // flags: -,-,-,-
    // timings: 4
    void LD_reg8_reg8(u8* to, u8* from) {
        (*to) = *from;
    }

    // usage: 00
    // flags: -,-,-,-
    // timings: 4
    void NOP() {
    }

    // usage: F6
    // flags: Z,0,0,0
    // timings: 8
    void OR_const8(u8 val) {
        _or(val);
    }

    // usage: B6
    // flags: Z,0,0,0
    // timings: 8
    void OR_mem(u16 addr) {
        _or(read_mem(addr));
    }

    // usage: B0,B1,B2,B3,B4,B5,B7
    // flags: Z,0,0,0
    // timings: 4
    void OR_reg8(u8* r) {
        _or(*r);
    }

    // usage: C1,D1,E1,F1
    // flags: -,-,-,-
    // timings: 12
    void POP_reg16(u16* r) {
        *r = read_mem(reg.SP);
        reg.SP++;
        *r |= read_mem(reg.SP) << 8;
        reg.SP++;

        reset_low_F();  // in case we read to AF, as the 4 low bits must always read 0
    }

    // usage: C5,D5,E5,F5
    // flags: -,-,-,-
    // timings: 16
    void PUSH_reg16(u16* r) {
        cycle_count_advance(4);

        reg.SP--;
        write_mem(reg.SP, (u8)((*r) >> 8));
        reg.SP--;
        write_mem(reg.SP, (u8)(*r));
    }

    // usage: 86,8E,96,9E,A6,AE,B6,BE
    // flags: -,-,-,-
    // timings: 16
    void RES_const8_mem(u8 bit, u16 addr) {
        assert(bit < 8);
        write_mem(addr, read_mem(addr) & ~(1 << bit));
    }

    // usage: 80,81,82,83,84,85,87,88,89,8A,8B,8C,8D,8F,90,91,92,93,94,95,97,98,99,9A,9B,9C,9D,9F,A0,A1,A2,A3,A4,A5,A7,A8,A9,AA,AB,AC,AD,AF,B0,B1,B2,B3,B4,B5,B7,B8,B9,BA,BB,BC,BD,BF
    // flags: -,-,-,-
    // timings: 8
    void RES_const8_reg8(u8 bit, u8* r) {
        assert(bit < 8);
        *r &= ~(1 << bit);
    }

    // usage: C9
    // flags: -,-,-,-
    // timings: 16
    void RET() {
        cycle_count_advance(4);
        POP_reg16(&reg.PC);  // 8 cycles
    }

    // usage: D9
    // flags: -,-,-,-
    // timings: 16
    void RETI() {
        RET();  // 12 cycles
        EI();    // 0 cycles
        /* std::cout << "RETI CMD" << std::endl; */
    }

    // usage: C0,C8,D0,D8
    // flags: -,-,-,-
    // timings: 20/8
    void RET_flag(bool flag) {
        cycle_count_advance(4);
        if(flag)
            RET();  // 12 cycles
    }

    // usage: 17
    // flags: 0,0,0,C
    // timings: 4
    void RLA() {
        reg.A = _rotate_left(reg.A, true);
        reg.FZ = false;
    }

    // usage: 07
    // flags: 0,0,0,C
    // timings: 4
    void RLCA() {
        reg.A = _rotate_left(reg.A);
        reg.FZ = false;
    }

    // usage: 06
    // flags: Z,0,0,C
    // timings: 16
    void RLC_mem(u16 addr) {
        write_mem(addr, _rotate_left(read_mem(addr)));
    }

    // usage: 00,01,02,03,04,05,07
    // flags: Z,0,0,C
    // timings: 8
    void RLC_reg8(u8* r) {
        *r = _rotate_left(*r);
    }

    // usage: 16
    // flags: Z,0,0,C
    // timings: 16
    void RL_mem(u16 addr) {
        write_mem(addr, _rotate_left(read_mem(addr), true));
    }

    // usage: 10,11,12,13,14,15,17
    // flags: Z,0,0,C
    // timings: 8
    void RL_reg8(u8* r) {
        *r = _rotate_left(*r, true);
    }

    // usage: 1F
    // flags: 0,0,0,C
    // timings: 4
    void RRA() {
        reg.A = _rotate_right(reg.A, true);
        reg.FZ = false;
    }

    // usage: 0F
    // flags: 0,0,0,C
    // timings: 4
    void RRCA() {
        reg.A = _rotate_right(reg.A);
        reg.FZ = false;
    }

    // usage: 0E
    // flags: Z,0,0,C
    // timings: 16
    void RRC_mem(u16 addr) {
        write_mem(addr, _rotate_right(read_mem(addr)));
    }

    // usage: 08,09,0A,0B,0C,0D,0F
    // flags: Z,0,0,C
    // timings: 8
    void RRC_reg8(u8* r) {
        *r = _rotate_right(*r);
    }

    // usage: 1E
    // flags: Z,0,0,C
    // timings: 16
    void RR_mem(u16 addr) {
        write_mem(addr, _rotate_right(read_mem(addr), true));
    }

    // usage: 18,19,1A,1B,1C,1D,1F
    // flags: Z,0,0,C
    // timings: 8
    void RR_reg8(u8* r) {
        *r = _rotate_right(*r, true);
    }

    // usage: C7,CF,D7,DF,E7,EF,F7,FF
    // flags: -,-,-,-
    // timings: 16
    void RST_const8(u8 addr) {
        CALL_const16((u16)addr);  // 12 cycles
    }

    // usage: DE
    // flags: Z,1,H,C
    // timings: 8
    void SBC_reg8_const8(u8* r, u8 val) {
        _sub(r, val, true);
    }

    // usage: 9E
    // flags: Z,1,H,C
    // timings: 8
    void SBC_reg8_mem(u8* r, u16 addr) {
        _sub(r, read_mem(addr), true);
    }

    // usage: 98,99,9A,9B,9C,9D,9F
    // flags: Z,1,H,C
    // timings: 4
    void SBC_reg8_reg8(u8* to, u8* from) {
        _sub(to, *from, true);
    }

    // usage: 37
    // flags: -,0,0,1
    // timings: 4
    void SCF() {
        reg.FN = false;
        reg.FH = false;
        reg.FC = true;
    }

    // usage: C6,CE,D6,DE,E6,EE,F6,FE
    // flags: -,-,-,-
    // timings: 16
    void SET_const8_mem(u8 bit, u16 addr) {
        assert(bit < 8);
        write_mem(addr, read_mem(addr) | (1 << bit));
    }

    // usage: C0,C1,C2,C3,C4,C5,C7,C8,C9,CA,CC,CD,CF,D0,D1,D2,D3,D4,D5,D7,D8,D9,DA,DB,DC,DD,DF,E0,E1,E2,E3,E4,E5,E7,E8,E9,EA,EB,EC,ED,EF,F0,F1,F2,F3,F4,F5,F7,F8,F9,FA,FB,FC,FD,FF
    // flags: -,-,-,-
    // timings: 8
    void SET_const8_reg8(u8 bit, u8* r) {
        assert(bit < 8);
        *r |= 1 << bit;
    }

    // usage: 26
    // flags: Z,0,0,C
    // timings: 16
    void SLA_mem(u16 addr) {
        write_mem(addr, _shift_left(read_mem(addr)));
    }

    // usage: 20,21,22,23,24,25,27
    // flags: Z,0,0,C
    // timings: 8
    void SLA_reg8(u8* r) {
        *r = _shift_left(*r);
    }

    // usage: 2E
    // flags: Z,0,0,0
    // timings: 16
    void SRA_mem(u16 addr) {
        write_mem(addr, _shift_right(read_mem(addr), true));
    }

    // usage: 28,29,2A,2B,2C,2D,2F
    // flags: Z,0,0,0
    // timings: 8
    void SRA_reg8(u8* r) {
        *r = _shift_right(*r, true);
    }

    // usage: 3E
    // flags: Z,0,0,C
    // timings: 16
    void SRL_mem(u16 addr) {
        write_mem(addr, _shift_right(read_mem(addr)));
    }

    // usage: 38,39,3A,3B,3C,3D,3F
    // flags: Z,0,0,C
    // timings: 8
    void SRL_reg8(u8* r) {
        *r = _shift_right(*r);
    }

    // usage: 10
    // flags: -,-,-,-
    // timings: 4
    void STOP_const8(u8 zero) {
        check(zero == 0);
        std::cout << "STOP CMD" << std::endl;
        /* unreachable(); */
    }

    // usage: D6
    // flags: Z,1,H,C
    // timings: 8
    void SUB_const8(u8 val) {
        _sub(&reg.A, val);
    }

    // usage: 96
    // flags: Z,1,H,C
    // timings: 8
    void SUB_mem(u16 addr) {
        _sub(&reg.A, read_mem(addr));
    }

    // usage: 90,91,92,93,94,95,97
    // flags: Z,1,H,C
    // timings: 4
    void SUB_reg8(u8* r) {
        _sub(&reg.A, *r);
    }

    // usage: 36
    // flags: Z,0,0,0
    // timings: 16
    void SWAP_mem(u16 addr) {
        u8 val = read_mem(addr);
        u8 res = (val << 4) | (val >> 4);
        write_mem(addr, res);

        reg.FZ = res == 0;
        reg.FN = false;
        reg.FH = false;
        reg.FC = false;
    }

    // usage: 30,31,32,33,34,35,37
    // flags: Z,0,0,0
    // timings: 8
    void SWAP_reg8(u8* r) {
        *r = ((*r) << 4) | ((*r) >> 4);

        reg.FZ = (*r) == 0;
        reg.FN = false;
        reg.FH = false;
        reg.FC = false;
    }

    // usage: EE
    // flags: Z,0,0,0
    // timings: 8
    void XOR_const8(u8 val) {
        _xor(val);
    }

    // usage: AE
    // flags: Z,0,0,0
    // timings: 8
    void XOR_mem(u16 addr) {
        _xor(read_mem(addr));
    }

    // usage: A8,A9,AA,AB,AC,AD,AF
    // flags: Z,0,0,0
    // timings: 4
    void XOR_reg8(u8* r) {
        _xor(*r);
    }

#include "autogen/cpu_dispatcher.cpp"
#include "autogen/disas.cpp"
};

