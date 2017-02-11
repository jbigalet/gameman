void exec_op_prefix() {
    u8 opcode = read_pc_u8();
    switch(opcode) {
        case 0x00:
        {
            /* cycle_count_advance(8); */
            RLC_reg8(&reg.B);
            return;
        }
        case 0x01:
        {
            /* cycle_count_advance(8); */
            RLC_reg8(&reg.C);
            return;
        }
        case 0x02:
        {
            /* cycle_count_advance(8); */
            RLC_reg8(&reg.D);
            return;
        }
        case 0x03:
        {
            /* cycle_count_advance(8); */
            RLC_reg8(&reg.E);
            return;
        }
        case 0x04:
        {
            /* cycle_count_advance(8); */
            RLC_reg8(&reg.H);
            return;
        }
        case 0x05:
        {
            /* cycle_count_advance(8); */
            RLC_reg8(&reg.L);
            return;
        }
        case 0x06:
        {
            /* cycle_count_advance(16); */
            RLC_mem(reg.HL);
            return;
        }
        case 0x07:
        {
            /* cycle_count_advance(8); */
            RLC_reg8(&reg.A);
            return;
        }
        case 0x08:
        {
            /* cycle_count_advance(8); */
            RRC_reg8(&reg.B);
            return;
        }
        case 0x09:
        {
            /* cycle_count_advance(8); */
            RRC_reg8(&reg.C);
            return;
        }
        case 0x0A:
        {
            /* cycle_count_advance(8); */
            RRC_reg8(&reg.D);
            return;
        }
        case 0x0B:
        {
            /* cycle_count_advance(8); */
            RRC_reg8(&reg.E);
            return;
        }
        case 0x0C:
        {
            /* cycle_count_advance(8); */
            RRC_reg8(&reg.H);
            return;
        }
        case 0x0D:
        {
            /* cycle_count_advance(8); */
            RRC_reg8(&reg.L);
            return;
        }
        case 0x0E:
        {
            /* cycle_count_advance(16); */
            RRC_mem(reg.HL);
            return;
        }
        case 0x0F:
        {
            /* cycle_count_advance(8); */
            RRC_reg8(&reg.A);
            return;
        }
        case 0x10:
        {
            /* cycle_count_advance(8); */
            RL_reg8(&reg.B);
            return;
        }
        case 0x11:
        {
            /* cycle_count_advance(8); */
            RL_reg8(&reg.C);
            return;
        }
        case 0x12:
        {
            /* cycle_count_advance(8); */
            RL_reg8(&reg.D);
            return;
        }
        case 0x13:
        {
            /* cycle_count_advance(8); */
            RL_reg8(&reg.E);
            return;
        }
        case 0x14:
        {
            /* cycle_count_advance(8); */
            RL_reg8(&reg.H);
            return;
        }
        case 0x15:
        {
            /* cycle_count_advance(8); */
            RL_reg8(&reg.L);
            return;
        }
        case 0x16:
        {
            /* cycle_count_advance(16); */
            RL_mem(reg.HL);
            return;
        }
        case 0x17:
        {
            /* cycle_count_advance(8); */
            RL_reg8(&reg.A);
            return;
        }
        case 0x18:
        {
            /* cycle_count_advance(8); */
            RR_reg8(&reg.B);
            return;
        }
        case 0x19:
        {
            /* cycle_count_advance(8); */
            RR_reg8(&reg.C);
            return;
        }
        case 0x1A:
        {
            /* cycle_count_advance(8); */
            RR_reg8(&reg.D);
            return;
        }
        case 0x1B:
        {
            /* cycle_count_advance(8); */
            RR_reg8(&reg.E);
            return;
        }
        case 0x1C:
        {
            /* cycle_count_advance(8); */
            RR_reg8(&reg.H);
            return;
        }
        case 0x1D:
        {
            /* cycle_count_advance(8); */
            RR_reg8(&reg.L);
            return;
        }
        case 0x1E:
        {
            /* cycle_count_advance(16); */
            RR_mem(reg.HL);
            return;
        }
        case 0x1F:
        {
            /* cycle_count_advance(8); */
            RR_reg8(&reg.A);
            return;
        }
        case 0x20:
        {
            /* cycle_count_advance(8); */
            SLA_reg8(&reg.B);
            return;
        }
        case 0x21:
        {
            /* cycle_count_advance(8); */
            SLA_reg8(&reg.C);
            return;
        }
        case 0x22:
        {
            /* cycle_count_advance(8); */
            SLA_reg8(&reg.D);
            return;
        }
        case 0x23:
        {
            /* cycle_count_advance(8); */
            SLA_reg8(&reg.E);
            return;
        }
        case 0x24:
        {
            /* cycle_count_advance(8); */
            SLA_reg8(&reg.H);
            return;
        }
        case 0x25:
        {
            /* cycle_count_advance(8); */
            SLA_reg8(&reg.L);
            return;
        }
        case 0x26:
        {
            /* cycle_count_advance(16); */
            SLA_mem(reg.HL);
            return;
        }
        case 0x27:
        {
            /* cycle_count_advance(8); */
            SLA_reg8(&reg.A);
            return;
        }
        case 0x28:
        {
            /* cycle_count_advance(8); */
            SRA_reg8(&reg.B);
            return;
        }
        case 0x29:
        {
            /* cycle_count_advance(8); */
            SRA_reg8(&reg.C);
            return;
        }
        case 0x2A:
        {
            /* cycle_count_advance(8); */
            SRA_reg8(&reg.D);
            return;
        }
        case 0x2B:
        {
            /* cycle_count_advance(8); */
            SRA_reg8(&reg.E);
            return;
        }
        case 0x2C:
        {
            /* cycle_count_advance(8); */
            SRA_reg8(&reg.H);
            return;
        }
        case 0x2D:
        {
            /* cycle_count_advance(8); */
            SRA_reg8(&reg.L);
            return;
        }
        case 0x2E:
        {
            /* cycle_count_advance(16); */
            SRA_mem(reg.HL);
            return;
        }
        case 0x2F:
        {
            /* cycle_count_advance(8); */
            SRA_reg8(&reg.A);
            return;
        }
        case 0x30:
        {
            /* cycle_count_advance(8); */
            SWAP_reg8(&reg.B);
            return;
        }
        case 0x31:
        {
            /* cycle_count_advance(8); */
            SWAP_reg8(&reg.C);
            return;
        }
        case 0x32:
        {
            /* cycle_count_advance(8); */
            SWAP_reg8(&reg.D);
            return;
        }
        case 0x33:
        {
            /* cycle_count_advance(8); */
            SWAP_reg8(&reg.E);
            return;
        }
        case 0x34:
        {
            /* cycle_count_advance(8); */
            SWAP_reg8(&reg.H);
            return;
        }
        case 0x35:
        {
            /* cycle_count_advance(8); */
            SWAP_reg8(&reg.L);
            return;
        }
        case 0x36:
        {
            /* cycle_count_advance(16); */
            SWAP_mem(reg.HL);
            return;
        }
        case 0x37:
        {
            /* cycle_count_advance(8); */
            SWAP_reg8(&reg.A);
            return;
        }
        case 0x38:
        {
            /* cycle_count_advance(8); */
            SRL_reg8(&reg.B);
            return;
        }
        case 0x39:
        {
            /* cycle_count_advance(8); */
            SRL_reg8(&reg.C);
            return;
        }
        case 0x3A:
        {
            /* cycle_count_advance(8); */
            SRL_reg8(&reg.D);
            return;
        }
        case 0x3B:
        {
            /* cycle_count_advance(8); */
            SRL_reg8(&reg.E);
            return;
        }
        case 0x3C:
        {
            /* cycle_count_advance(8); */
            SRL_reg8(&reg.H);
            return;
        }
        case 0x3D:
        {
            /* cycle_count_advance(8); */
            SRL_reg8(&reg.L);
            return;
        }
        case 0x3E:
        {
            /* cycle_count_advance(16); */
            SRL_mem(reg.HL);
            return;
        }
        case 0x3F:
        {
            /* cycle_count_advance(8); */
            SRL_reg8(&reg.A);
            return;
        }
        case 0x40:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x0, &reg.B);
            return;
        }
        case 0x41:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x0, &reg.C);
            return;
        }
        case 0x42:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x0, &reg.D);
            return;
        }
        case 0x43:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x0, &reg.E);
            return;
        }
        case 0x44:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x0, &reg.H);
            return;
        }
        case 0x45:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x0, &reg.L);
            return;
        }
        case 0x46:
        {
            /* cycle_count_advance(12); */
            BIT_const8_mem(0x0, reg.HL);
            return;
        }
        case 0x47:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x0, &reg.A);
            return;
        }
        case 0x48:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x1, &reg.B);
            return;
        }
        case 0x49:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x1, &reg.C);
            return;
        }
        case 0x4A:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x1, &reg.D);
            return;
        }
        case 0x4B:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x1, &reg.E);
            return;
        }
        case 0x4C:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x1, &reg.H);
            return;
        }
        case 0x4D:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x1, &reg.L);
            return;
        }
        case 0x4E:
        {
            /* cycle_count_advance(12); */
            BIT_const8_mem(0x1, reg.HL);
            return;
        }
        case 0x4F:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x1, &reg.A);
            return;
        }
        case 0x50:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x2, &reg.B);
            return;
        }
        case 0x51:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x2, &reg.C);
            return;
        }
        case 0x52:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x2, &reg.D);
            return;
        }
        case 0x53:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x2, &reg.E);
            return;
        }
        case 0x54:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x2, &reg.H);
            return;
        }
        case 0x55:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x2, &reg.L);
            return;
        }
        case 0x56:
        {
            /* cycle_count_advance(12); */
            BIT_const8_mem(0x2, reg.HL);
            return;
        }
        case 0x57:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x2, &reg.A);
            return;
        }
        case 0x58:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x3, &reg.B);
            return;
        }
        case 0x59:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x3, &reg.C);
            return;
        }
        case 0x5A:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x3, &reg.D);
            return;
        }
        case 0x5B:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x3, &reg.E);
            return;
        }
        case 0x5C:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x3, &reg.H);
            return;
        }
        case 0x5D:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x3, &reg.L);
            return;
        }
        case 0x5E:
        {
            /* cycle_count_advance(12); */
            BIT_const8_mem(0x3, reg.HL);
            return;
        }
        case 0x5F:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x3, &reg.A);
            return;
        }
        case 0x60:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x4, &reg.B);
            return;
        }
        case 0x61:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x4, &reg.C);
            return;
        }
        case 0x62:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x4, &reg.D);
            return;
        }
        case 0x63:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x4, &reg.E);
            return;
        }
        case 0x64:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x4, &reg.H);
            return;
        }
        case 0x65:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x4, &reg.L);
            return;
        }
        case 0x66:
        {
            /* cycle_count_advance(12); */
            BIT_const8_mem(0x4, reg.HL);
            return;
        }
        case 0x67:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x4, &reg.A);
            return;
        }
        case 0x68:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x5, &reg.B);
            return;
        }
        case 0x69:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x5, &reg.C);
            return;
        }
        case 0x6A:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x5, &reg.D);
            return;
        }
        case 0x6B:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x5, &reg.E);
            return;
        }
        case 0x6C:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x5, &reg.H);
            return;
        }
        case 0x6D:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x5, &reg.L);
            return;
        }
        case 0x6E:
        {
            /* cycle_count_advance(12); */
            BIT_const8_mem(0x5, reg.HL);
            return;
        }
        case 0x6F:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x5, &reg.A);
            return;
        }
        case 0x70:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x6, &reg.B);
            return;
        }
        case 0x71:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x6, &reg.C);
            return;
        }
        case 0x72:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x6, &reg.D);
            return;
        }
        case 0x73:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x6, &reg.E);
            return;
        }
        case 0x74:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x6, &reg.H);
            return;
        }
        case 0x75:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x6, &reg.L);
            return;
        }
        case 0x76:
        {
            /* cycle_count_advance(12); */
            BIT_const8_mem(0x6, reg.HL);
            return;
        }
        case 0x77:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x6, &reg.A);
            return;
        }
        case 0x78:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x7, &reg.B);
            return;
        }
        case 0x79:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x7, &reg.C);
            return;
        }
        case 0x7A:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x7, &reg.D);
            return;
        }
        case 0x7B:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x7, &reg.E);
            return;
        }
        case 0x7C:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x7, &reg.H);
            return;
        }
        case 0x7D:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x7, &reg.L);
            return;
        }
        case 0x7E:
        {
            /* cycle_count_advance(12); */
            BIT_const8_mem(0x7, reg.HL);
            return;
        }
        case 0x7F:
        {
            /* cycle_count_advance(8); */
            BIT_const8_reg8(0x7, &reg.A);
            return;
        }
        case 0x80:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x0, &reg.B);
            return;
        }
        case 0x81:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x0, &reg.C);
            return;
        }
        case 0x82:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x0, &reg.D);
            return;
        }
        case 0x83:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x0, &reg.E);
            return;
        }
        case 0x84:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x0, &reg.H);
            return;
        }
        case 0x85:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x0, &reg.L);
            return;
        }
        case 0x86:
        {
            /* cycle_count_advance(16); */
            RES_const8_mem(0x0, reg.HL);
            return;
        }
        case 0x87:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x0, &reg.A);
            return;
        }
        case 0x88:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x1, &reg.B);
            return;
        }
        case 0x89:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x1, &reg.C);
            return;
        }
        case 0x8A:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x1, &reg.D);
            return;
        }
        case 0x8B:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x1, &reg.E);
            return;
        }
        case 0x8C:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x1, &reg.H);
            return;
        }
        case 0x8D:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x1, &reg.L);
            return;
        }
        case 0x8E:
        {
            /* cycle_count_advance(16); */
            RES_const8_mem(0x1, reg.HL);
            return;
        }
        case 0x8F:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x1, &reg.A);
            return;
        }
        case 0x90:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x2, &reg.B);
            return;
        }
        case 0x91:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x2, &reg.C);
            return;
        }
        case 0x92:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x2, &reg.D);
            return;
        }
        case 0x93:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x2, &reg.E);
            return;
        }
        case 0x94:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x2, &reg.H);
            return;
        }
        case 0x95:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x2, &reg.L);
            return;
        }
        case 0x96:
        {
            /* cycle_count_advance(16); */
            RES_const8_mem(0x2, reg.HL);
            return;
        }
        case 0x97:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x2, &reg.A);
            return;
        }
        case 0x98:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x3, &reg.B);
            return;
        }
        case 0x99:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x3, &reg.C);
            return;
        }
        case 0x9A:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x3, &reg.D);
            return;
        }
        case 0x9B:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x3, &reg.E);
            return;
        }
        case 0x9C:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x3, &reg.H);
            return;
        }
        case 0x9D:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x3, &reg.L);
            return;
        }
        case 0x9E:
        {
            /* cycle_count_advance(16); */
            RES_const8_mem(0x3, reg.HL);
            return;
        }
        case 0x9F:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x3, &reg.A);
            return;
        }
        case 0xA0:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x4, &reg.B);
            return;
        }
        case 0xA1:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x4, &reg.C);
            return;
        }
        case 0xA2:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x4, &reg.D);
            return;
        }
        case 0xA3:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x4, &reg.E);
            return;
        }
        case 0xA4:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x4, &reg.H);
            return;
        }
        case 0xA5:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x4, &reg.L);
            return;
        }
        case 0xA6:
        {
            /* cycle_count_advance(16); */
            RES_const8_mem(0x4, reg.HL);
            return;
        }
        case 0xA7:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x4, &reg.A);
            return;
        }
        case 0xA8:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x5, &reg.B);
            return;
        }
        case 0xA9:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x5, &reg.C);
            return;
        }
        case 0xAA:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x5, &reg.D);
            return;
        }
        case 0xAB:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x5, &reg.E);
            return;
        }
        case 0xAC:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x5, &reg.H);
            return;
        }
        case 0xAD:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x5, &reg.L);
            return;
        }
        case 0xAE:
        {
            /* cycle_count_advance(16); */
            RES_const8_mem(0x5, reg.HL);
            return;
        }
        case 0xAF:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x5, &reg.A);
            return;
        }
        case 0xB0:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x6, &reg.B);
            return;
        }
        case 0xB1:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x6, &reg.C);
            return;
        }
        case 0xB2:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x6, &reg.D);
            return;
        }
        case 0xB3:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x6, &reg.E);
            return;
        }
        case 0xB4:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x6, &reg.H);
            return;
        }
        case 0xB5:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x6, &reg.L);
            return;
        }
        case 0xB6:
        {
            /* cycle_count_advance(16); */
            RES_const8_mem(0x6, reg.HL);
            return;
        }
        case 0xB7:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x6, &reg.A);
            return;
        }
        case 0xB8:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x7, &reg.B);
            return;
        }
        case 0xB9:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x7, &reg.C);
            return;
        }
        case 0xBA:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x7, &reg.D);
            return;
        }
        case 0xBB:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x7, &reg.E);
            return;
        }
        case 0xBC:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x7, &reg.H);
            return;
        }
        case 0xBD:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x7, &reg.L);
            return;
        }
        case 0xBE:
        {
            /* cycle_count_advance(16); */
            RES_const8_mem(0x7, reg.HL);
            return;
        }
        case 0xBF:
        {
            /* cycle_count_advance(8); */
            RES_const8_reg8(0x7, &reg.A);
            return;
        }
        case 0xC0:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x0, &reg.B);
            return;
        }
        case 0xC1:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x0, &reg.C);
            return;
        }
        case 0xC2:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x0, &reg.D);
            return;
        }
        case 0xC3:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x0, &reg.E);
            return;
        }
        case 0xC4:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x0, &reg.H);
            return;
        }
        case 0xC5:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x0, &reg.L);
            return;
        }
        case 0xC6:
        {
            /* cycle_count_advance(16); */
            SET_const8_mem(0x0, reg.HL);
            return;
        }
        case 0xC7:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x0, &reg.A);
            return;
        }
        case 0xC8:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x1, &reg.B);
            return;
        }
        case 0xC9:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x1, &reg.C);
            return;
        }
        case 0xCA:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x1, &reg.D);
            return;
        }
        case 0xCB:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x1, &reg.E);
            return;
        }
        case 0xCC:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x1, &reg.H);
            return;
        }
        case 0xCD:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x1, &reg.L);
            return;
        }
        case 0xCE:
        {
            /* cycle_count_advance(16); */
            SET_const8_mem(0x1, reg.HL);
            return;
        }
        case 0xCF:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x1, &reg.A);
            return;
        }
        case 0xD0:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x2, &reg.B);
            return;
        }
        case 0xD1:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x2, &reg.C);
            return;
        }
        case 0xD2:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x2, &reg.D);
            return;
        }
        case 0xD3:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x2, &reg.E);
            return;
        }
        case 0xD4:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x2, &reg.H);
            return;
        }
        case 0xD5:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x2, &reg.L);
            return;
        }
        case 0xD6:
        {
            /* cycle_count_advance(16); */
            SET_const8_mem(0x2, reg.HL);
            return;
        }
        case 0xD7:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x2, &reg.A);
            return;
        }
        case 0xD8:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x3, &reg.B);
            return;
        }
        case 0xD9:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x3, &reg.C);
            return;
        }
        case 0xDA:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x3, &reg.D);
            return;
        }
        case 0xDB:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x3, &reg.E);
            return;
        }
        case 0xDC:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x3, &reg.H);
            return;
        }
        case 0xDD:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x3, &reg.L);
            return;
        }
        case 0xDE:
        {
            /* cycle_count_advance(16); */
            SET_const8_mem(0x3, reg.HL);
            return;
        }
        case 0xDF:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x3, &reg.A);
            return;
        }
        case 0xE0:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x4, &reg.B);
            return;
        }
        case 0xE1:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x4, &reg.C);
            return;
        }
        case 0xE2:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x4, &reg.D);
            return;
        }
        case 0xE3:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x4, &reg.E);
            return;
        }
        case 0xE4:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x4, &reg.H);
            return;
        }
        case 0xE5:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x4, &reg.L);
            return;
        }
        case 0xE6:
        {
            /* cycle_count_advance(16); */
            SET_const8_mem(0x4, reg.HL);
            return;
        }
        case 0xE7:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x4, &reg.A);
            return;
        }
        case 0xE8:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x5, &reg.B);
            return;
        }
        case 0xE9:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x5, &reg.C);
            return;
        }
        case 0xEA:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x5, &reg.D);
            return;
        }
        case 0xEB:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x5, &reg.E);
            return;
        }
        case 0xEC:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x5, &reg.H);
            return;
        }
        case 0xED:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x5, &reg.L);
            return;
        }
        case 0xEE:
        {
            /* cycle_count_advance(16); */
            SET_const8_mem(0x5, reg.HL);
            return;
        }
        case 0xEF:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x5, &reg.A);
            return;
        }
        case 0xF0:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x6, &reg.B);
            return;
        }
        case 0xF1:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x6, &reg.C);
            return;
        }
        case 0xF2:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x6, &reg.D);
            return;
        }
        case 0xF3:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x6, &reg.E);
            return;
        }
        case 0xF4:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x6, &reg.H);
            return;
        }
        case 0xF5:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x6, &reg.L);
            return;
        }
        case 0xF6:
        {
            /* cycle_count_advance(16); */
            SET_const8_mem(0x6, reg.HL);
            return;
        }
        case 0xF7:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x6, &reg.A);
            return;
        }
        case 0xF8:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x7, &reg.B);
            return;
        }
        case 0xF9:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x7, &reg.C);
            return;
        }
        case 0xFA:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x7, &reg.D);
            return;
        }
        case 0xFB:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x7, &reg.E);
            return;
        }
        case 0xFC:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x7, &reg.H);
            return;
        }
        case 0xFD:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x7, &reg.L);
            return;
        }
        case 0xFE:
        {
            /* cycle_count_advance(16); */
            SET_const8_mem(0x7, reg.HL);
            return;
        }
        case 0xFF:
        {
            /* cycle_count_advance(8); */
            SET_const8_reg8(0x7, &reg.A);
            return;
        }

    }

    std::cout << "Unkown upcode " + to_hex_string(opcode) << std::endl;
    unreachable();
}


void exec_op() {
    u8 opcode = read_pc_u8();
    switch(opcode) {
        case 0x00:
        {
            /* cycle_count_advance(4); */
            NOP();
            return;
        }
        case 0x01:
        {
            /* cycle_count_advance(12); */
            LD_reg16_const16(&reg.BC, read_pc_u16());
            return;
        }
        case 0x02:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.BC, &reg.A);
            return;
        }
        case 0x03:
        {
            /* cycle_count_advance(8); */
            INC_reg16(&reg.BC);
            return;
        }
        case 0x04:
        {
            /* cycle_count_advance(4); */
            INC_reg8(&reg.B);
            return;
        }
        case 0x05:
        {
            /* cycle_count_advance(4); */
            DEC_reg8(&reg.B);
            return;
        }
        case 0x06:
        {
            /* cycle_count_advance(8); */
            LD_reg8_const8(&reg.B, read_pc_u8());
            return;
        }
        case 0x07:
        {
            /* cycle_count_advance(4); */
            RLCA();
            return;
        }
        case 0x08:
        {
            /* cycle_count_advance(20); */
            LD_mem_reg16(read_pc_u16(), &reg.SP);
            return;
        }
        case 0x09:
        {
            /* cycle_count_advance(8); */
            ADD_reg16_reg16(&reg.HL, &reg.BC);
            return;
        }
        case 0x0A:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.A, reg.BC);
            return;
        }
        case 0x0B:
        {
            /* cycle_count_advance(8); */
            DEC_reg16(&reg.BC);
            return;
        }
        case 0x0C:
        {
            /* cycle_count_advance(4); */
            INC_reg8(&reg.C);
            return;
        }
        case 0x0D:
        {
            /* cycle_count_advance(4); */
            DEC_reg8(&reg.C);
            return;
        }
        case 0x0E:
        {
            /* cycle_count_advance(8); */
            LD_reg8_const8(&reg.C, read_pc_u8());
            return;
        }
        case 0x0F:
        {
            /* cycle_count_advance(4); */
            RRCA();
            return;
        }
        case 0x10:
        {
            /* cycle_count_advance(4); */
            STOP_const8(0x0);
            return;
        }
        case 0x11:
        {
            /* cycle_count_advance(12); */
            LD_reg16_const16(&reg.DE, read_pc_u16());
            return;
        }
        case 0x12:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.DE, &reg.A);
            return;
        }
        case 0x13:
        {
            /* cycle_count_advance(8); */
            INC_reg16(&reg.DE);
            return;
        }
        case 0x14:
        {
            /* cycle_count_advance(4); */
            INC_reg8(&reg.D);
            return;
        }
        case 0x15:
        {
            /* cycle_count_advance(4); */
            DEC_reg8(&reg.D);
            return;
        }
        case 0x16:
        {
            /* cycle_count_advance(8); */
            LD_reg8_const8(&reg.D, read_pc_u8());
            return;
        }
        case 0x17:
        {
            /* cycle_count_advance(4); */
            RLA();
            return;
        }
        case 0x18:
        {
            /* cycle_count_advance(12); */
            JR_const8(read_pc_i8());
            return;
        }
        case 0x19:
        {
            /* cycle_count_advance(8); */
            ADD_reg16_reg16(&reg.HL, &reg.DE);
            return;
        }
        case 0x1A:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.A, reg.DE);
            return;
        }
        case 0x1B:
        {
            /* cycle_count_advance(8); */
            DEC_reg16(&reg.DE);
            return;
        }
        case 0x1C:
        {
            /* cycle_count_advance(4); */
            INC_reg8(&reg.E);
            return;
        }
        case 0x1D:
        {
            /* cycle_count_advance(4); */
            DEC_reg8(&reg.E);
            return;
        }
        case 0x1E:
        {
            /* cycle_count_advance(8); */
            LD_reg8_const8(&reg.E, read_pc_u8());
            return;
        }
        case 0x1F:
        {
            /* cycle_count_advance(4); */
            RRA();
            return;
        }
        case 0x20:
        {
            /* cycle_count_advance(!reg.FZ ? 12 : 8); */
            JR_flag_const8(!reg.FZ, read_pc_i8());
            return;
        }
        case 0x21:
        {
            /* cycle_count_advance(12); */
            LD_reg16_const16(&reg.HL, read_pc_u16());
            return;
        }
        case 0x22:
        {
            /* cycle_count_advance(8); */
            LD_memHLinc_reg8(reg.HL, &reg.A);
            return;
        }
        case 0x23:
        {
            /* cycle_count_advance(8); */
            INC_reg16(&reg.HL);
            return;
        }
        case 0x24:
        {
            /* cycle_count_advance(4); */
            INC_reg8(&reg.H);
            return;
        }
        case 0x25:
        {
            /* cycle_count_advance(4); */
            DEC_reg8(&reg.H);
            return;
        }
        case 0x26:
        {
            /* cycle_count_advance(8); */
            LD_reg8_const8(&reg.H, read_pc_u8());
            return;
        }
        case 0x27:
        {
            /* cycle_count_advance(4); */
            DAA();
            return;
        }
        case 0x28:
        {
            /* cycle_count_advance(reg.FZ ? 12 : 8); */
            JR_flag_const8(reg.FZ, read_pc_i8());
            return;
        }
        case 0x29:
        {
            /* cycle_count_advance(8); */
            ADD_reg16_reg16(&reg.HL, &reg.HL);
            return;
        }
        case 0x2A:
        {
            /* cycle_count_advance(8); */
            LD_reg8_memHLinc(&reg.A, reg.HL);
            return;
        }
        case 0x2B:
        {
            /* cycle_count_advance(8); */
            DEC_reg16(&reg.HL);
            return;
        }
        case 0x2C:
        {
            /* cycle_count_advance(4); */
            INC_reg8(&reg.L);
            return;
        }
        case 0x2D:
        {
            /* cycle_count_advance(4); */
            DEC_reg8(&reg.L);
            return;
        }
        case 0x2E:
        {
            /* cycle_count_advance(8); */
            LD_reg8_const8(&reg.L, read_pc_u8());
            return;
        }
        case 0x2F:
        {
            /* cycle_count_advance(4); */
            CPL();
            return;
        }
        case 0x30:
        {
            /* cycle_count_advance(!reg.FC ? 12 : 8); */
            JR_flag_const8(!reg.FC, read_pc_i8());
            return;
        }
        case 0x31:
        {
            /* cycle_count_advance(12); */
            LD_reg16_const16(&reg.SP, read_pc_u16());
            return;
        }
        case 0x32:
        {
            /* cycle_count_advance(8); */
            LD_memHLdec_reg8(reg.HL, &reg.A);
            return;
        }
        case 0x33:
        {
            /* cycle_count_advance(8); */
            INC_reg16(&reg.SP);
            return;
        }
        case 0x34:
        {
            /* cycle_count_advance(12); */
            INC_mem(reg.HL);
            return;
        }
        case 0x35:
        {
            /* cycle_count_advance(12); */
            DEC_mem(reg.HL);
            return;
        }
        case 0x36:
        {
            /* cycle_count_advance(12); */
            LD_mem_const8(reg.HL, read_pc_u8());
            return;
        }
        case 0x37:
        {
            /* cycle_count_advance(4); */
            SCF();
            return;
        }
        case 0x38:
        {
            /* cycle_count_advance(reg.FC ? 12 : 8); */
            JR_flag_const8(reg.FC, read_pc_i8());
            return;
        }
        case 0x39:
        {
            /* cycle_count_advance(8); */
            ADD_reg16_reg16(&reg.HL, &reg.SP);
            return;
        }
        case 0x3A:
        {
            /* cycle_count_advance(8); */
            LD_reg8_memHLdec(&reg.A, reg.HL);
            return;
        }
        case 0x3B:
        {
            /* cycle_count_advance(8); */
            DEC_reg16(&reg.SP);
            return;
        }
        case 0x3C:
        {
            /* cycle_count_advance(4); */
            INC_reg8(&reg.A);
            return;
        }
        case 0x3D:
        {
            /* cycle_count_advance(4); */
            DEC_reg8(&reg.A);
            return;
        }
        case 0x3E:
        {
            /* cycle_count_advance(8); */
            LD_reg8_const8(&reg.A, read_pc_u8());
            return;
        }
        case 0x3F:
        {
            /* cycle_count_advance(4); */
            CCF();
            return;
        }
        case 0x40:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.B, &reg.B);
            return;
        }
        case 0x41:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.B, &reg.C);
            return;
        }
        case 0x42:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.B, &reg.D);
            return;
        }
        case 0x43:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.B, &reg.E);
            return;
        }
        case 0x44:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.B, &reg.H);
            return;
        }
        case 0x45:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.B, &reg.L);
            return;
        }
        case 0x46:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.B, reg.HL);
            return;
        }
        case 0x47:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.B, &reg.A);
            return;
        }
        case 0x48:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.C, &reg.B);
            return;
        }
        case 0x49:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.C, &reg.C);
            return;
        }
        case 0x4A:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.C, &reg.D);
            return;
        }
        case 0x4B:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.C, &reg.E);
            return;
        }
        case 0x4C:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.C, &reg.H);
            return;
        }
        case 0x4D:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.C, &reg.L);
            return;
        }
        case 0x4E:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.C, reg.HL);
            return;
        }
        case 0x4F:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.C, &reg.A);
            return;
        }
        case 0x50:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.D, &reg.B);
            return;
        }
        case 0x51:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.D, &reg.C);
            return;
        }
        case 0x52:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.D, &reg.D);
            return;
        }
        case 0x53:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.D, &reg.E);
            return;
        }
        case 0x54:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.D, &reg.H);
            return;
        }
        case 0x55:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.D, &reg.L);
            return;
        }
        case 0x56:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.D, reg.HL);
            return;
        }
        case 0x57:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.D, &reg.A);
            return;
        }
        case 0x58:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.E, &reg.B);
            return;
        }
        case 0x59:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.E, &reg.C);
            return;
        }
        case 0x5A:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.E, &reg.D);
            return;
        }
        case 0x5B:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.E, &reg.E);
            return;
        }
        case 0x5C:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.E, &reg.H);
            return;
        }
        case 0x5D:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.E, &reg.L);
            return;
        }
        case 0x5E:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.E, reg.HL);
            return;
        }
        case 0x5F:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.E, &reg.A);
            return;
        }
        case 0x60:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.H, &reg.B);
            return;
        }
        case 0x61:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.H, &reg.C);
            return;
        }
        case 0x62:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.H, &reg.D);
            return;
        }
        case 0x63:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.H, &reg.E);
            return;
        }
        case 0x64:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.H, &reg.H);
            return;
        }
        case 0x65:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.H, &reg.L);
            return;
        }
        case 0x66:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.H, reg.HL);
            return;
        }
        case 0x67:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.H, &reg.A);
            return;
        }
        case 0x68:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.L, &reg.B);
            return;
        }
        case 0x69:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.L, &reg.C);
            return;
        }
        case 0x6A:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.L, &reg.D);
            return;
        }
        case 0x6B:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.L, &reg.E);
            return;
        }
        case 0x6C:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.L, &reg.H);
            return;
        }
        case 0x6D:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.L, &reg.L);
            return;
        }
        case 0x6E:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.L, reg.HL);
            return;
        }
        case 0x6F:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.L, &reg.A);
            return;
        }
        case 0x70:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.HL, &reg.B);
            return;
        }
        case 0x71:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.HL, &reg.C);
            return;
        }
        case 0x72:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.HL, &reg.D);
            return;
        }
        case 0x73:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.HL, &reg.E);
            return;
        }
        case 0x74:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.HL, &reg.H);
            return;
        }
        case 0x75:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.HL, &reg.L);
            return;
        }
        case 0x76:
        {
            /* cycle_count_advance(4); */
            HALT();
            return;
        }
        case 0x77:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(reg.HL, &reg.A);
            return;
        }
        case 0x78:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.A, &reg.B);
            return;
        }
        case 0x79:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.A, &reg.C);
            return;
        }
        case 0x7A:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.A, &reg.D);
            return;
        }
        case 0x7B:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.A, &reg.E);
            return;
        }
        case 0x7C:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.A, &reg.H);
            return;
        }
        case 0x7D:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.A, &reg.L);
            return;
        }
        case 0x7E:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.A, reg.HL);
            return;
        }
        case 0x7F:
        {
            /* cycle_count_advance(4); */
            LD_reg8_reg8(&reg.A, &reg.A);
            return;
        }
        case 0x80:
        {
            /* cycle_count_advance(4); */
            ADD_reg8_reg8(&reg.A, &reg.B);
            return;
        }
        case 0x81:
        {
            /* cycle_count_advance(4); */
            ADD_reg8_reg8(&reg.A, &reg.C);
            return;
        }
        case 0x82:
        {
            /* cycle_count_advance(4); */
            ADD_reg8_reg8(&reg.A, &reg.D);
            return;
        }
        case 0x83:
        {
            /* cycle_count_advance(4); */
            ADD_reg8_reg8(&reg.A, &reg.E);
            return;
        }
        case 0x84:
        {
            /* cycle_count_advance(4); */
            ADD_reg8_reg8(&reg.A, &reg.H);
            return;
        }
        case 0x85:
        {
            /* cycle_count_advance(4); */
            ADD_reg8_reg8(&reg.A, &reg.L);
            return;
        }
        case 0x86:
        {
            /* cycle_count_advance(8); */
            ADD_reg8_mem(&reg.A, reg.HL);
            return;
        }
        case 0x87:
        {
            /* cycle_count_advance(4); */
            ADD_reg8_reg8(&reg.A, &reg.A);
            return;
        }
        case 0x88:
        {
            /* cycle_count_advance(4); */
            ADC_reg8_reg8(&reg.A, &reg.B);
            return;
        }
        case 0x89:
        {
            /* cycle_count_advance(4); */
            ADC_reg8_reg8(&reg.A, &reg.C);
            return;
        }
        case 0x8A:
        {
            /* cycle_count_advance(4); */
            ADC_reg8_reg8(&reg.A, &reg.D);
            return;
        }
        case 0x8B:
        {
            /* cycle_count_advance(4); */
            ADC_reg8_reg8(&reg.A, &reg.E);
            return;
        }
        case 0x8C:
        {
            /* cycle_count_advance(4); */
            ADC_reg8_reg8(&reg.A, &reg.H);
            return;
        }
        case 0x8D:
        {
            /* cycle_count_advance(4); */
            ADC_reg8_reg8(&reg.A, &reg.L);
            return;
        }
        case 0x8E:
        {
            /* cycle_count_advance(8); */
            ADC_reg8_mem(&reg.A, reg.HL);
            return;
        }
        case 0x8F:
        {
            /* cycle_count_advance(4); */
            ADC_reg8_reg8(&reg.A, &reg.A);
            return;
        }
        case 0x90:
        {
            /* cycle_count_advance(4); */
            SUB_reg8(&reg.B);
            return;
        }
        case 0x91:
        {
            /* cycle_count_advance(4); */
            SUB_reg8(&reg.C);
            return;
        }
        case 0x92:
        {
            /* cycle_count_advance(4); */
            SUB_reg8(&reg.D);
            return;
        }
        case 0x93:
        {
            /* cycle_count_advance(4); */
            SUB_reg8(&reg.E);
            return;
        }
        case 0x94:
        {
            /* cycle_count_advance(4); */
            SUB_reg8(&reg.H);
            return;
        }
        case 0x95:
        {
            /* cycle_count_advance(4); */
            SUB_reg8(&reg.L);
            return;
        }
        case 0x96:
        {
            /* cycle_count_advance(8); */
            SUB_mem(reg.HL);
            return;
        }
        case 0x97:
        {
            /* cycle_count_advance(4); */
            SUB_reg8(&reg.A);
            return;
        }
        case 0x98:
        {
            /* cycle_count_advance(4); */
            SBC_reg8_reg8(&reg.A, &reg.B);
            return;
        }
        case 0x99:
        {
            /* cycle_count_advance(4); */
            SBC_reg8_reg8(&reg.A, &reg.C);
            return;
        }
        case 0x9A:
        {
            /* cycle_count_advance(4); */
            SBC_reg8_reg8(&reg.A, &reg.D);
            return;
        }
        case 0x9B:
        {
            /* cycle_count_advance(4); */
            SBC_reg8_reg8(&reg.A, &reg.E);
            return;
        }
        case 0x9C:
        {
            /* cycle_count_advance(4); */
            SBC_reg8_reg8(&reg.A, &reg.H);
            return;
        }
        case 0x9D:
        {
            /* cycle_count_advance(4); */
            SBC_reg8_reg8(&reg.A, &reg.L);
            return;
        }
        case 0x9E:
        {
            /* cycle_count_advance(8); */
            SBC_reg8_mem(&reg.A, reg.HL);
            return;
        }
        case 0x9F:
        {
            /* cycle_count_advance(4); */
            SBC_reg8_reg8(&reg.A, &reg.A);
            return;
        }
        case 0xA0:
        {
            /* cycle_count_advance(4); */
            AND_reg8(&reg.B);
            return;
        }
        case 0xA1:
        {
            /* cycle_count_advance(4); */
            AND_reg8(&reg.C);
            return;
        }
        case 0xA2:
        {
            /* cycle_count_advance(4); */
            AND_reg8(&reg.D);
            return;
        }
        case 0xA3:
        {
            /* cycle_count_advance(4); */
            AND_reg8(&reg.E);
            return;
        }
        case 0xA4:
        {
            /* cycle_count_advance(4); */
            AND_reg8(&reg.H);
            return;
        }
        case 0xA5:
        {
            /* cycle_count_advance(4); */
            AND_reg8(&reg.L);
            return;
        }
        case 0xA6:
        {
            /* cycle_count_advance(8); */
            AND_mem(reg.HL);
            return;
        }
        case 0xA7:
        {
            /* cycle_count_advance(4); */
            AND_reg8(&reg.A);
            return;
        }
        case 0xA8:
        {
            /* cycle_count_advance(4); */
            XOR_reg8(&reg.B);
            return;
        }
        case 0xA9:
        {
            /* cycle_count_advance(4); */
            XOR_reg8(&reg.C);
            return;
        }
        case 0xAA:
        {
            /* cycle_count_advance(4); */
            XOR_reg8(&reg.D);
            return;
        }
        case 0xAB:
        {
            /* cycle_count_advance(4); */
            XOR_reg8(&reg.E);
            return;
        }
        case 0xAC:
        {
            /* cycle_count_advance(4); */
            XOR_reg8(&reg.H);
            return;
        }
        case 0xAD:
        {
            /* cycle_count_advance(4); */
            XOR_reg8(&reg.L);
            return;
        }
        case 0xAE:
        {
            /* cycle_count_advance(8); */
            XOR_mem(reg.HL);
            return;
        }
        case 0xAF:
        {
            /* cycle_count_advance(4); */
            XOR_reg8(&reg.A);
            return;
        }
        case 0xB0:
        {
            /* cycle_count_advance(4); */
            OR_reg8(&reg.B);
            return;
        }
        case 0xB1:
        {
            /* cycle_count_advance(4); */
            OR_reg8(&reg.C);
            return;
        }
        case 0xB2:
        {
            /* cycle_count_advance(4); */
            OR_reg8(&reg.D);
            return;
        }
        case 0xB3:
        {
            /* cycle_count_advance(4); */
            OR_reg8(&reg.E);
            return;
        }
        case 0xB4:
        {
            /* cycle_count_advance(4); */
            OR_reg8(&reg.H);
            return;
        }
        case 0xB5:
        {
            /* cycle_count_advance(4); */
            OR_reg8(&reg.L);
            return;
        }
        case 0xB6:
        {
            /* cycle_count_advance(8); */
            OR_mem(reg.HL);
            return;
        }
        case 0xB7:
        {
            /* cycle_count_advance(4); */
            OR_reg8(&reg.A);
            return;
        }
        case 0xB8:
        {
            /* cycle_count_advance(4); */
            CP_reg8(&reg.B);
            return;
        }
        case 0xB9:
        {
            /* cycle_count_advance(4); */
            CP_reg8(&reg.C);
            return;
        }
        case 0xBA:
        {
            /* cycle_count_advance(4); */
            CP_reg8(&reg.D);
            return;
        }
        case 0xBB:
        {
            /* cycle_count_advance(4); */
            CP_reg8(&reg.E);
            return;
        }
        case 0xBC:
        {
            /* cycle_count_advance(4); */
            CP_reg8(&reg.H);
            return;
        }
        case 0xBD:
        {
            /* cycle_count_advance(4); */
            CP_reg8(&reg.L);
            return;
        }
        case 0xBE:
        {
            /* cycle_count_advance(8); */
            CP_mem(reg.HL);
            return;
        }
        case 0xBF:
        {
            /* cycle_count_advance(4); */
            CP_reg8(&reg.A);
            return;
        }
        case 0xC0:
        {
            /* cycle_count_advance(!reg.FZ ? 20 : 8); */
            RET_flag(!reg.FZ);
            return;
        }
        case 0xC1:
        {
            /* cycle_count_advance(12); */
            POP_reg16(&reg.BC);
            return;
        }
        case 0xC2:
        {
            /* cycle_count_advance(!reg.FZ ? 16 : 12); */
            JP_flag_const16(!reg.FZ, read_pc_u16());
            return;
        }
        case 0xC3:
        {
            /* cycle_count_advance(16); */
            JP_const16(read_pc_u16());
            return;
        }
        case 0xC4:
        {
            /* cycle_count_advance(!reg.FZ ? 24 : 12); */
            CALL_flag_const16(!reg.FZ, read_pc_u16());
            return;
        }
        case 0xC5:
        {
            /* cycle_count_advance(16); */
            PUSH_reg16(&reg.BC);
            return;
        }
        case 0xC6:
        {
            /* cycle_count_advance(8); */
            ADD_reg8_const8(&reg.A, read_pc_u8());
            return;
        }
        case 0xC7:
        {
            /* cycle_count_advance(16); */
            RST_const8(0x00);
            return;
        }
        case 0xC8:
        {
            /* cycle_count_advance(reg.FZ ? 20 : 8); */
            RET_flag(reg.FZ);
            return;
        }
        case 0xC9:
        {
            /* cycle_count_advance(16); */
            RET();
            return;
        }
        case 0xCA:
        {
            /* cycle_count_advance(reg.FZ ? 16 : 12); */
            JP_flag_const16(reg.FZ, read_pc_u16());
            return;
        }
        case 0xCC:
        {
            /* cycle_count_advance(reg.FZ ? 24 : 12); */
            CALL_flag_const16(reg.FZ, read_pc_u16());
            return;
        }
        case 0xCD:
        {
            /* cycle_count_advance(24); */
            CALL_const16(read_pc_u16());
            return;
        }
        case 0xCE:
        {
            /* cycle_count_advance(8); */
            ADC_reg8_const8(&reg.A, read_pc_u8());
            return;
        }
        case 0xCF:
        {
            /* cycle_count_advance(16); */
            RST_const8(0x08);
            return;
        }
        case 0xD0:
        {
            /* cycle_count_advance(!reg.FC ? 20 : 8); */
            RET_flag(!reg.FC);
            return;
        }
        case 0xD1:
        {
            /* cycle_count_advance(12); */
            POP_reg16(&reg.DE);
            return;
        }
        case 0xD2:
        {
            /* cycle_count_advance(!reg.FC ? 16 : 12); */
            JP_flag_const16(!reg.FC, read_pc_u16());
            return;
        }
        case 0xD4:
        {
            /* cycle_count_advance(!reg.FC ? 24 : 12); */
            CALL_flag_const16(!reg.FC, read_pc_u16());
            return;
        }
        case 0xD5:
        {
            /* cycle_count_advance(16); */
            PUSH_reg16(&reg.DE);
            return;
        }
        case 0xD6:
        {
            /* cycle_count_advance(8); */
            SUB_const8(read_pc_u8());
            return;
        }
        case 0xD7:
        {
            /* cycle_count_advance(16); */
            RST_const8(0x10);
            return;
        }
        case 0xD8:
        {
            /* cycle_count_advance(reg.FC ? 20 : 8); */
            RET_flag(reg.FC);
            return;
        }
        case 0xD9:
        {
            /* cycle_count_advance(16); */
            RETI();
            return;
        }
        case 0xDA:
        {
            /* cycle_count_advance(reg.FC ? 16 : 12); */
            JP_flag_const16(reg.FC, read_pc_u16());
            return;
        }
        case 0xDC:
        {
            /* cycle_count_advance(reg.FC ? 24 : 12); */
            CALL_flag_const16(reg.FC, read_pc_u16());
            return;
        }
        case 0xDE:
        {
            /* cycle_count_advance(8); */
            SBC_reg8_const8(&reg.A, read_pc_u8());
            return;
        }
        case 0xDF:
        {
            /* cycle_count_advance(16); */
            RST_const8(0x18);
            return;
        }
        case 0xE0:
        {
            /* cycle_count_advance(12); */
            LDH_mem_reg8(0xff00+read_pc_u8(), &reg.A);
            return;
        }
        case 0xE1:
        {
            /* cycle_count_advance(12); */
            POP_reg16(&reg.HL);
            return;
        }
        case 0xE2:
        {
            /* cycle_count_advance(8); */
            LD_mem_reg8(0xff00+reg.C, &reg.A);
            return;
        }
        case 0xE5:
        {
            /* cycle_count_advance(16); */
            PUSH_reg16(&reg.HL);
            return;
        }
        case 0xE6:
        {
            /* cycle_count_advance(8); */
            AND_const8(read_pc_u8());
            return;
        }
        case 0xE7:
        {
            /* cycle_count_advance(16); */
            RST_const8(0x20);
            return;
        }
        case 0xE8:
        {
            /* cycle_count_advance(16); */
            ADD_reg16_const8(&reg.SP, read_pc_u8());
            return;
        }
        case 0xE9:
        {
            /* cycle_count_advance(4); */
            JP_mem(reg.HL);
            return;
        }
        case 0xEA:
        {
            /* cycle_count_advance(16); */
            LD_mem_reg8(read_pc_u16(), &reg.A);
            return;
        }
        case 0xEE:
        {
            /* cycle_count_advance(8); */
            XOR_const8(read_pc_u8());
            return;
        }
        case 0xEF:
        {
            /* cycle_count_advance(16); */
            RST_const8(0x28);
            return;
        }
        case 0xF0:
        {
            /* cycle_count_advance(12); */
            LDH_reg8_mem(&reg.A, 0xff00+read_pc_u8());
            return;
        }
        case 0xF1:
        {
            /* cycle_count_advance(12); */
            POP_reg16(&reg.AF);
            return;
        }
        case 0xF2:
        {
            /* cycle_count_advance(8); */
            LD_reg8_mem(&reg.A, 0xff00+reg.C);
            return;
        }
        case 0xF3:
        {
            /* cycle_count_advance(4); */
            DI();
            return;
        }
        case 0xF5:
        {
            /* cycle_count_advance(16); */
            PUSH_reg16(&reg.AF);
            return;
        }
        case 0xF6:
        {
            /* cycle_count_advance(8); */
            OR_const8(read_pc_u8());
            return;
        }
        case 0xF7:
        {
            /* cycle_count_advance(16); */
            RST_const8(0x30);
            return;
        }
        case 0xF8:
        {
            /* cycle_count_advance(12); */
            LD_reg16_const8(&reg.HL, read_pc_u8());
            return;
        }
        case 0xF9:
        {
            /* cycle_count_advance(8); */
            LD_reg16_reg16(&reg.SP, &reg.HL);
            return;
        }
        case 0xFA:
        {
            /* cycle_count_advance(16); */
            LD_reg8_mem(&reg.A, read_pc_u16());
            return;
        }
        case 0xFB:
        {
            /* cycle_count_advance(4); */
            EI();
            return;
        }
        case 0xFE:
        {
            /* cycle_count_advance(8); */
            CP_const8(read_pc_u8());
            return;
        }
        case 0xFF:
        {
            /* cycle_count_advance(16); */
            RST_const8(0x38);
            return;
        }

        case 0xCB:
            exec_op_prefix();
            return;
    }

    std::cout << "Unkown upcode " + to_hex_string(opcode) << std::endl;
    unreachable();
}


