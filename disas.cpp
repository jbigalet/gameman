std::string disas_prefix(std::vector<i8>::iterator* it, bool with_bytes=true, bool with_timings=true, bool with_flags=true) {
    u8 opcode = read<u8>(it);
    switch(opcode) {
        case 0x00:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "00";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLC B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x01:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "01";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLC C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x02:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "02";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLC D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x03:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "03";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLC E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x04:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "04";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLC H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x05:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "05";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLC L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x06:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "06";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLC (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x07:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "07";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLC A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x08:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "08";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRC B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x09:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "09";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRC C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x0A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "0A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRC D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x0B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "0B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRC E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x0C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "0C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRC H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x0D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "0D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRC L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x0E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "0E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRC (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x0F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "0F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRC A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x10:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "10";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RL B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x11:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "11";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RL C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x12:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "12";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RL D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x13:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "13";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RL E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x14:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "14";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RL H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x15:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "15";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RL L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x16:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "16";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RL (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x17:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "17";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RL A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x18:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "18";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RR B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x19:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "19";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RR C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x1A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "1A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RR D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x1B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "1B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RR E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x1C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "1C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RR H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x1D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "1D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RR L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x1E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "1E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RR (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x1F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "1F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RR A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x20:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "20";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SLA B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x21:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "21";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SLA C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x22:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "22";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SLA D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x23:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "23";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SLA E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x24:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "24";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SLA H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x25:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "25";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SLA L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x26:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "26";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SLA (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x27:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "27";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SLA A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x28:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "28";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRA B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x29:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "29";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRA C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x2A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "2A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRA D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x2B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "2B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRA E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x2C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "2C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRA H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x2D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "2D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRA L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x2E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "2E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRA (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x2F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "2F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRA A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x30:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "30";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SWAP B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x31:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "31";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SWAP C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x32:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "32";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SWAP D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x33:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "33";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SWAP E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x34:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "34";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SWAP H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x35:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "35";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SWAP L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x36:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "36";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SWAP (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x37:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "37";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SWAP A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0x38:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "38";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRL B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x39:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "39";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRL C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x3A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "3A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRL D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x3B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "3B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRL E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x3C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "3C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRL H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x3D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "3D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRL L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x3E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "3E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRL (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x3F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "3F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SRL A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,C";
            }

            return str;
        }
        case 0x40:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "40";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 0,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x41:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "41";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 0,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x42:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "42";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 0,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x43:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "43";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 0,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x44:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "44";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 0,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x45:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "45";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 0,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x46:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "46";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 0,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x47:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "47";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 0,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x48:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "48";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 1,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x49:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "49";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 1,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x4A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "4A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 1,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x4B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "4B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 1,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x4C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "4C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 1,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x4D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "4D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 1,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x4E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "4E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 1,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x4F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "4F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 1,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x50:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "50";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 2,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x51:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "51";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 2,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x52:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "52";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 2,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x53:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "53";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 2,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x54:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "54";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 2,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x55:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "55";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 2,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x56:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "56";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 2,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x57:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "57";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 2,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x58:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "58";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 3,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x59:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "59";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 3,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x5A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "5A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 3,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x5B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "5B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 3,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x5C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "5C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 3,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x5D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "5D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 3,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x5E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "5E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 3,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x5F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "5F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 3,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x60:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "60";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 4,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x61:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "61";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 4,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x62:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "62";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 4,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x63:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "63";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 4,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x64:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "64";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 4,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x65:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "65";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 4,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x66:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "66";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 4,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x67:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "67";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 4,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x68:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "68";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 5,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x69:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "69";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 5,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x6A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "6A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 5,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x6B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "6B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 5,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x6C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "6C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 5,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x6D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "6D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 5,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x6E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "6E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 5,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x6F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "6F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 5,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x70:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "70";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 6,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x71:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "71";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 6,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x72:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "72";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 6,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x73:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "73";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 6,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x74:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "74";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 6,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x75:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "75";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 6,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x76:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "76";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 6,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x77:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "77";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 6,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x78:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "78";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 7,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x79:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "79";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 7,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x7A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "7A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 7,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x7B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "7B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 7,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x7C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "7C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 7,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x7D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "7D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 7,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x7E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "7E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 7,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x7F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "7F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "BIT 7,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,-";
            }

            return str;
        }
        case 0x80:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "80";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 0,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x81:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "81";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 0,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x82:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "82";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 0,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x83:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "83";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 0,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x84:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "84";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 0,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x85:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "85";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 0,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x86:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "86";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 0,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x87:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "87";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 0,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x88:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "88";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 1,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x89:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "89";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 1,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x8A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "8A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 1,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x8B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "8B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 1,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x8C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "8C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 1,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x8D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "8D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 1,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x8E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "8E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 1,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x8F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "8F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 1,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x90:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "90";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 2,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x91:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "91";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 2,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x92:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "92";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 2,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x93:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "93";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 2,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x94:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "94";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 2,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x95:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "95";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 2,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x96:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "96";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 2,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x97:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "97";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 2,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x98:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "98";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 3,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x99:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "99";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 3,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x9A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "9A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 3,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x9B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "9B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 3,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x9C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "9C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 3,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x9D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "9D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 3,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x9E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "9E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 3,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x9F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "9F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 3,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 4,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 4,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 4,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 4,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA4:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A4";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 4,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 4,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA6:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A6";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 4,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 4,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 5,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xA9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "A9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 5,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xAA:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "AA";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 5,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xAB:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "AB";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 5,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xAC:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "AC";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 5,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xAD:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "AD";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 5,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xAE:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "AE";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 5,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xAF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "AF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 5,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 6,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 6,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 6,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 6,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB4:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B4";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 6,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 6,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB6:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B6";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 6,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 6,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 7,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xB9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "B9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 7,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xBA:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "BA";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 7,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xBB:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "BB";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 7,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xBC:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "BC";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 7,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xBD:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "BD";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 7,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xBE:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "BE";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 7,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xBF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "BF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RES 7,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 0,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 0,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 0,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 0,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC4:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C4";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 0,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 0,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC6:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C6";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 0,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 0,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 1,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "C9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 1,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCA:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "CA";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 1,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCC:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "CC";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 1,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCD:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "CD";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 1,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCE:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "CE";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 1,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "CF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 1,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 2,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 2,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 2,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 2,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD4:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D4";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 2,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 2,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD6:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D6";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 2,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 2,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 3,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "D9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 3,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDA:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "DA";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 3,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDB:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "DB";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 3,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDC:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "DC";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 3,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDD:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "DD";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 3,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDE:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "DE";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 3,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "DF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 3,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 4,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 4,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 4,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 4,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE4:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E4";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 4,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 4,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE6:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E6";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 4,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 4,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 5,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "E9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 5,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xEA:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "EA";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 5,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xEB:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "EB";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 5,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xEC:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "EC";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 5,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xED:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "ED";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 5,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xEE:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "EE";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 5,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xEF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "EF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 5,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 6,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 6,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 6,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 6,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF4:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F4";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 6,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 6,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF6:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F6";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 6,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 6,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 7,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "F9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 7,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFA:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "FA";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 7,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFB:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "FB";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 7,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFC:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "FC";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 7,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFD:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "FD";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 7,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFE:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "FE";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 7,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CB ";
                str += "FF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SET 7,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }

        case 0xCB:
            return disas_prefix(it, with_bytes, with_timings, with_flags);
    }

    return "Unkown upcode " + to_hex_string(opcode);
}


std::string disas(std::vector<i8>::iterator* it, bool with_bytes=true, bool with_timings=true, bool with_flags=true) {
    u8 opcode = read<u8>(it);
    switch(opcode) {
        case 0x00:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "00";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "NOP";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x01:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "01";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD BC,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x02:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "02";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (BC),A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x03:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "03";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC BC";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x04:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "04";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,-";
            }

            return str;
        }
        case 0x05:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "05";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,-";
            }

            return str;
        }
        case 0x06:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "06";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x07:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "07";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLCA";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: 0,0,0,C";
            }

            return str;
        }
        case 0x08:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "08";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD ($" + to_hex_string(b1) + "),SP";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 20";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x09:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "09";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD HL,BC";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,0,H,C";
            }

            return str;
        }
        case 0x0A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "0A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,(BC)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x0B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "0B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC BC";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x0C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "0C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,-";
            }

            return str;
        }
        case 0x0D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "0D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,-";
            }

            return str;
        }
        case 0x0E:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "0E";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x0F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "0F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRCA";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: 0,0,0,C";
            }

            return str;
        }
        case 0x10:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "10";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "STOP 0";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x11:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "11";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD DE,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x12:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "12";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (DE),A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x13:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "13";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC DE";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x14:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "14";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,-";
            }

            return str;
        }
        case 0x15:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "15";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,-";
            }

            return str;
        }
        case 0x16:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "16";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x17:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "17";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RLA";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: 0,0,0,C";
            }

            return str;
        }
        case 0x18:
        {
            i8 b1 = read<i8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "18";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JR PC" + to_hex_string(b1, false, true) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x19:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "19";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD HL,DE";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,0,H,C";
            }

            return str;
        }
        case 0x1A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "1A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,(DE)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x1B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "1B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC DE";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x1C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "1C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,-";
            }

            return str;
        }
        case 0x1D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "1D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,-";
            }

            return str;
        }
        case 0x1E:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "1E";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x1F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "1F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RRA";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: 0,0,0,C";
            }

            return str;
        }
        case 0x20:
        {
            i8 b1 = read<i8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "20";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JR NZ,PC" + to_hex_string(b1, false, true) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12/8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x21:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "21";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD HL,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x22:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "22";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL+),A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x23:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "23";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC HL";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x24:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "24";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,-";
            }

            return str;
        }
        case 0x25:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "25";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,-";
            }

            return str;
        }
        case 0x26:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "26";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x27:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "27";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DAA";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,-,0,C";
            }

            return str;
        }
        case 0x28:
        {
            i8 b1 = read<i8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "28";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JR Z,PC" + to_hex_string(b1, false, true) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12/8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x29:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "29";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD HL,HL";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,0,H,C";
            }

            return str;
        }
        case 0x2A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "2A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,(HL+)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x2B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "2B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC HL";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x2C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "2C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,-";
            }

            return str;
        }
        case 0x2D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "2D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,-";
            }

            return str;
        }
        case 0x2E:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "2E";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x2F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "2F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CPL";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,1,1,-";
            }

            return str;
        }
        case 0x30:
        {
            i8 b1 = read<i8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "30";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JR NC,PC" + to_hex_string(b1, false, true) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12/8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x31:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "31";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD SP,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x32:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "32";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL-),A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x33:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "33";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC SP";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x34:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "34";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,-";
            }

            return str;
        }
        case 0x35:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "35";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,-";
            }

            return str;
        }
        case 0x36:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "36";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL),$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x37:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "37";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SCF";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,0,0,1";
            }

            return str;
        }
        case 0x38:
        {
            i8 b1 = read<i8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "38";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JR C,PC" + to_hex_string(b1, false, true) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12/8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x39:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "39";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD HL,SP";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,0,H,C";
            }

            return str;
        }
        case 0x3A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "3A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,(HL-)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x3B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "3B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC SP";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x3C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "3C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "INC A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,-";
            }

            return str;
        }
        case 0x3D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "3D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DEC A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,-";
            }

            return str;
        }
        case 0x3E:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "3E";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x3F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "3F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CCF";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,0,0,C";
            }

            return str;
        }
        case 0x40:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "40";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x41:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "41";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x42:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "42";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x43:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "43";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x44:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "44";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x45:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "45";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x46:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "46";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x47:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "47";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD B,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x48:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "48";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x49:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "49";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x4A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "4A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x4B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "4B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x4C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "4C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x4D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "4D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x4E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "4E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x4F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "4F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD C,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x50:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "50";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x51:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "51";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x52:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "52";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x53:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "53";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x54:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "54";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x55:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "55";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x56:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "56";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x57:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "57";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD D,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x58:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "58";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x59:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "59";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x5A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "5A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x5B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "5B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x5C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "5C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x5D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "5D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x5E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "5E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x5F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "5F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD E,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x60:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "60";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x61:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "61";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x62:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "62";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x63:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "63";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x64:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "64";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x65:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "65";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x66:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "66";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x67:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "67";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD H,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x68:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "68";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x69:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "69";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x6A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "6A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x6B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "6B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x6C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "6C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x6D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "6D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x6E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "6E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x6F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "6F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD L,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x70:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "70";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL),B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x71:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "71";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL),C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x72:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "72";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL),D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x73:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "73";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL),E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x74:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "74";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL),H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x75:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "75";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL),L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x76:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "76";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "HALT";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x77:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "77";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD (HL),A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x78:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "78";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x79:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "79";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x7A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "7A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x7B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "7B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x7C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "7C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x7D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "7D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x7E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "7E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x7F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "7F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0x80:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "80";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x81:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "81";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x82:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "82";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x83:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "83";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x84:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "84";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x85:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "85";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x86:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "86";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x87:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "87";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x88:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "88";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x89:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "89";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x8A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "8A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x8B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "8B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x8C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "8C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x8D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "8D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x8E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "8E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x8F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "8F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0x90:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "90";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x91:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "91";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x92:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "92";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x93:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "93";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x94:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "94";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x95:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "95";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x96:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "96";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x97:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "97";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x98:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "98";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x99:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "99";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x9A:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "9A";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x9B:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "9B";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x9C:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "9C";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x9D:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "9D";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x9E:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "9E";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,(HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0x9F:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "9F";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xA0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xA1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xA2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xA3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xA4:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A4";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xA5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xA6:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A6";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xA7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xA8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xA9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "A9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xAA:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "AA";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xAB:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "AB";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xAC:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "AC";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xAD:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "AD";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xAE:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "AE";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xAF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "AF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB4:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B4";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB6:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B6";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xB8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP B";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xB9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "B9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xBA:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "BA";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP D";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xBB:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "BB";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP E";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xBC:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "BC";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xBD:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "BD";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP L";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xBE:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "BE";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xBF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "BF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xC0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RET NZ";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 20/8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "POP BC";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC2:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C2";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JP NZ,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16/12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC3:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C3";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JP $" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC4:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C4";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CALL NZ,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 24/12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "PUSH BC";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC6:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C6";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD A,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0xC7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RST 00H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RET Z";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 20/8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xC9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "C9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RET";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCA:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CA";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JP Z,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16/12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCC:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CC";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CALL Z,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 24/12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCD:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CD";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CALL $" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 24";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xCE:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CE";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADC A,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,H,C";
            }

            return str;
        }
        case 0xCF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "CF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RST 08H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD0:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D0";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RET NC";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 20/8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "POP DE";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD2:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D2";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JP NC,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16/12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD4:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D4";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CALL NC,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 24/12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "PUSH DE";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD6:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D6";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SUB $" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xD7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RST 10H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD8:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D8";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RET C";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 20/8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xD9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "D9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RETI";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDA:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "DA";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JP C,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16/12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDC:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "DC";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CALL C,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 24/12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xDE:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "DE";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "SBC A,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xDF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "DF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RST 18H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE0:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "E0";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LDH ($" + to_hex_string((u16)(0xff00 + b1)) + "),A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "E1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "POP HL";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "E2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD ($FF00+C),A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "E5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "PUSH HL";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE6:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "E6";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "AND $" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,1,0";
            }

            return str;
        }
        case 0xE7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "E7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RST 20H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xE8:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "E8";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "ADD SP,$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: 0,0,H,C";
            }

            return str;
        }
        case 0xE9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "E9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "JP (HL)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xEA:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "EA";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD ($" + to_hex_string(b1) + "),A";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xEE:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "EE";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "XOR $" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xEF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "EF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RST 28H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF0:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F0";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LDH A,($" + to_hex_string((u16)(0xff00 + b1)) + ")";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF1:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F1";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "POP AF";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,N,H,C";
            }

            return str;
        }
        case 0xF2:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F2";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,($FF00+C)";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF3:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F3";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "DI";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF5:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F5";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "PUSH AF";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF6:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F6";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "OR $" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,0,0,0";
            }

            return str;
        }
        case 0xF7:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F7";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RST 30H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xF8:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F8";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD HL,SP+$" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 12";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: 0,0,H,C";
            }

            return str;
        }
        case 0xF9:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "F9";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD SP,HL";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFA:
        {
            u16 b1 = read<u16>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "FA";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "LD A,($" + to_hex_string(b1) + ")";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFB:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "FB";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "EI";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 4";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }
        case 0xFE:
        {
            u8 b1 = read<u8>(it);
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "FE";
                str += " " + to_hex_string(b1, true);  // with spaces
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "CP $" + to_hex_string(b1) + "";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 8";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: Z,1,H,C";
            }

            return str;
        }
        case 0xFF:
        {
            std::string str;
            if(with_bytes) {
                str += "[";
                str += "FF";
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += "RST 38H";

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: 16";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " flags: -,-,-,-";
            }

            return str;
        }

        case 0xCB:
            return disas_prefix(it, with_bytes, with_timings, with_flags);
    }

    return "Unkown upcode " + to_hex_string(opcode);
}


