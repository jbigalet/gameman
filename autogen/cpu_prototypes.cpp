// usage: CE
// flags: Z,0,H,C
void ADC_reg8_const8(u8*,u8);

// usage: 8E
// flags: Z,0,H,C
void ADC_reg8_mem(u8*,u16);

// usage: 88,89,8A,8B,8C,8D,8F
// flags: Z,0,H,C
void ADC_reg8_reg8(u8*,u8*);

// usage: E8
// flags: 0,0,H,C
void ADD_reg16_const8(u16*,u8);

// usage: 09,19,29,39
// flags: -,0,H,C
void ADD_reg16_reg16(u16*,u16*);

// usage: C6
// flags: Z,0,H,C
void ADD_reg8_const8(u8*,u8);

// usage: 86
// flags: Z,0,H,C
void ADD_reg8_mem(u8*,u16);

// usage: 80,81,82,83,84,85,87
// flags: Z,0,H,C
void ADD_reg8_reg8(u8*,u8*);

// usage: E6
// flags: Z,0,1,0
void AND_const8(u8);

// usage: A6
// flags: Z,0,1,0
void AND_mem(u16);

// usage: A0,A1,A2,A3,A4,A5,A7
// flags: Z,0,1,0
void AND_reg8(u8*);

// usage: 46,4E,56,5E,66,6E,76,7E
// flags: Z,0,1,-
void BIT_const8_mem(u8,u16);

// usage: 40,41,42,43,44,45,47,48,49,4A,4B,4C,4D,4F,50,51,52,53,54,55,57,58,59,5A,5B,5C,5D,5F,60,61,62,63,64,65,67,68,69,6A,6B,6C,6D,6F,70,71,72,73,74,75,77,78,79,7A,7B,7C,7D,7F
// flags: Z,0,1,-
void BIT_const8_reg8(u8,u8*);

// usage: CD
// flags: -,-,-,-
void CALL_const16(u16);

// usage: C4,CC,D4,DC
// flags: -,-,-,-
void CALL_flag_const16(bool,u16);

// usage: 3F
// flags: -,0,0,C
void CCF();

// usage: 2F
// flags: -,1,1,-
void CPL();

// usage: FE
// flags: Z,1,H,C
void CP_const8(u8);

// usage: BE
// flags: Z,1,H,C
void CP_mem(u16);

// usage: B8,B9,BA,BB,BC,BD,BF
// flags: Z,1,H,C
void CP_reg8(u8*);

// usage: 27
// flags: Z,-,0,C
void DAA();

// usage: 35
// flags: Z,1,H,-
void DEC_mem(u16);

// usage: 0B,1B,2B,3B
// flags: -,-,-,-
void DEC_reg16(u16*);

// usage: 05,0D,15,1D,25,2D,3D
// flags: Z,1,H,-
void DEC_reg8(u8*);

// usage: F3
// flags: -,-,-,-
void DI();

// usage: FB
// flags: -,-,-,-
void EI();

// usage: 76
// flags: -,-,-,-
void HALT();

// usage: 34
// flags: Z,0,H,-
void INC_mem(u16);

// usage: 03,13,23,33
// flags: -,-,-,-
void INC_reg16(u16*);

// usage: 04,0C,14,1C,24,2C,3C
// flags: Z,0,H,-
void INC_reg8(u8*);

// usage: C3
// flags: -,-,-,-
void JP_const16(u16);

// usage: C2,CA,D2,DA
// flags: -,-,-,-
void JP_flag_const16(bool,u16);

// usage: E9
// flags: -,-,-,-
void JP_mem(u16);

// usage: 18
// flags: -,-,-,-
void JR_const8(i8);

// usage: 20,28,30,38
// flags: -,-,-,-
void JR_flag_const8(bool,i8);

// usage: E0
// flags: -,-,-,-
void LDH_mem_reg8(u16,u8*);

// usage: F0
// flags: -,-,-,-
void LDH_reg8_mem(u8*,u16);

// usage: 32
// flags: -,-,-,-
void LD_memHLdec_reg8(u16,u8*);

// usage: 22
// flags: -,-,-,-
void LD_memHLinc_reg8(u16,u8*);

// usage: 36
// flags: -,-,-,-
void LD_mem_const8(u16,u8);

// usage: 08
// flags: -,-,-,-
void LD_mem_reg16(u16,u16*);

// usage: 02,12,70,71,72,73,74,75,77,E2,EA
// flags: -,-,-,-
void LD_mem_reg8(u16,u8*);

// usage: 01,11,21,31
// flags: -,-,-,-
void LD_reg16_const16(u16*,u16);

// usage: F8
// flags: 0,0,H,C
void LD_reg16_const8(u16*,u8);

// usage: F9
// flags: -,-,-,-
void LD_reg16_reg16(u16*,u16*);

// usage: 06,0E,16,1E,26,2E,3E
// flags: -,-,-,-
void LD_reg8_const8(u8*,u8);

// usage: 0A,1A,46,4E,56,5E,66,6E,7E,F2,FA
// flags: -,-,-,-
void LD_reg8_mem(u8*,u16);

// usage: 3A
// flags: -,-,-,-
void LD_reg8_memHLdec(u8*,u16);

// usage: 2A
// flags: -,-,-,-
void LD_reg8_memHLinc(u8*,u16);

// usage: 40,41,42,43,44,45,47,48,49,4A,4B,4C,4D,4F,50,51,52,53,54,55,57,58,59,5A,5B,5C,5D,5F,60,61,62,63,64,65,67,68,69,6A,6B,6C,6D,6F,78,79,7A,7B,7C,7D,7F
// flags: -,-,-,-
void LD_reg8_reg8(u8*,u8*);

// usage: 00
// flags: -,-,-,-
void NOP();

// usage: F6
// flags: Z,0,0,0
void OR_const8(u8);

// usage: B6
// flags: Z,0,0,0
void OR_mem(u16);

// usage: B0,B1,B2,B3,B4,B5,B7
// flags: Z,0,0,0
void OR_reg8(u8*);

// usage: C1,D1,E1,F1
// flags: -,-,-,-
void POP_reg16(u16*);

// usage: C5,D5,E5,F5
// flags: -,-,-,-
void PUSH_reg16(u16*);

// usage: 86,8E,96,9E,A6,AE,B6,BE
// flags: -,-,-,-
void RES_const8_mem(u8,u16);

// usage: 80,81,82,83,84,85,87,88,89,8A,8B,8C,8D,8F,90,91,92,93,94,95,97,98,99,9A,9B,9C,9D,9F,A0,A1,A2,A3,A4,A5,A7,A8,A9,AA,AB,AC,AD,AF,B0,B1,B2,B3,B4,B5,B7,B8,B9,BA,BB,BC,BD,BF
// flags: -,-,-,-
void RES_const8_reg8(u8,u8*);

// usage: C9
// flags: -,-,-,-
void RET();

// usage: D9
// flags: -,-,-,-
void RETI();

// usage: C0,C8,D0,D8
// flags: -,-,-,-
void RET_flag(bool);

// usage: 17
// flags: 0,0,0,C
void RLA();

// usage: 07
// flags: 0,0,0,C
void RLCA();

// usage: 06
// flags: Z,0,0,C
void RLC_mem(u16);

// usage: 00,01,02,03,04,05,07
// flags: Z,0,0,C
void RLC_reg8(u8*);

// usage: 16
// flags: Z,0,0,C
void RL_mem(u16);

// usage: 10,11,12,13,14,15,17
// flags: Z,0,0,C
void RL_reg8(u8*);

// usage: 1F
// flags: 0,0,0,C
void RRA();

// usage: 0F
// flags: 0,0,0,C
void RRCA();

// usage: 0E
// flags: Z,0,0,C
void RRC_mem(u16);

// usage: 08,09,0A,0B,0C,0D,0F
// flags: Z,0,0,C
void RRC_reg8(u8*);

// usage: 1E
// flags: Z,0,0,C
void RR_mem(u16);

// usage: 18,19,1A,1B,1C,1D,1F
// flags: Z,0,0,C
void RR_reg8(u8*);

// usage: C7,CF,D7,DF,E7,EF,F7,FF
// flags: -,-,-,-
void RST_const8(u8);

// usage: DE
// flags: Z,1,H,C
void SBC_reg8_const8(u8*,u8);

// usage: 9E
// flags: Z,1,H,C
void SBC_reg8_mem(u8*,u16);

// usage: 98,99,9A,9B,9C,9D,9F
// flags: Z,1,H,C
void SBC_reg8_reg8(u8*,u8*);

// usage: 37
// flags: -,0,0,1
void SCF();

// usage: C6,CE,D6,DE,E6,EE,F6,FE
// flags: -,-,-,-
void SET_const8_mem(u8,u16);

// usage: C0,C1,C2,C3,C4,C5,C7,C8,C9,CA,CB,CC,CD,CF,D0,D1,D2,D3,D4,D5,D7,D8,D9,DA,DB,DC,DD,DF,E0,E1,E2,E3,E4,E5,E7,E8,E9,EA,EB,EC,ED,EF,F0,F1,F2,F3,F4,F5,F7,F8,F9,FA,FB,FC,FD,FF
// flags: -,-,-,-
void SET_const8_reg8(u8,u8*);

// usage: 26
// flags: Z,0,0,C
void SLA_mem(u16);

// usage: 20,21,22,23,24,25,27
// flags: Z,0,0,C
void SLA_reg8(u8*);

// usage: 2E
// flags: Z,0,0,0
void SRA_mem(u16);

// usage: 28,29,2A,2B,2C,2D,2F
// flags: Z,0,0,0
void SRA_reg8(u8*);

// usage: 3E
// flags: Z,0,0,C
void SRL_mem(u16);

// usage: 38,39,3A,3B,3C,3D,3F
// flags: Z,0,0,C
void SRL_reg8(u8*);

// usage: 10
// flags: -,-,-,-
void STOP_const8(u8);

// usage: D6
// flags: Z,1,H,C
void SUB_const8(u8);

// usage: 96
// flags: Z,1,H,C
void SUB_mem(u16);

// usage: 90,91,92,93,94,95,97
// flags: Z,1,H,C
void SUB_reg8(u8*);

// usage: 36
// flags: Z,0,0,0
void SWAP_mem(u16);

// usage: 30,31,32,33,34,35,37
// flags: Z,0,0,0
void SWAP_reg8(u8*);

// usage: EE
// flags: Z,0,0,0
void XOR_const8(u8);

// usage: AE
// flags: Z,0,0,0
void XOR_mem(u16);

// usage: A8,A9,AA,AB,AC,AD,AF
// flags: Z,0,0,0
void XOR_reg8(u8*);