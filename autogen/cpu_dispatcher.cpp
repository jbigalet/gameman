i32 exec_op_prefix() {
    u8 opcode = read_pc<u8>();
    switch(opcode) {
        case 0x00:
        {
            RLC_reg8(&reg.B);
            return 8;
        }
        case 0x01:
        {
            RLC_reg8(&reg.C);
            return 8;
        }
        case 0x02:
        {
            RLC_reg8(&reg.D);
            return 8;
        }
        case 0x03:
        {
            RLC_reg8(&reg.E);
            return 8;
        }
        case 0x04:
        {
            RLC_reg8(&reg.H);
            return 8;
        }
        case 0x05:
        {
            RLC_reg8(&reg.L);
            return 8;
        }
        case 0x06:
        {
            RLC_mem(reg.HL);
            return 16;
        }
        case 0x07:
        {
            RLC_reg8(&reg.A);
            return 8;
        }
        case 0x08:
        {
            RRC_reg8(&reg.B);
            return 8;
        }
        case 0x09:
        {
            RRC_reg8(&reg.C);
            return 8;
        }
        case 0x0A:
        {
            RRC_reg8(&reg.D);
            return 8;
        }
        case 0x0B:
        {
            RRC_reg8(&reg.E);
            return 8;
        }
        case 0x0C:
        {
            RRC_reg8(&reg.H);
            return 8;
        }
        case 0x0D:
        {
            RRC_reg8(&reg.L);
            return 8;
        }
        case 0x0E:
        {
            RRC_mem(reg.HL);
            return 16;
        }
        case 0x0F:
        {
            RRC_reg8(&reg.A);
            return 8;
        }
        case 0x10:
        {
            RL_reg8(&reg.B);
            return 8;
        }
        case 0x11:
        {
            RL_reg8(&reg.C);
            return 8;
        }
        case 0x12:
        {
            RL_reg8(&reg.D);
            return 8;
        }
        case 0x13:
        {
            RL_reg8(&reg.E);
            return 8;
        }
        case 0x14:
        {
            RL_reg8(&reg.H);
            return 8;
        }
        case 0x15:
        {
            RL_reg8(&reg.L);
            return 8;
        }
        case 0x16:
        {
            RL_mem(reg.HL);
            return 16;
        }
        case 0x17:
        {
            RL_reg8(&reg.A);
            return 8;
        }
        case 0x18:
        {
            RR_reg8(&reg.B);
            return 8;
        }
        case 0x19:
        {
            RR_reg8(&reg.C);
            return 8;
        }
        case 0x1A:
        {
            RR_reg8(&reg.D);
            return 8;
        }
        case 0x1B:
        {
            RR_reg8(&reg.E);
            return 8;
        }
        case 0x1C:
        {
            RR_reg8(&reg.H);
            return 8;
        }
        case 0x1D:
        {
            RR_reg8(&reg.L);
            return 8;
        }
        case 0x1E:
        {
            RR_mem(reg.HL);
            return 16;
        }
        case 0x1F:
        {
            RR_reg8(&reg.A);
            return 8;
        }
        case 0x20:
        {
            SLA_reg8(&reg.B);
            return 8;
        }
        case 0x21:
        {
            SLA_reg8(&reg.C);
            return 8;
        }
        case 0x22:
        {
            SLA_reg8(&reg.D);
            return 8;
        }
        case 0x23:
        {
            SLA_reg8(&reg.E);
            return 8;
        }
        case 0x24:
        {
            SLA_reg8(&reg.H);
            return 8;
        }
        case 0x25:
        {
            SLA_reg8(&reg.L);
            return 8;
        }
        case 0x26:
        {
            SLA_mem(reg.HL);
            return 16;
        }
        case 0x27:
        {
            SLA_reg8(&reg.A);
            return 8;
        }
        case 0x28:
        {
            SRA_reg8(&reg.B);
            return 8;
        }
        case 0x29:
        {
            SRA_reg8(&reg.C);
            return 8;
        }
        case 0x2A:
        {
            SRA_reg8(&reg.D);
            return 8;
        }
        case 0x2B:
        {
            SRA_reg8(&reg.E);
            return 8;
        }
        case 0x2C:
        {
            SRA_reg8(&reg.H);
            return 8;
        }
        case 0x2D:
        {
            SRA_reg8(&reg.L);
            return 8;
        }
        case 0x2E:
        {
            SRA_mem(reg.HL);
            return 16;
        }
        case 0x2F:
        {
            SRA_reg8(&reg.A);
            return 8;
        }
        case 0x30:
        {
            SWAP_reg8(&reg.B);
            return 8;
        }
        case 0x31:
        {
            SWAP_reg8(&reg.C);
            return 8;
        }
        case 0x32:
        {
            SWAP_reg8(&reg.D);
            return 8;
        }
        case 0x33:
        {
            SWAP_reg8(&reg.E);
            return 8;
        }
        case 0x34:
        {
            SWAP_reg8(&reg.H);
            return 8;
        }
        case 0x35:
        {
            SWAP_reg8(&reg.L);
            return 8;
        }
        case 0x36:
        {
            SWAP_mem(reg.HL);
            return 16;
        }
        case 0x37:
        {
            SWAP_reg8(&reg.A);
            return 8;
        }
        case 0x38:
        {
            SRL_reg8(&reg.B);
            return 8;
        }
        case 0x39:
        {
            SRL_reg8(&reg.C);
            return 8;
        }
        case 0x3A:
        {
            SRL_reg8(&reg.D);
            return 8;
        }
        case 0x3B:
        {
            SRL_reg8(&reg.E);
            return 8;
        }
        case 0x3C:
        {
            SRL_reg8(&reg.H);
            return 8;
        }
        case 0x3D:
        {
            SRL_reg8(&reg.L);
            return 8;
        }
        case 0x3E:
        {
            SRL_mem(reg.HL);
            return 16;
        }
        case 0x3F:
        {
            SRL_reg8(&reg.A);
            return 8;
        }
        case 0x40:
        {
            BIT_const8_reg8(0x0, &reg.B);
            return 8;
        }
        case 0x41:
        {
            BIT_const8_reg8(0x0, &reg.C);
            return 8;
        }
        case 0x42:
        {
            BIT_const8_reg8(0x0, &reg.D);
            return 8;
        }
        case 0x43:
        {
            BIT_const8_reg8(0x0, &reg.E);
            return 8;
        }
        case 0x44:
        {
            BIT_const8_reg8(0x0, &reg.H);
            return 8;
        }
        case 0x45:
        {
            BIT_const8_reg8(0x0, &reg.L);
            return 8;
        }
        case 0x46:
        {
            BIT_const8_mem(0x0, reg.HL);
            return 16;
        }
        case 0x47:
        {
            BIT_const8_reg8(0x0, &reg.A);
            return 8;
        }
        case 0x48:
        {
            BIT_const8_reg8(0x1, &reg.B);
            return 8;
        }
        case 0x49:
        {
            BIT_const8_reg8(0x1, &reg.C);
            return 8;
        }
        case 0x4A:
        {
            BIT_const8_reg8(0x1, &reg.D);
            return 8;
        }
        case 0x4B:
        {
            BIT_const8_reg8(0x1, &reg.E);
            return 8;
        }
        case 0x4C:
        {
            BIT_const8_reg8(0x1, &reg.H);
            return 8;
        }
        case 0x4D:
        {
            BIT_const8_reg8(0x1, &reg.L);
            return 8;
        }
        case 0x4E:
        {
            BIT_const8_mem(0x1, reg.HL);
            return 16;
        }
        case 0x4F:
        {
            BIT_const8_reg8(0x1, &reg.A);
            return 8;
        }
        case 0x50:
        {
            BIT_const8_reg8(0x2, &reg.B);
            return 8;
        }
        case 0x51:
        {
            BIT_const8_reg8(0x2, &reg.C);
            return 8;
        }
        case 0x52:
        {
            BIT_const8_reg8(0x2, &reg.D);
            return 8;
        }
        case 0x53:
        {
            BIT_const8_reg8(0x2, &reg.E);
            return 8;
        }
        case 0x54:
        {
            BIT_const8_reg8(0x2, &reg.H);
            return 8;
        }
        case 0x55:
        {
            BIT_const8_reg8(0x2, &reg.L);
            return 8;
        }
        case 0x56:
        {
            BIT_const8_mem(0x2, reg.HL);
            return 16;
        }
        case 0x57:
        {
            BIT_const8_reg8(0x2, &reg.A);
            return 8;
        }
        case 0x58:
        {
            BIT_const8_reg8(0x3, &reg.B);
            return 8;
        }
        case 0x59:
        {
            BIT_const8_reg8(0x3, &reg.C);
            return 8;
        }
        case 0x5A:
        {
            BIT_const8_reg8(0x3, &reg.D);
            return 8;
        }
        case 0x5B:
        {
            BIT_const8_reg8(0x3, &reg.E);
            return 8;
        }
        case 0x5C:
        {
            BIT_const8_reg8(0x3, &reg.H);
            return 8;
        }
        case 0x5D:
        {
            BIT_const8_reg8(0x3, &reg.L);
            return 8;
        }
        case 0x5E:
        {
            BIT_const8_mem(0x3, reg.HL);
            return 16;
        }
        case 0x5F:
        {
            BIT_const8_reg8(0x3, &reg.A);
            return 8;
        }
        case 0x60:
        {
            BIT_const8_reg8(0x4, &reg.B);
            return 8;
        }
        case 0x61:
        {
            BIT_const8_reg8(0x4, &reg.C);
            return 8;
        }
        case 0x62:
        {
            BIT_const8_reg8(0x4, &reg.D);
            return 8;
        }
        case 0x63:
        {
            BIT_const8_reg8(0x4, &reg.E);
            return 8;
        }
        case 0x64:
        {
            BIT_const8_reg8(0x4, &reg.H);
            return 8;
        }
        case 0x65:
        {
            BIT_const8_reg8(0x4, &reg.L);
            return 8;
        }
        case 0x66:
        {
            BIT_const8_mem(0x4, reg.HL);
            return 16;
        }
        case 0x67:
        {
            BIT_const8_reg8(0x4, &reg.A);
            return 8;
        }
        case 0x68:
        {
            BIT_const8_reg8(0x5, &reg.B);
            return 8;
        }
        case 0x69:
        {
            BIT_const8_reg8(0x5, &reg.C);
            return 8;
        }
        case 0x6A:
        {
            BIT_const8_reg8(0x5, &reg.D);
            return 8;
        }
        case 0x6B:
        {
            BIT_const8_reg8(0x5, &reg.E);
            return 8;
        }
        case 0x6C:
        {
            BIT_const8_reg8(0x5, &reg.H);
            return 8;
        }
        case 0x6D:
        {
            BIT_const8_reg8(0x5, &reg.L);
            return 8;
        }
        case 0x6E:
        {
            BIT_const8_mem(0x5, reg.HL);
            return 16;
        }
        case 0x6F:
        {
            BIT_const8_reg8(0x5, &reg.A);
            return 8;
        }
        case 0x70:
        {
            BIT_const8_reg8(0x6, &reg.B);
            return 8;
        }
        case 0x71:
        {
            BIT_const8_reg8(0x6, &reg.C);
            return 8;
        }
        case 0x72:
        {
            BIT_const8_reg8(0x6, &reg.D);
            return 8;
        }
        case 0x73:
        {
            BIT_const8_reg8(0x6, &reg.E);
            return 8;
        }
        case 0x74:
        {
            BIT_const8_reg8(0x6, &reg.H);
            return 8;
        }
        case 0x75:
        {
            BIT_const8_reg8(0x6, &reg.L);
            return 8;
        }
        case 0x76:
        {
            BIT_const8_mem(0x6, reg.HL);
            return 16;
        }
        case 0x77:
        {
            BIT_const8_reg8(0x6, &reg.A);
            return 8;
        }
        case 0x78:
        {
            BIT_const8_reg8(0x7, &reg.B);
            return 8;
        }
        case 0x79:
        {
            BIT_const8_reg8(0x7, &reg.C);
            return 8;
        }
        case 0x7A:
        {
            BIT_const8_reg8(0x7, &reg.D);
            return 8;
        }
        case 0x7B:
        {
            BIT_const8_reg8(0x7, &reg.E);
            return 8;
        }
        case 0x7C:
        {
            BIT_const8_reg8(0x7, &reg.H);
            return 8;
        }
        case 0x7D:
        {
            BIT_const8_reg8(0x7, &reg.L);
            return 8;
        }
        case 0x7E:
        {
            BIT_const8_mem(0x7, reg.HL);
            return 16;
        }
        case 0x7F:
        {
            BIT_const8_reg8(0x7, &reg.A);
            return 8;
        }
        case 0x80:
        {
            RES_const8_reg8(0x0, &reg.B);
            return 8;
        }
        case 0x81:
        {
            RES_const8_reg8(0x0, &reg.C);
            return 8;
        }
        case 0x82:
        {
            RES_const8_reg8(0x0, &reg.D);
            return 8;
        }
        case 0x83:
        {
            RES_const8_reg8(0x0, &reg.E);
            return 8;
        }
        case 0x84:
        {
            RES_const8_reg8(0x0, &reg.H);
            return 8;
        }
        case 0x85:
        {
            RES_const8_reg8(0x0, &reg.L);
            return 8;
        }
        case 0x86:
        {
            RES_const8_mem(0x0, reg.HL);
            return 16;
        }
        case 0x87:
        {
            RES_const8_reg8(0x0, &reg.A);
            return 8;
        }
        case 0x88:
        {
            RES_const8_reg8(0x1, &reg.B);
            return 8;
        }
        case 0x89:
        {
            RES_const8_reg8(0x1, &reg.C);
            return 8;
        }
        case 0x8A:
        {
            RES_const8_reg8(0x1, &reg.D);
            return 8;
        }
        case 0x8B:
        {
            RES_const8_reg8(0x1, &reg.E);
            return 8;
        }
        case 0x8C:
        {
            RES_const8_reg8(0x1, &reg.H);
            return 8;
        }
        case 0x8D:
        {
            RES_const8_reg8(0x1, &reg.L);
            return 8;
        }
        case 0x8E:
        {
            RES_const8_mem(0x1, reg.HL);
            return 16;
        }
        case 0x8F:
        {
            RES_const8_reg8(0x1, &reg.A);
            return 8;
        }
        case 0x90:
        {
            RES_const8_reg8(0x2, &reg.B);
            return 8;
        }
        case 0x91:
        {
            RES_const8_reg8(0x2, &reg.C);
            return 8;
        }
        case 0x92:
        {
            RES_const8_reg8(0x2, &reg.D);
            return 8;
        }
        case 0x93:
        {
            RES_const8_reg8(0x2, &reg.E);
            return 8;
        }
        case 0x94:
        {
            RES_const8_reg8(0x2, &reg.H);
            return 8;
        }
        case 0x95:
        {
            RES_const8_reg8(0x2, &reg.L);
            return 8;
        }
        case 0x96:
        {
            RES_const8_mem(0x2, reg.HL);
            return 16;
        }
        case 0x97:
        {
            RES_const8_reg8(0x2, &reg.A);
            return 8;
        }
        case 0x98:
        {
            RES_const8_reg8(0x3, &reg.B);
            return 8;
        }
        case 0x99:
        {
            RES_const8_reg8(0x3, &reg.C);
            return 8;
        }
        case 0x9A:
        {
            RES_const8_reg8(0x3, &reg.D);
            return 8;
        }
        case 0x9B:
        {
            RES_const8_reg8(0x3, &reg.E);
            return 8;
        }
        case 0x9C:
        {
            RES_const8_reg8(0x3, &reg.H);
            return 8;
        }
        case 0x9D:
        {
            RES_const8_reg8(0x3, &reg.L);
            return 8;
        }
        case 0x9E:
        {
            RES_const8_mem(0x3, reg.HL);
            return 16;
        }
        case 0x9F:
        {
            RES_const8_reg8(0x3, &reg.A);
            return 8;
        }
        case 0xA0:
        {
            RES_const8_reg8(0x4, &reg.B);
            return 8;
        }
        case 0xA1:
        {
            RES_const8_reg8(0x4, &reg.C);
            return 8;
        }
        case 0xA2:
        {
            RES_const8_reg8(0x4, &reg.D);
            return 8;
        }
        case 0xA3:
        {
            RES_const8_reg8(0x4, &reg.E);
            return 8;
        }
        case 0xA4:
        {
            RES_const8_reg8(0x4, &reg.H);
            return 8;
        }
        case 0xA5:
        {
            RES_const8_reg8(0x4, &reg.L);
            return 8;
        }
        case 0xA6:
        {
            RES_const8_mem(0x4, reg.HL);
            return 16;
        }
        case 0xA7:
        {
            RES_const8_reg8(0x4, &reg.A);
            return 8;
        }
        case 0xA8:
        {
            RES_const8_reg8(0x5, &reg.B);
            return 8;
        }
        case 0xA9:
        {
            RES_const8_reg8(0x5, &reg.C);
            return 8;
        }
        case 0xAA:
        {
            RES_const8_reg8(0x5, &reg.D);
            return 8;
        }
        case 0xAB:
        {
            RES_const8_reg8(0x5, &reg.E);
            return 8;
        }
        case 0xAC:
        {
            RES_const8_reg8(0x5, &reg.H);
            return 8;
        }
        case 0xAD:
        {
            RES_const8_reg8(0x5, &reg.L);
            return 8;
        }
        case 0xAE:
        {
            RES_const8_mem(0x5, reg.HL);
            return 16;
        }
        case 0xAF:
        {
            RES_const8_reg8(0x5, &reg.A);
            return 8;
        }
        case 0xB0:
        {
            RES_const8_reg8(0x6, &reg.B);
            return 8;
        }
        case 0xB1:
        {
            RES_const8_reg8(0x6, &reg.C);
            return 8;
        }
        case 0xB2:
        {
            RES_const8_reg8(0x6, &reg.D);
            return 8;
        }
        case 0xB3:
        {
            RES_const8_reg8(0x6, &reg.E);
            return 8;
        }
        case 0xB4:
        {
            RES_const8_reg8(0x6, &reg.H);
            return 8;
        }
        case 0xB5:
        {
            RES_const8_reg8(0x6, &reg.L);
            return 8;
        }
        case 0xB6:
        {
            RES_const8_mem(0x6, reg.HL);
            return 16;
        }
        case 0xB7:
        {
            RES_const8_reg8(0x6, &reg.A);
            return 8;
        }
        case 0xB8:
        {
            RES_const8_reg8(0x7, &reg.B);
            return 8;
        }
        case 0xB9:
        {
            RES_const8_reg8(0x7, &reg.C);
            return 8;
        }
        case 0xBA:
        {
            RES_const8_reg8(0x7, &reg.D);
            return 8;
        }
        case 0xBB:
        {
            RES_const8_reg8(0x7, &reg.E);
            return 8;
        }
        case 0xBC:
        {
            RES_const8_reg8(0x7, &reg.H);
            return 8;
        }
        case 0xBD:
        {
            RES_const8_reg8(0x7, &reg.L);
            return 8;
        }
        case 0xBE:
        {
            RES_const8_mem(0x7, reg.HL);
            return 16;
        }
        case 0xBF:
        {
            RES_const8_reg8(0x7, &reg.A);
            return 8;
        }
        case 0xC0:
        {
            SET_const8_reg8(0x0, &reg.B);
            return 8;
        }
        case 0xC1:
        {
            SET_const8_reg8(0x0, &reg.C);
            return 8;
        }
        case 0xC2:
        {
            SET_const8_reg8(0x0, &reg.D);
            return 8;
        }
        case 0xC3:
        {
            SET_const8_reg8(0x0, &reg.E);
            return 8;
        }
        case 0xC4:
        {
            SET_const8_reg8(0x0, &reg.H);
            return 8;
        }
        case 0xC5:
        {
            SET_const8_reg8(0x0, &reg.L);
            return 8;
        }
        case 0xC6:
        {
            SET_const8_mem(0x0, reg.HL);
            return 16;
        }
        case 0xC7:
        {
            SET_const8_reg8(0x0, &reg.A);
            return 8;
        }
        case 0xC8:
        {
            SET_const8_reg8(0x1, &reg.B);
            return 8;
        }
        case 0xC9:
        {
            SET_const8_reg8(0x1, &reg.C);
            return 8;
        }
        case 0xCA:
        {
            SET_const8_reg8(0x1, &reg.D);
            return 8;
        }
        case 0xCC:
        {
            SET_const8_reg8(0x1, &reg.H);
            return 8;
        }
        case 0xCD:
        {
            SET_const8_reg8(0x1, &reg.L);
            return 8;
        }
        case 0xCE:
        {
            SET_const8_mem(0x1, reg.HL);
            return 16;
        }
        case 0xCF:
        {
            SET_const8_reg8(0x1, &reg.A);
            return 8;
        }
        case 0xD0:
        {
            SET_const8_reg8(0x2, &reg.B);
            return 8;
        }
        case 0xD1:
        {
            SET_const8_reg8(0x2, &reg.C);
            return 8;
        }
        case 0xD2:
        {
            SET_const8_reg8(0x2, &reg.D);
            return 8;
        }
        case 0xD3:
        {
            SET_const8_reg8(0x2, &reg.E);
            return 8;
        }
        case 0xD4:
        {
            SET_const8_reg8(0x2, &reg.H);
            return 8;
        }
        case 0xD5:
        {
            SET_const8_reg8(0x2, &reg.L);
            return 8;
        }
        case 0xD6:
        {
            SET_const8_mem(0x2, reg.HL);
            return 16;
        }
        case 0xD7:
        {
            SET_const8_reg8(0x2, &reg.A);
            return 8;
        }
        case 0xD8:
        {
            SET_const8_reg8(0x3, &reg.B);
            return 8;
        }
        case 0xD9:
        {
            SET_const8_reg8(0x3, &reg.C);
            return 8;
        }
        case 0xDA:
        {
            SET_const8_reg8(0x3, &reg.D);
            return 8;
        }
        case 0xDB:
        {
            SET_const8_reg8(0x3, &reg.E);
            return 8;
        }
        case 0xDC:
        {
            SET_const8_reg8(0x3, &reg.H);
            return 8;
        }
        case 0xDD:
        {
            SET_const8_reg8(0x3, &reg.L);
            return 8;
        }
        case 0xDE:
        {
            SET_const8_mem(0x3, reg.HL);
            return 16;
        }
        case 0xDF:
        {
            SET_const8_reg8(0x3, &reg.A);
            return 8;
        }
        case 0xE0:
        {
            SET_const8_reg8(0x4, &reg.B);
            return 8;
        }
        case 0xE1:
        {
            SET_const8_reg8(0x4, &reg.C);
            return 8;
        }
        case 0xE2:
        {
            SET_const8_reg8(0x4, &reg.D);
            return 8;
        }
        case 0xE3:
        {
            SET_const8_reg8(0x4, &reg.E);
            return 8;
        }
        case 0xE4:
        {
            SET_const8_reg8(0x4, &reg.H);
            return 8;
        }
        case 0xE5:
        {
            SET_const8_reg8(0x4, &reg.L);
            return 8;
        }
        case 0xE6:
        {
            SET_const8_mem(0x4, reg.HL);
            return 16;
        }
        case 0xE7:
        {
            SET_const8_reg8(0x4, &reg.A);
            return 8;
        }
        case 0xE8:
        {
            SET_const8_reg8(0x5, &reg.B);
            return 8;
        }
        case 0xE9:
        {
            SET_const8_reg8(0x5, &reg.C);
            return 8;
        }
        case 0xEA:
        {
            SET_const8_reg8(0x5, &reg.D);
            return 8;
        }
        case 0xEB:
        {
            SET_const8_reg8(0x5, &reg.E);
            return 8;
        }
        case 0xEC:
        {
            SET_const8_reg8(0x5, &reg.H);
            return 8;
        }
        case 0xED:
        {
            SET_const8_reg8(0x5, &reg.L);
            return 8;
        }
        case 0xEE:
        {
            SET_const8_mem(0x5, reg.HL);
            return 16;
        }
        case 0xEF:
        {
            SET_const8_reg8(0x5, &reg.A);
            return 8;
        }
        case 0xF0:
        {
            SET_const8_reg8(0x6, &reg.B);
            return 8;
        }
        case 0xF1:
        {
            SET_const8_reg8(0x6, &reg.C);
            return 8;
        }
        case 0xF2:
        {
            SET_const8_reg8(0x6, &reg.D);
            return 8;
        }
        case 0xF3:
        {
            SET_const8_reg8(0x6, &reg.E);
            return 8;
        }
        case 0xF4:
        {
            SET_const8_reg8(0x6, &reg.H);
            return 8;
        }
        case 0xF5:
        {
            SET_const8_reg8(0x6, &reg.L);
            return 8;
        }
        case 0xF6:
        {
            SET_const8_mem(0x6, reg.HL);
            return 16;
        }
        case 0xF7:
        {
            SET_const8_reg8(0x6, &reg.A);
            return 8;
        }
        case 0xF8:
        {
            SET_const8_reg8(0x7, &reg.B);
            return 8;
        }
        case 0xF9:
        {
            SET_const8_reg8(0x7, &reg.C);
            return 8;
        }
        case 0xFA:
        {
            SET_const8_reg8(0x7, &reg.D);
            return 8;
        }
        case 0xFB:
        {
            SET_const8_reg8(0x7, &reg.E);
            return 8;
        }
        case 0xFC:
        {
            SET_const8_reg8(0x7, &reg.H);
            return 8;
        }
        case 0xFD:
        {
            SET_const8_reg8(0x7, &reg.L);
            return 8;
        }
        case 0xFE:
        {
            SET_const8_mem(0x7, reg.HL);
            return 16;
        }
        case 0xFF:
        {
            SET_const8_reg8(0x7, &reg.A);
            return 8;
        }

        case 0xCB:
            return exec_op_prefix();
    }

    std::cout << "Unkown upcode " + to_hex_string(opcode) << std::endl;
    unreachable();
    return 0;
}


i32 exec_op() {
    u8 opcode = read_pc<u8>();
    switch(opcode) {
        case 0x00:
        {
            NOP();
            return 4;
        }
        case 0x01:
        {
            LD_reg16_const16(&reg.BC, read_pc<u16>());
            return 12;
        }
        case 0x02:
        {
            LD_mem_reg8(reg.BC, &reg.A);
            return 8;
        }
        case 0x03:
        {
            INC_reg16(&reg.BC);
            return 8;
        }
        case 0x04:
        {
            INC_reg8(&reg.B);
            return 4;
        }
        case 0x05:
        {
            DEC_reg8(&reg.B);
            return 4;
        }
        case 0x06:
        {
            LD_reg8_const8(&reg.B, read_pc<u8>());
            return 8;
        }
        case 0x07:
        {
            RLCA();
            return 4;
        }
        case 0x08:
        {
            LD_mem_reg16(read_pc<u16>(), &reg.SP);
            return 20;
        }
        case 0x09:
        {
            ADD_reg16_reg16(&reg.HL, &reg.BC);
            return 8;
        }
        case 0x0A:
        {
            LD_reg8_mem(&reg.A, reg.BC);
            return 8;
        }
        case 0x0B:
        {
            DEC_reg16(&reg.BC);
            return 8;
        }
        case 0x0C:
        {
            INC_reg8(&reg.C);
            return 4;
        }
        case 0x0D:
        {
            DEC_reg8(&reg.C);
            return 4;
        }
        case 0x0E:
        {
            LD_reg8_const8(&reg.C, read_pc<u8>());
            return 8;
        }
        case 0x0F:
        {
            RRCA();
            return 4;
        }
        case 0x10:
        {
            STOP_const8(0x0);
            return 4;
        }
        case 0x11:
        {
            LD_reg16_const16(&reg.DE, read_pc<u16>());
            return 12;
        }
        case 0x12:
        {
            LD_mem_reg8(reg.DE, &reg.A);
            return 8;
        }
        case 0x13:
        {
            INC_reg16(&reg.DE);
            return 8;
        }
        case 0x14:
        {
            INC_reg8(&reg.D);
            return 4;
        }
        case 0x15:
        {
            DEC_reg8(&reg.D);
            return 4;
        }
        case 0x16:
        {
            LD_reg8_const8(&reg.D, read_pc<u8>());
            return 8;
        }
        case 0x17:
        {
            RLA();
            return 4;
        }
        case 0x18:
        {
            JR_const8(read_pc<i8>());
            return 12;
        }
        case 0x19:
        {
            ADD_reg16_reg16(&reg.HL, &reg.DE);
            return 8;
        }
        case 0x1A:
        {
            LD_reg8_mem(&reg.A, reg.DE);
            return 8;
        }
        case 0x1B:
        {
            DEC_reg16(&reg.DE);
            return 8;
        }
        case 0x1C:
        {
            INC_reg8(&reg.E);
            return 4;
        }
        case 0x1D:
        {
            DEC_reg8(&reg.E);
            return 4;
        }
        case 0x1E:
        {
            LD_reg8_const8(&reg.E, read_pc<u8>());
            return 8;
        }
        case 0x1F:
        {
            RRA();
            return 4;
        }
        case 0x20:
        {
            bool action_taken = JR_flag_const8(!reg.FZ, read_pc<i8>());
            return action_taken ? 12 : 8;
        }
        case 0x21:
        {
            LD_reg16_const16(&reg.HL, read_pc<u16>());
            return 12;
        }
        case 0x22:
        {
            LD_memHLinc_reg8(reg.HL, &reg.A);
            return 8;
        }
        case 0x23:
        {
            INC_reg16(&reg.HL);
            return 8;
        }
        case 0x24:
        {
            INC_reg8(&reg.H);
            return 4;
        }
        case 0x25:
        {
            DEC_reg8(&reg.H);
            return 4;
        }
        case 0x26:
        {
            LD_reg8_const8(&reg.H, read_pc<u8>());
            return 8;
        }
        case 0x27:
        {
            DAA();
            return 4;
        }
        case 0x28:
        {
            bool action_taken = JR_flag_const8(reg.FZ, read_pc<i8>());
            return action_taken ? 12 : 8;
        }
        case 0x29:
        {
            ADD_reg16_reg16(&reg.HL, &reg.HL);
            return 8;
        }
        case 0x2A:
        {
            LD_reg8_memHLinc(&reg.A, reg.HL);
            return 8;
        }
        case 0x2B:
        {
            DEC_reg16(&reg.HL);
            return 8;
        }
        case 0x2C:
        {
            INC_reg8(&reg.L);
            return 4;
        }
        case 0x2D:
        {
            DEC_reg8(&reg.L);
            return 4;
        }
        case 0x2E:
        {
            LD_reg8_const8(&reg.L, read_pc<u8>());
            return 8;
        }
        case 0x2F:
        {
            CPL();
            return 4;
        }
        case 0x30:
        {
            bool action_taken = JR_flag_const8(!reg.FC, read_pc<i8>());
            return action_taken ? 12 : 8;
        }
        case 0x31:
        {
            LD_reg16_const16(&reg.SP, read_pc<u16>());
            return 12;
        }
        case 0x32:
        {
            LD_memHLdec_reg8(reg.HL, &reg.A);
            return 8;
        }
        case 0x33:
        {
            INC_reg16(&reg.SP);
            return 8;
        }
        case 0x34:
        {
            INC_mem(reg.HL);
            return 12;
        }
        case 0x35:
        {
            DEC_mem(reg.HL);
            return 12;
        }
        case 0x36:
        {
            LD_mem_const8(reg.HL, read_pc<u8>());
            return 12;
        }
        case 0x37:
        {
            SCF();
            return 4;
        }
        case 0x38:
        {
            bool action_taken = JR_flag_const8(reg.FC, read_pc<i8>());
            return action_taken ? 12 : 8;
        }
        case 0x39:
        {
            ADD_reg16_reg16(&reg.HL, &reg.SP);
            return 8;
        }
        case 0x3A:
        {
            LD_reg8_memHLdec(&reg.A, reg.HL);
            return 8;
        }
        case 0x3B:
        {
            DEC_reg16(&reg.SP);
            return 8;
        }
        case 0x3C:
        {
            INC_reg8(&reg.A);
            return 4;
        }
        case 0x3D:
        {
            DEC_reg8(&reg.A);
            return 4;
        }
        case 0x3E:
        {
            LD_reg8_const8(&reg.A, read_pc<u8>());
            return 8;
        }
        case 0x3F:
        {
            CCF();
            return 4;
        }
        case 0x40:
        {
            LD_reg8_reg8(&reg.B, &reg.B);
            return 4;
        }
        case 0x41:
        {
            LD_reg8_reg8(&reg.B, &reg.C);
            return 4;
        }
        case 0x42:
        {
            LD_reg8_reg8(&reg.B, &reg.D);
            return 4;
        }
        case 0x43:
        {
            LD_reg8_reg8(&reg.B, &reg.E);
            return 4;
        }
        case 0x44:
        {
            LD_reg8_reg8(&reg.B, &reg.H);
            return 4;
        }
        case 0x45:
        {
            LD_reg8_reg8(&reg.B, &reg.L);
            return 4;
        }
        case 0x46:
        {
            LD_reg8_mem(&reg.B, reg.HL);
            return 8;
        }
        case 0x47:
        {
            LD_reg8_reg8(&reg.B, &reg.A);
            return 4;
        }
        case 0x48:
        {
            LD_reg8_reg8(&reg.C, &reg.B);
            return 4;
        }
        case 0x49:
        {
            LD_reg8_reg8(&reg.C, &reg.C);
            return 4;
        }
        case 0x4A:
        {
            LD_reg8_reg8(&reg.C, &reg.D);
            return 4;
        }
        case 0x4B:
        {
            LD_reg8_reg8(&reg.C, &reg.E);
            return 4;
        }
        case 0x4C:
        {
            LD_reg8_reg8(&reg.C, &reg.H);
            return 4;
        }
        case 0x4D:
        {
            LD_reg8_reg8(&reg.C, &reg.L);
            return 4;
        }
        case 0x4E:
        {
            LD_reg8_mem(&reg.C, reg.HL);
            return 8;
        }
        case 0x4F:
        {
            LD_reg8_reg8(&reg.C, &reg.A);
            return 4;
        }
        case 0x50:
        {
            LD_reg8_reg8(&reg.D, &reg.B);
            return 4;
        }
        case 0x51:
        {
            LD_reg8_reg8(&reg.D, &reg.C);
            return 4;
        }
        case 0x52:
        {
            LD_reg8_reg8(&reg.D, &reg.D);
            return 4;
        }
        case 0x53:
        {
            LD_reg8_reg8(&reg.D, &reg.E);
            return 4;
        }
        case 0x54:
        {
            LD_reg8_reg8(&reg.D, &reg.H);
            return 4;
        }
        case 0x55:
        {
            LD_reg8_reg8(&reg.D, &reg.L);
            return 4;
        }
        case 0x56:
        {
            LD_reg8_mem(&reg.D, reg.HL);
            return 8;
        }
        case 0x57:
        {
            LD_reg8_reg8(&reg.D, &reg.A);
            return 4;
        }
        case 0x58:
        {
            LD_reg8_reg8(&reg.E, &reg.B);
            return 4;
        }
        case 0x59:
        {
            LD_reg8_reg8(&reg.E, &reg.C);
            return 4;
        }
        case 0x5A:
        {
            LD_reg8_reg8(&reg.E, &reg.D);
            return 4;
        }
        case 0x5B:
        {
            LD_reg8_reg8(&reg.E, &reg.E);
            return 4;
        }
        case 0x5C:
        {
            LD_reg8_reg8(&reg.E, &reg.H);
            return 4;
        }
        case 0x5D:
        {
            LD_reg8_reg8(&reg.E, &reg.L);
            return 4;
        }
        case 0x5E:
        {
            LD_reg8_mem(&reg.E, reg.HL);
            return 8;
        }
        case 0x5F:
        {
            LD_reg8_reg8(&reg.E, &reg.A);
            return 4;
        }
        case 0x60:
        {
            LD_reg8_reg8(&reg.H, &reg.B);
            return 4;
        }
        case 0x61:
        {
            LD_reg8_reg8(&reg.H, &reg.C);
            return 4;
        }
        case 0x62:
        {
            LD_reg8_reg8(&reg.H, &reg.D);
            return 4;
        }
        case 0x63:
        {
            LD_reg8_reg8(&reg.H, &reg.E);
            return 4;
        }
        case 0x64:
        {
            LD_reg8_reg8(&reg.H, &reg.H);
            return 4;
        }
        case 0x65:
        {
            LD_reg8_reg8(&reg.H, &reg.L);
            return 4;
        }
        case 0x66:
        {
            LD_reg8_mem(&reg.H, reg.HL);
            return 8;
        }
        case 0x67:
        {
            LD_reg8_reg8(&reg.H, &reg.A);
            return 4;
        }
        case 0x68:
        {
            LD_reg8_reg8(&reg.L, &reg.B);
            return 4;
        }
        case 0x69:
        {
            LD_reg8_reg8(&reg.L, &reg.C);
            return 4;
        }
        case 0x6A:
        {
            LD_reg8_reg8(&reg.L, &reg.D);
            return 4;
        }
        case 0x6B:
        {
            LD_reg8_reg8(&reg.L, &reg.E);
            return 4;
        }
        case 0x6C:
        {
            LD_reg8_reg8(&reg.L, &reg.H);
            return 4;
        }
        case 0x6D:
        {
            LD_reg8_reg8(&reg.L, &reg.L);
            return 4;
        }
        case 0x6E:
        {
            LD_reg8_mem(&reg.L, reg.HL);
            return 8;
        }
        case 0x6F:
        {
            LD_reg8_reg8(&reg.L, &reg.A);
            return 4;
        }
        case 0x70:
        {
            LD_mem_reg8(reg.HL, &reg.B);
            return 8;
        }
        case 0x71:
        {
            LD_mem_reg8(reg.HL, &reg.C);
            return 8;
        }
        case 0x72:
        {
            LD_mem_reg8(reg.HL, &reg.D);
            return 8;
        }
        case 0x73:
        {
            LD_mem_reg8(reg.HL, &reg.E);
            return 8;
        }
        case 0x74:
        {
            LD_mem_reg8(reg.HL, &reg.H);
            return 8;
        }
        case 0x75:
        {
            LD_mem_reg8(reg.HL, &reg.L);
            return 8;
        }
        case 0x76:
        {
            HALT();
            return 4;
        }
        case 0x77:
        {
            LD_mem_reg8(reg.HL, &reg.A);
            return 8;
        }
        case 0x78:
        {
            LD_reg8_reg8(&reg.A, &reg.B);
            return 4;
        }
        case 0x79:
        {
            LD_reg8_reg8(&reg.A, &reg.C);
            return 4;
        }
        case 0x7A:
        {
            LD_reg8_reg8(&reg.A, &reg.D);
            return 4;
        }
        case 0x7B:
        {
            LD_reg8_reg8(&reg.A, &reg.E);
            return 4;
        }
        case 0x7C:
        {
            LD_reg8_reg8(&reg.A, &reg.H);
            return 4;
        }
        case 0x7D:
        {
            LD_reg8_reg8(&reg.A, &reg.L);
            return 4;
        }
        case 0x7E:
        {
            LD_reg8_mem(&reg.A, reg.HL);
            return 8;
        }
        case 0x7F:
        {
            LD_reg8_reg8(&reg.A, &reg.A);
            return 4;
        }
        case 0x80:
        {
            ADD_reg8_reg8(&reg.A, &reg.B);
            return 4;
        }
        case 0x81:
        {
            ADD_reg8_reg8(&reg.A, &reg.C);
            return 4;
        }
        case 0x82:
        {
            ADD_reg8_reg8(&reg.A, &reg.D);
            return 4;
        }
        case 0x83:
        {
            ADD_reg8_reg8(&reg.A, &reg.E);
            return 4;
        }
        case 0x84:
        {
            ADD_reg8_reg8(&reg.A, &reg.H);
            return 4;
        }
        case 0x85:
        {
            ADD_reg8_reg8(&reg.A, &reg.L);
            return 4;
        }
        case 0x86:
        {
            ADD_reg8_mem(&reg.A, reg.HL);
            return 8;
        }
        case 0x87:
        {
            ADD_reg8_reg8(&reg.A, &reg.A);
            return 4;
        }
        case 0x88:
        {
            ADC_reg8_reg8(&reg.A, &reg.B);
            return 4;
        }
        case 0x89:
        {
            ADC_reg8_reg8(&reg.A, &reg.C);
            return 4;
        }
        case 0x8A:
        {
            ADC_reg8_reg8(&reg.A, &reg.D);
            return 4;
        }
        case 0x8B:
        {
            ADC_reg8_reg8(&reg.A, &reg.E);
            return 4;
        }
        case 0x8C:
        {
            ADC_reg8_reg8(&reg.A, &reg.H);
            return 4;
        }
        case 0x8D:
        {
            ADC_reg8_reg8(&reg.A, &reg.L);
            return 4;
        }
        case 0x8E:
        {
            ADC_reg8_mem(&reg.A, reg.HL);
            return 8;
        }
        case 0x8F:
        {
            ADC_reg8_reg8(&reg.A, &reg.A);
            return 4;
        }
        case 0x90:
        {
            SUB_reg8(&reg.B);
            return 4;
        }
        case 0x91:
        {
            SUB_reg8(&reg.C);
            return 4;
        }
        case 0x92:
        {
            SUB_reg8(&reg.D);
            return 4;
        }
        case 0x93:
        {
            SUB_reg8(&reg.E);
            return 4;
        }
        case 0x94:
        {
            SUB_reg8(&reg.H);
            return 4;
        }
        case 0x95:
        {
            SUB_reg8(&reg.L);
            return 4;
        }
        case 0x96:
        {
            SUB_mem(reg.HL);
            return 8;
        }
        case 0x97:
        {
            SUB_reg8(&reg.A);
            return 4;
        }
        case 0x98:
        {
            SBC_reg8_reg8(&reg.A, &reg.B);
            return 4;
        }
        case 0x99:
        {
            SBC_reg8_reg8(&reg.A, &reg.C);
            return 4;
        }
        case 0x9A:
        {
            SBC_reg8_reg8(&reg.A, &reg.D);
            return 4;
        }
        case 0x9B:
        {
            SBC_reg8_reg8(&reg.A, &reg.E);
            return 4;
        }
        case 0x9C:
        {
            SBC_reg8_reg8(&reg.A, &reg.H);
            return 4;
        }
        case 0x9D:
        {
            SBC_reg8_reg8(&reg.A, &reg.L);
            return 4;
        }
        case 0x9E:
        {
            SBC_reg8_mem(&reg.A, reg.HL);
            return 8;
        }
        case 0x9F:
        {
            SBC_reg8_reg8(&reg.A, &reg.A);
            return 4;
        }
        case 0xA0:
        {
            AND_reg8(&reg.B);
            return 4;
        }
        case 0xA1:
        {
            AND_reg8(&reg.C);
            return 4;
        }
        case 0xA2:
        {
            AND_reg8(&reg.D);
            return 4;
        }
        case 0xA3:
        {
            AND_reg8(&reg.E);
            return 4;
        }
        case 0xA4:
        {
            AND_reg8(&reg.H);
            return 4;
        }
        case 0xA5:
        {
            AND_reg8(&reg.L);
            return 4;
        }
        case 0xA6:
        {
            AND_mem(reg.HL);
            return 8;
        }
        case 0xA7:
        {
            AND_reg8(&reg.A);
            return 4;
        }
        case 0xA8:
        {
            XOR_reg8(&reg.B);
            return 4;
        }
        case 0xA9:
        {
            XOR_reg8(&reg.C);
            return 4;
        }
        case 0xAA:
        {
            XOR_reg8(&reg.D);
            return 4;
        }
        case 0xAB:
        {
            XOR_reg8(&reg.E);
            return 4;
        }
        case 0xAC:
        {
            XOR_reg8(&reg.H);
            return 4;
        }
        case 0xAD:
        {
            XOR_reg8(&reg.L);
            return 4;
        }
        case 0xAE:
        {
            XOR_mem(reg.HL);
            return 8;
        }
        case 0xAF:
        {
            XOR_reg8(&reg.A);
            return 4;
        }
        case 0xB0:
        {
            OR_reg8(&reg.B);
            return 4;
        }
        case 0xB1:
        {
            OR_reg8(&reg.C);
            return 4;
        }
        case 0xB2:
        {
            OR_reg8(&reg.D);
            return 4;
        }
        case 0xB3:
        {
            OR_reg8(&reg.E);
            return 4;
        }
        case 0xB4:
        {
            OR_reg8(&reg.H);
            return 4;
        }
        case 0xB5:
        {
            OR_reg8(&reg.L);
            return 4;
        }
        case 0xB6:
        {
            OR_mem(reg.HL);
            return 8;
        }
        case 0xB7:
        {
            OR_reg8(&reg.A);
            return 4;
        }
        case 0xB8:
        {
            CP_reg8(&reg.B);
            return 4;
        }
        case 0xB9:
        {
            CP_reg8(&reg.C);
            return 4;
        }
        case 0xBA:
        {
            CP_reg8(&reg.D);
            return 4;
        }
        case 0xBB:
        {
            CP_reg8(&reg.E);
            return 4;
        }
        case 0xBC:
        {
            CP_reg8(&reg.H);
            return 4;
        }
        case 0xBD:
        {
            CP_reg8(&reg.L);
            return 4;
        }
        case 0xBE:
        {
            CP_mem(reg.HL);
            return 8;
        }
        case 0xBF:
        {
            CP_reg8(&reg.A);
            return 4;
        }
        case 0xC0:
        {
            bool action_taken = RET_flag(!reg.FZ);
            return action_taken ? 20 : 8;
        }
        case 0xC1:
        {
            POP_reg16(&reg.BC);
            return 12;
        }
        case 0xC2:
        {
            bool action_taken = JP_flag_const16(!reg.FZ, read_pc<u16>());
            return action_taken ? 16 : 12;
        }
        case 0xC3:
        {
            JP_const16(read_pc<u16>());
            return 16;
        }
        case 0xC4:
        {
            bool action_taken = CALL_flag_const16(!reg.FZ, read_pc<u16>());
            return action_taken ? 24 : 12;
        }
        case 0xC5:
        {
            PUSH_reg16(&reg.BC);
            return 16;
        }
        case 0xC6:
        {
            ADD_reg8_const8(&reg.A, read_pc<u8>());
            return 8;
        }
        case 0xC7:
        {
            RST_const8(0x00);
            return 16;
        }
        case 0xC8:
        {
            bool action_taken = RET_flag(reg.FZ);
            return action_taken ? 20 : 8;
        }
        case 0xC9:
        {
            RET();
            return 16;
        }
        case 0xCA:
        {
            bool action_taken = JP_flag_const16(reg.FZ, read_pc<u16>());
            return action_taken ? 16 : 12;
        }
        case 0xCC:
        {
            bool action_taken = CALL_flag_const16(reg.FZ, read_pc<u16>());
            return action_taken ? 24 : 12;
        }
        case 0xCD:
        {
            CALL_const16(read_pc<u16>());
            return 24;
        }
        case 0xCE:
        {
            ADC_reg8_const8(&reg.A, read_pc<u8>());
            return 8;
        }
        case 0xCF:
        {
            RST_const8(0x08);
            return 16;
        }
        case 0xD0:
        {
            bool action_taken = RET_flag(!reg.FC);
            return action_taken ? 20 : 8;
        }
        case 0xD1:
        {
            POP_reg16(&reg.DE);
            return 12;
        }
        case 0xD2:
        {
            bool action_taken = JP_flag_const16(!reg.FC, read_pc<u16>());
            return action_taken ? 16 : 12;
        }
        case 0xD4:
        {
            bool action_taken = CALL_flag_const16(!reg.FC, read_pc<u16>());
            return action_taken ? 24 : 12;
        }
        case 0xD5:
        {
            PUSH_reg16(&reg.DE);
            return 16;
        }
        case 0xD6:
        {
            SUB_const8(read_pc<u8>());
            return 8;
        }
        case 0xD7:
        {
            RST_const8(0x10);
            return 16;
        }
        case 0xD8:
        {
            bool action_taken = RET_flag(reg.FC);
            return action_taken ? 20 : 8;
        }
        case 0xD9:
        {
            RETI();
            return 16;
        }
        case 0xDA:
        {
            bool action_taken = JP_flag_const16(reg.FC, read_pc<u16>());
            return action_taken ? 16 : 12;
        }
        case 0xDC:
        {
            bool action_taken = CALL_flag_const16(reg.FC, read_pc<u16>());
            return action_taken ? 24 : 12;
        }
        case 0xDE:
        {
            SBC_reg8_const8(&reg.A, read_pc<u8>());
            return 8;
        }
        case 0xDF:
        {
            RST_const8(0x18);
            return 16;
        }
        case 0xE0:
        {
            LDH_mem_reg8(0xff00+read_pc<u8>(), &reg.A);
            return 12;
        }
        case 0xE1:
        {
            POP_reg16(&reg.HL);
            return 12;
        }
        case 0xE2:
        {
            LD_mem_reg8(0xff00+reg.C, &reg.A);
            return 8;
        }
        case 0xE5:
        {
            PUSH_reg16(&reg.HL);
            return 16;
        }
        case 0xE6:
        {
            AND_const8(read_pc<u8>());
            return 8;
        }
        case 0xE7:
        {
            RST_const8(0x20);
            return 16;
        }
        case 0xE8:
        {
            ADD_reg16_const8(&reg.SP, read_pc<u8>());
            return 16;
        }
        case 0xE9:
        {
            JP_mem(reg.HL);
            return 4;
        }
        case 0xEA:
        {
            LD_mem_reg8(read_pc<u16>(), &reg.A);
            return 16;
        }
        case 0xEE:
        {
            XOR_const8(read_pc<u8>());
            return 8;
        }
        case 0xEF:
        {
            RST_const8(0x28);
            return 16;
        }
        case 0xF0:
        {
            LDH_reg8_mem(&reg.A, 0xff00+read_pc<u8>());
            return 12;
        }
        case 0xF1:
        {
            POP_reg16(&reg.AF);
            return 12;
        }
        case 0xF2:
        {
            LD_reg8_mem(&reg.A, 0xff00+reg.C);
            return 8;
        }
        case 0xF3:
        {
            DI();
            return 4;
        }
        case 0xF5:
        {
            PUSH_reg16(&reg.AF);
            return 16;
        }
        case 0xF6:
        {
            OR_const8(read_pc<u8>());
            return 8;
        }
        case 0xF7:
        {
            RST_const8(0x30);
            return 16;
        }
        case 0xF8:
        {
            LD_reg16_const8(&reg.HL, read_pc<u8>());
            return 12;
        }
        case 0xF9:
        {
            LD_reg16_reg16(&reg.SP, &reg.HL);
            return 8;
        }
        case 0xFA:
        {
            LD_reg8_mem(&reg.A, read_pc<u16>());
            return 16;
        }
        case 0xFB:
        {
            EI();
            return 4;
        }
        case 0xFE:
        {
            CP_const8(read_pc<u8>());
            return 8;
        }
        case 0xFF:
        {
            RST_const8(0x38);
            return 16;
        }

        case 0xCB:
            return exec_op_prefix();
    }

    std::cout << "Unkown upcode " + to_hex_string(opcode) << std::endl;
    unreachable();
    return 0;
}


