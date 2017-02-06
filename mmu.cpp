/* #define DISABLE_HISTORY */

struct MMU {
    u8 mem[0x10000];
    std::vector<u8> boot_rom;
    std::vector<u8> rom;
    u16 ibank = 1;

    std::string history;

    u8 read(u16 addr, bool log_history=true) {
#ifndef DISABLE_HISTORY
        if(log_history)
            history += "read $" + to_hex_string(addr) + " = " + to_hex_string(mem[addr]) + "\n";
#endif

        if(addr <= 0x3fff) {
            return rom[addr];
        }

        if(addr <= 0x7fff) {
            /* std::cout << "from bank #" << ibank << std::endl; */
            u32 bank_start = addr-0x4000;
            return rom[bank_start + ibank*0x4000];
        }

        return mem[addr];
    };

    void write(u16 addr, u8 val, bool log_history=true) {
#ifndef DISABLE_HISTORY
        if(log_history)
            history += "write $" + to_hex_string(addr) + " = " + to_hex_string(val) + "\n";
#endif

        if(addr <= 0x7fff) {
            std::cout << "cannot write at " << to_hex_string(addr) << std::endl;
            unreachable();  // cannot write to rom
        }

        mem[addr] = val;

        if(addr == 0xff01)  // link port
            std::cerr << val << std::flush;
    };
};
