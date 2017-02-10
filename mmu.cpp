#ifdef DISAS_EVERYTHING
#define ENABLE_HISTORY
#endif

static std::map<u8, std::string> MBC_NAME = {
    { 0x00, "ROM ONLY" },
    { 0x01, "MBC1" },
    { 0x02, "MBC1+RAM" },
    { 0x03, "MBC1+RAM+BATTERY" },
    { 0x05, "MBC2" },
    { 0x06, "MBC2+BATTERY" },
    { 0x08, "ROM+RAM" },
    { 0x09, "ROM+RAM+BATTERY" },
    { 0x0B, "MMM01" },
    { 0x0C, "MMM01+RAM" },
    { 0x0D, "MMM01+RAM+BATTERY" },
    { 0x0F, "MBC3+TIMER+BATTERY" },
    { 0x10, "MBC3+TIMER+RAM+BATTERY" },
    { 0x11, "MBC3" },
    { 0x12, "MBC3+RAM" },
    { 0x13, "MBC3+RAM+BATTERY" },
    { 0x15, "MBC4" },
    { 0x16, "MBC4+RAM" },
    { 0x17, "MBC4+RAM+BATTERY" },
    { 0x19, "MBC5" },
    { 0x1A, "MBC5+RAM" },
    { 0x1B, "MBC5+RAM+BATTERY" },
    { 0x1C, "MBC5+RUMBLE" },
    { 0x1D, "MBC5+RUMBLE+RAM" },
    { 0x1E, "MBC5+RUMBLE+RAM+BATTERY" },
    { 0x20, "MBC6" },
    { 0x22, "MBC7+SENSOR+RUMBLE+RAM+BATTERY" },
    { 0xFC, "POCKET CAMERA" },
    { 0xFD, "BANDAI TAMA5" },
    { 0xFE, "HuC3" },
    { 0xFF, "HuC1+RAM+BATTERY" }
};

struct MMU {
    u8 mem[0x10000];
    std::vector<u8> boot_rom;
    std::vector<u8> rom;
    u8 mbc_type;
    u8 ibank = 1;
    std::string history;
    bool boot_rom_enabled = true;

    void init_mbc() {
        mbc_type = rom[0x147];
        std::cout << "Cartridge type: [" << to_hex_string(mbc_type) << "] "
                  << get_default(MBC_NAME, mbc_type, "UNKNOWN") << std::endl;

        switch(mbc_type) {
            case 0x00:
            case 0x01:
                ibank = 1;
                break;

            default:
                std::cout << "unimplemented MBC type" << std::endl;
                unreachable();
        }
    }

    u8 read(u16 addr, bool log_history=true) {
#ifdef ENABLE_HISTORY
        if(log_history)
            history += "read $" + to_hex_string(addr) + " = " + to_hex_string(mem[addr]) + "\n";
#endif

        if(boot_rom_enabled && addr < 0x100)
            return boot_rom[addr];


        if(addr <= 0x3fff) {
            return rom[addr];
        }

        if(addr <= 0x7fff) {
            /* std::cout << "from bank #" << ibank << std::endl; */
            u32 bank_start = addr-0x4000;
            return rom[bank_start + ((u16)ibank)*0x4000];
        }

        return mem[addr];
    };

    void write_error(u16 addr) {
        std::cout << "cannot write at " << to_hex_string(addr) << std::endl;
        unreachable();  // cannot write to rom
    }

    void write(u16 addr, u8 val, bool log_history=true) {
#ifdef ENABLE_HISTORY
        if(log_history)
            history += "write $" + to_hex_string(addr) + " = " + to_hex_string(val) + "\n";
#endif

        if(addr <= 0x7fff) {
            if(mbc_type != 0x01 || addr < 0x2000 || addr >= 0x6000) {
                write_error(addr);
            } else if(addr <= 0x3fff) {
                ibank = (ibank & 0xe0) + (val & 0x1f);  // keep 3 high bits, set the 5 low
            } else {
                ibank = (ibank & 0x1f) + (val & 0xe0);  // keep 5 low bits, set the 3 high
            }
        }

        if(addr == 0xff04) {  // DIV register
            val = 0;
            /* std::cout << "writing to div reg" << std::endl; */
        }

        if(addr == 0xff50) {  // disable boot rom
            boot_rom_enabled = false;
            std::cout << "boot rom disabled" << std::endl;
        }

        mem[addr] = val;

        if(addr == 0xff01)  // link port
            std::cerr << bold(std::string(1, val), true, "32") << std::flush;

        /* if(addr == 0xffff) std::cout << "setting IE to " << to_bit_string(val) << std::endl; */
        /* if(addr == 0xff0f) std::cout << "setting IF to " << to_bit_string(val) << std::endl; */
    };
};
