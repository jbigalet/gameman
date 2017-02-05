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

struct CPU {
    Registers reg;
    MMU mmu;


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
        u16 res = (u16)reg.A - tosub;
        u16 low = (reg.A & 0x0f) - (tosub & 0x0f);

        reg.FZ = ((u8)res) == 0;
        reg.FN = true;
        reg.FH = low > 0x0f;
        reg.FC = res > 0xff;
    }

#include "cpu_prototypes.cpp"
#include "cpu_dispatcher.cpp"
};



// opcode implementations

#define ADD_4BIT_OVERFLOW(a,b) ((a & 0x0f) + (b & 0x0f) > 0x0f)
#define ADD_8BIT_OVERFLOW(a,b) ((a & 0xff) + (b & 0xff) > 0xff)


// usage: CE
// flags: Z,0,H,C
void CPU::ADC_reg8_const8(u8* r, u8 val) {
    _add(r, val, true);
}

// usage: 8E
// flags: Z,0,H,C
void CPU::ADC_reg8_mem(u8* r, u16 addr) {
    _add(r, mmu.read(addr), true);
}

// usage: 88,89,8A,8B,8C,8D,8F
// flags: Z,0,H,C
void CPU::ADC_reg8_reg8(u8* to, u8* from) {
    _add(to, (*from), true);
}

// usage: E8
// flags: 0,0,H,C
void CPU::ADD_reg16_const8(u16* r, u8 val) {
    i8 rval = (i8)val;

    reg.FZ = false;
    reg.FN = false;
    reg.FH = ADD_4BIT_OVERFLOW((*r), rval);
    reg.FC = ADD_8BIT_OVERFLOW((*r), rval);

    (*r) += rval;
}

// usage: 09,19,29,39
// flags: -,0,H,C
void CPU::ADD_reg16_reg16(u16* to, u16* from) {
    u32 res = (u32)(*to) + (u32)(*from);

    (*to) = (u16)res;

    reg.FN = false;
    reg.FH = ((*to) & 0xfff) + ((*from) & 0xfff) > 0x0fff;
    reg.FC = res > 0xffff;
}

// usage: C6
// flags: Z,0,H,C
void CPU::ADD_reg8_const8(u8* r, u8 val) {
    _add(r, val);
}

// usage: 86
// flags: Z,0,H,C
void CPU::ADD_reg8_mem(u8* r, u16 addr) {
    _add(r, mmu.read(addr));
}

// usage: 80,81,82,83,84,85,87
// flags: Z,0,H,C
void CPU::ADD_reg8_reg8(u8* to, u8* from) {
    _add(to, (*from));
}

// usage: E6
// flags: Z,0,1,0
void CPU::AND_const8(u8 val) {
    _and(val);
}

// usage: A6
// flags: Z,0,1,0
void CPU::AND_mem(u16 addr) {
    _and(mmu.read(addr));
}

// usage: A0,A1,A2,A3,A4,A5,A7
// flags: Z,0,1,0
void CPU::AND_reg8(u8* r) {
    _and(*r);
}

// usage: 46,4E,56,5E,66,6E,76,7E
// flags: Z,0,1,-
void CPU::BIT_const8_mem(u8,u16) {
    // TODO
}

// usage: 40,41,42,43,44,45,47,48,49,4A,4B,4C,4D,4F,50,51,52,53,54,55,57,58,59,5A,5B,5C,5D,5F,60,61,62,63,64,65,67,68,69,6A,6B,6C,6D,6F,70,71,72,73,74,75,77,78,79,7A,7B,7C,7D,7F
// flags: Z,0,1,-
void CPU::BIT_const8_reg8(u8,u8*) {
    // TODO
}

// usage: CD
// flags: -,-,-,-
void CPU::CALL_const16(u16) {
    // TODO
}

// usage: C4,CC,D4,DC
// flags: -,-,-,-
bool CPU::CALL_flag_const16(bool,u16) {
    // TODO
}

// usage: 3F
// flags: -,0,0,C
void CPU::CCF() {
    // TODO
}

// usage: 2F
// flags: -,1,1,-
void CPU::CPL() {
    reg.A ^= 0xff;
    reg.FN = true;
    reg.FH = true;
}

// usage: FE
// flags: Z,1,H,C
void CPU::CP_const8(u8 val) {
    _cp(val);
}

// usage: BE
// flags: Z,1,H,C
void CPU::CP_mem(u16 addr) {
    _cp(mmu.read(addr));
}

// usage: B8,B9,BA,BB,BC,BD,BF
// flags: Z,1,H,C
void CPU::CP_reg8(u8* r) {
    _cp(*r);
}

// usage: 27
// flags: Z,-,0,C
void CPU::DAA() {
    // TODO
}

// usage: 35
// flags: Z,1,H,-
void CPU::DEC_mem(u16 addr) {
    u8 val = mmu.read(addr);
    u8 res = val - 1;
    mmu.write(addr, res);

    reg.FZ = res == 0;
    reg.FN = true;
    // only possible res after getting a carry is for all the low bytes to be set
    reg.FH = (res & 0x0f) == 0x0f;
}

// usage: 0B,1B,2B,3B
// flags: -,-,-,-
void CPU::DEC_reg16(u16* r) {
    (*r)--;
}

// usage: 05,0D,15,1D,25,2D,3D
// flags: Z,1,H,-
void CPU::DEC_reg8(u8* r) {
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
void CPU::DI() {
    // TODO
}

// usage: FB
// flags: -,-,-,-
void CPU::EI() {
    // TODO
}

// usage: 76
// flags: -,-,-,-
void CPU::HALT() {
    // TODO
}

// usage: 34
// flags: Z,0,H,-
void CPU::INC_mem(u16 addr) {
    u8 val = mmu.read(addr);
    u8 res = val + 1;
    mmu.write(addr, res);

    reg.FZ = res == 0;
    reg.FN = false;
    reg.FH = ADD_4BIT_OVERFLOW(val, 1);
}

// usage: 03,13,23,33
// flags: -,-,-,-
void CPU::INC_reg16(u16* r) {
    (*r)++;
}

// usage: 04,0C,14,1C,24,2C,3C
// flags: Z,0,H,-
void CPU::INC_reg8(u8* r) {
    u8 val = *r;
    u8 res = val + 1;
    *r = res;

    reg.FZ = res == 0;
    reg.FN = false;
    reg.FH = ADD_4BIT_OVERFLOW(val, 1);
}

// usage: C3
// flags: -,-,-,-
void CPU::JP_const16(u16) {
    // TODO
}

// usage: C2,CA,D2,DA
// flags: -,-,-,-
bool CPU::JP_flag_const16(bool,u16) {
    // TODO
}

// usage: E9
// flags: -,-,-,-
void CPU::JP_mem(u16) {
    // TODO
}

// usage: 18
// flags: -,-,-,-
void CPU::JR_const8(i8) {
    // TODO
}

// usage: 20,28,30,38
// flags: -,-,-,-
bool CPU::JR_flag_const8(bool,i8) {
    // TODO
}

// usage: E0
// flags: -,-,-,-
void CPU::LDH_mem_reg8(u16,u8*) {
    // TODO
}

// usage: F0
// flags: -,-,-,-
void CPU::LDH_reg8_mem(u8*,u16) {
    // TODO
}

// usage: 36
// flags: -,-,-,-
void CPU::LD_mem_const8(u16 addr, u8 val) {
    mmu.write(addr, val);
}

// usage: 08
// flags: -,-,-,-
void CPU::LD_mem_reg16(u16 addr, u16* r) {
    mmu.write(addr, (u8)(*r));
    mmu.write(addr, (u8)(*r >> 8));
}

// usage: 02,12,22,32,70,71,72,73,74,75,77,E2,EA
// flags: -,-,-,-
void CPU::LD_mem_reg8(u16 addr, u8* r) {
    mmu.write(addr, *r);
}

// usage: 01,11,21,31
// flags: -,-,-,-
void CPU::LD_reg16_const16(u16* r, u16 val) {
    (*r) = val;
}

// usage: F8
// flags: 0,0,H,C
void CPU::LD_reg16_const8(u16* r, u8 val) {
    reg.FZ = false;
    reg.FN = false;
    reg.FH = ADD_4BIT_OVERFLOW(reg.SP, val);
    reg.FC = ADD_8BIT_OVERFLOW(reg.SP, val);

    (*r) = reg.SP + val;
}

// usage: F9
// flags: -,-,-,-
void CPU::LD_reg16_reg16(u16* to, u16* from) {
    (*to) = *from;
}

// usage: 06,0E,16,1E,26,2E,3E
// flags: -,-,-,-
void CPU::LD_reg8_const8(u8* r, u8 val) {
    (*r) = val;
}

// usage: 0A,1A,2A,3A,46,4E,56,5E,66,6E,7E,F2,FA
// flags: -,-,-,-
void CPU::LD_reg8_mem(u8* r, u16 addr) {
    (*r) = mmu.read(addr);
}

// usage: 40,41,42,43,44,45,47,48,49,4A,4B,4C,4D,4F,50,51,52,53,54,55,57,58,59,5A,5B,5C,5D,5F,60,61,62,63,64,65,67,68,69,6A,6B,6C,6D,6F,78,79,7A,7B,7C,7D,7F
// flags: -,-,-,-
void CPU::LD_reg8_reg8(u8* to, u8* from) {
    (*to) = *from;
}

// usage: 00
// flags: -,-,-,-
void CPU::NOP() {
}

// usage: F6
// flags: Z,0,0,0
void CPU::OR_const8(u8 val) {
    _or(val);
}

// usage: B6
// flags: Z,0,0,0
void CPU::OR_mem(u16 addr) {
    _or(mmu.read(addr));
}

// usage: B0,B1,B2,B3,B4,B5,B7
// flags: Z,0,0,0
void CPU::OR_reg8(u8* r) {
    _or(*r);
}

// usage: C1,D1,E1,F1
// flags: -,-,-,-
void CPU::POP_reg16(u16*) {
    // TODO
}

// usage: C5,D5,E5,F5
// flags: -,-,-,-
void CPU::PUSH_reg16(u16*) {
    // TODO
}

// usage: 86,8E,96,9E,A6,AE,B6,BE
// flags: -,-,-,-
void CPU::RES_const8_mem(u8,u16) {
    // TODO
}

// usage: 80,81,82,83,84,85,87,88,89,8A,8B,8C,8D,8F,90,91,92,93,94,95,97,98,99,9A,9B,9C,9D,9F,A0,A1,A2,A3,A4,A5,A7,A8,A9,AA,AB,AC,AD,AF,B0,B1,B2,B3,B4,B5,B7,B8,B9,BA,BB,BC,BD,BF
// flags: -,-,-,-
void CPU::RES_const8_reg8(u8,u8*) {
    // TODO
}

// usage: C9
// flags: -,-,-,-
void CPU::RET() {
    // TODO
}

// usage: D9
// flags: -,-,-,-
void CPU::RETI() {
    // TODO
}

// usage: C0,C8,D0,D8
// flags: -,-,-,-
bool CPU::RET_flag(bool) {
    // TODO
}

// usage: 17
// flags: 0,0,0,C
void CPU::RLA() {
    // TODO
}

// usage: 07
// flags: 0,0,0,C
void CPU::RLCA() {
    // TODO
}

// usage: 06
// flags: Z,0,0,C
void CPU::RLC_mem(u16) {
    // TODO
}

// usage: 00,01,02,03,04,05,07
// flags: Z,0,0,C
void CPU::RLC_reg8(u8*) {
    // TODO
}

// usage: 16
// flags: Z,0,0,C
void CPU::RL_mem(u16) {
    // TODO
}

// usage: 10,11,12,13,14,15,17
// flags: Z,0,0,C
void CPU::RL_reg8(u8*) {
    // TODO
}

// usage: 1F
// flags: 0,0,0,C
void CPU::RRA() {
    // TODO
}

// usage: 0F
// flags: 0,0,0,C
void CPU::RRCA() {
    // TODO
}

// usage: 0E
// flags: Z,0,0,C
void CPU::RRC_mem(u16) {
    // TODO
}

// usage: 08,09,0A,0B,0C,0D,0F
// flags: Z,0,0,C
void CPU::RRC_reg8(u8*) {
    // TODO
}

// usage: 1E
// flags: Z,0,0,C
void CPU::RR_mem(u16) {
    // TODO
}

// usage: 18,19,1A,1B,1C,1D,1F
// flags: Z,0,0,C
void CPU::RR_reg8(u8*) {
    // TODO
}

// usage: C7,CF,D7,DF,E7,EF,F7,FF
// flags: -,-,-,-
void CPU::RST_const8(u8) {
    // TODO
}

// usage: DE
// flags: Z,1,H,C
void CPU::SBC_reg8_const8(u8* r, u8 val) {
    _sub(r, val, true);
}

// usage: 9E
// flags: Z,1,H,C
void CPU::SBC_reg8_mem(u8* r, u16 addr) {
    _sub(r, mmu.read(addr), true);
}

// usage: 98,99,9A,9B,9C,9D,9F
// flags: Z,1,H,C
void CPU::SBC_reg8_reg8(u8* to, u8* from) {
    _sub(to, *from, true);
}

// usage: 37
// flags: -,0,0,1
void CPU::SCF() {
    // TODO
}

// usage: C6,CE,D6,DE,E6,EE,F6,FE
// flags: -,-,-,-
void CPU::SET_const8_mem(u8,u16) {
    // TODO
}

// usage: C0,C1,C2,C3,C4,C5,C7,C8,C9,CA,CC,CD,CF,D0,D1,D2,D3,D4,D5,D7,D8,D9,DA,DB,DC,DD,DF,E0,E1,E2,E3,E4,E5,E7,E8,E9,EA,EB,EC,ED,EF,F0,F1,F2,F3,F4,F5,F7,F8,F9,FA,FB,FC,FD,FF
// flags: -,-,-,-
void CPU::SET_const8_reg8(u8,u8*) {
    // TODO
}

// usage: 26
// flags: Z,0,0,C
void CPU::SLA_mem(u16) {
    // TODO
}

// usage: 20,21,22,23,24,25,27
// flags: Z,0,0,C
void CPU::SLA_reg8(u8*) {
    // TODO
}

// usage: 2E
// flags: Z,0,0,0
void CPU::SRA_mem(u16) {
    // TODO
}

// usage: 28,29,2A,2B,2C,2D,2F
// flags: Z,0,0,0
void CPU::SRA_reg8(u8*) {
    // TODO
}

// usage: 3E
// flags: Z,0,0,C
void CPU::SRL_mem(u16) {
    // TODO
}

// usage: 38,39,3A,3B,3C,3D,3F
// flags: Z,0,0,C
void CPU::SRL_reg8(u8*) {
    // TODO
}

// usage: 10
// flags: -,-,-,-
void CPU::STOP_const8(u8) {
    // TODO
}

// usage: D6
// flags: Z,1,H,C
void CPU::SUB_const8(u8 val) {
    _sub(&reg.A, val);
}

// usage: 96
// flags: Z,1,H,C
void CPU::SUB_mem(u16 addr) {
    _sub(&reg.A, mmu.read(addr));
}

// usage: 90,91,92,93,94,95,97
// flags: Z,1,H,C
void CPU::SUB_reg8(u8* r) {
    _sub(&reg.A, *r);
}

// usage: 36
// flags: Z,0,0,0
void CPU::SWAP_mem(u16) {
    // TODO
}

// usage: 30,31,32,33,34,35,37
// flags: Z,0,0,0
void CPU::SWAP_reg8(u8*) {
    // TODO
}

// usage: EE
// flags: Z,0,0,0
void CPU::XOR_const8(u8 val) {
    _xor(val);
}

// usage: AE
// flags: Z,0,0,0
void CPU::XOR_mem(u16 addr) {
    _xor(mmu.read(addr));
}

// usage: A8,A9,AA,AB,AC,AD,AF
// flags: Z,0,0,0
void CPU::XOR_reg8(u8* r) {
    _xor(*r);
}

