#ifdef DISAS_EVERYTHING
#define ENABLE_HISTORY
#endif

#define _IF         0xFF0F
#define _IE         0xFFFF

#define _VRAM_START 0x8000
#define _VRAM_END   0x9FFF
#define _OAM_START  0xFE00
#define _OAM_END    0xFE9F

#define _LCDC       0xFF40
#define _STAT       0xFF41
#define _SCY        0xFF42
#define _SCX        0xFF43
#define _LY         0xFF44
#define _LYC        0xFF45
#define _WY         0xFF4A
#define _WX         0xFF4B


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

struct MBC_base {
    u8 mem[0x10000];
    std::vector<u8> rom;
    std::vector<u8> ram;

    MBC_base() {
        for(i32 i=0 ; i<0x10000 ; i++)
            mem[i] = 0;
    }

    void set_ram_size(u32 ram_size) {
        ram.resize(ram_size, 0x00);
    }
};


struct ROM_ONLY : MBC_base {
    u8 read(u16 addr) {
        if(addr <= 0x7fff)
            return rom[addr];

        return mem[addr];
    }

    void write(u16 addr, u8 val) {
        if(addr <= 0x7fff)
            return;

        mem[addr] = val;
    }
};


struct MBC1 : MBC_base {
    u8 ibank = 1;
    u8 iram = 0;
    bool ram_enabled = false;
    bool ram_banking_mode = false;  // as opposed to rom_banking_mode

    u8 read(u16 addr) {
        // TODO doc
        if(addr <= 0x3fff)  // rom bank 0
            return rom[addr];

        if(addr <= 0x7fff) {  // rom bank n
            /* std::cout << "from bank #" << ibank << std::endl; */
            u32 bank_offset = addr-0x4000;
            u32 idx = bank_offset + ((u16)ibank)*0x4000;
            check(idx >= 0 && idx < rom.size());
            return rom[idx];
        }

        if(addr >= 0xA000 && addr <= 0xBFFF) {
            if(ram_enabled) {
                /* std::cout << "from rank bank #" << iram << std::endl; */
                u32 bank_offset = addr-0xA000;
                u32 idx = bank_offset + ((u16)iram)*0x2000;
                check(idx >= 0 && idx < ram.size());
                return ram[idx];
            }

            return 0x00;
        }

        return mem[addr];
    }

    void write(u16 addr, u8 val) {
        // TODO doc
        if(addr <= 0x1fff) {
            ram_enabled = (val & 0x0f) == 0x0a;
            std::cout << "ram enabled: " << ram_enabled << std::endl;
        } else if(addr <= 0x3fff) {
            if(val == 0x00) val = 0x01;
            ibank = (ibank & 0xE0) + (val & 0x1f);  // keep 3 high bits, set the 5 low
        } else if(addr <= 0x5fff) {
            if(ram_banking_mode) {
                std::cout << "changing ram bank to #" << (u32)val << std::endl;
                iram = val;
            } else {
                ibank = (ibank & 0x1f) + (val & 0xe0);  // keep 5 low bits, set the 3 high
            }
        } else if(addr <= 0x7fff) {
            check(val <= 0x01);
            ram_banking_mode = val == 0x01;
        } else if(addr >= 0xA000 && addr <= 0xBFFF) {
            if(ram_enabled) {
                u32 bank_offset = addr-0xA000;
                u32 idx = bank_offset + ((u16)iram)*0x2000;
                check(idx >= 0 && idx < ram.size());
                ram[idx] = val;
            }
        } else {
            mem[addr] = val;
        }
    }
};

struct MBC1_RAM_BATTERY : MBC1 {};




template<typename MBC>
struct MMU {
    MBC mbc;

    std::string history;
    std::vector<u8> boot_rom;
    bool boot_rom_enabled = true;

    bool can_access_vram = true;
    bool can_access_oam = true;

    void insert_cartridge(std::vector<u8> rom) {
        mbc.rom = rom;

        std::cout << "HEADER:" << std::endl;

        u32 rom_size;
        u8 rom_size_byte = mbc.rom[0x148];
        if(rom_size_byte <= 0x08) {
            rom_size = 32000 << rom_size_byte;
        } else {
            switch(rom_size_byte) {
                case 0x52:
                    rom_size = 1152000;
                    break;
                case 0x53:
                    rom_size = 1280000;
                    break;
                case 0x54:
                    rom_size = 1536000;
                    break;
                default:
                    std::cout << "unknown rom size byte: " << to_hex_string(rom_size_byte) << std::endl;
                    unreachable();
                    rom_size = 0;
            }
        }
        std::cout << "ROM size: " << rom_size;
        std::cout << " (" << (rom_size/16000) << " banks)" << std::endl;

        u32 ram_size;
        u8 ram_size_byte = mbc.rom[0x149];
        switch(ram_size_byte) {
            case 0x00:
                ram_size = 0;
                break;
            case 0x01:
                ram_size = 1 << 11;  // ~2k
                break;
            case 0x02:
                ram_size = 1 << 13;  // ~8k
                break;
            case 0x03:
                ram_size = 1 << 15;  // ~32k
                break;
            case 0x04:
                ram_size = 1 << 17;  // ~128k
                break;
            case 0x05:
                ram_size = 1 << 16;  // ~64k
                break;
            default:
                std::cout << "unknown ram size byte: " << to_hex_string(ram_size_byte) << std::endl;
                unreachable();
                ram_size = 0;
        }
        std::cout << "RAM size: " << ram_size;
        std::cout << " (" << (ram_size/8000) << " banks)" << std::endl;
        mbc.set_ram_size(ram_size);
    }

    void postboot_init() {
        mbc.mem[0xFF05] = 0x00;   // TIMA
        mbc.mem[0xFF06] = 0x00;   // TMA
        mbc.mem[0xFF07] = 0x00;   // TAC
        mbc.mem[0xFF10] = 0x80;   // NR10
        mbc.mem[0xFF11] = 0xBF;   // NR11
        mbc.mem[0xFF12] = 0xF3;   // NR12
        mbc.mem[0xFF14] = 0xBF;   // NR14
        mbc.mem[0xFF16] = 0x3F;   // NR21
        mbc.mem[0xFF17] = 0x00;   // NR22
        mbc.mem[0xFF19] = 0xBF;   // NR24
        mbc.mem[0xFF1A] = 0x7F;   // NR30
        mbc.mem[0xFF1B] = 0xFF;   // NR31
        mbc.mem[0xFF1C] = 0x9F;   // NR32
        mbc.mem[0xFF1E] = 0xBF;   // NR33
        mbc.mem[0xFF20] = 0xFF;   // NR41
        mbc.mem[0xFF21] = 0x00;   // NR42
        mbc.mem[0xFF22] = 0x00;   // NR43
        mbc.mem[0xFF23] = 0xBF;   // NR30
        mbc.mem[0xFF24] = 0x77;   // NR50
        mbc.mem[0xFF25] = 0xF3;   // NR51
        mbc.mem[0xFF26] = 0xF1;   // NR52  for GB, 0xF0 for SGB
        mbc.mem[0xFF40] = 0x91;   // LCDC
        mbc.mem[0xFF42] = 0x00;   // SCY
        mbc.mem[0xFF43] = 0x00;   // SCX
        mbc.mem[0xFF45] = 0x00;   // LYC
        mbc.mem[0xFF47] = 0xFC;   // BGP
        mbc.mem[0xFF48] = 0xFF;   // OBP0
        mbc.mem[0xFF49] = 0xFF;   // OBP1
        mbc.mem[0xFF4A] = 0x00;   // WY
        mbc.mem[0xFF4B] = 0x00;   // WX
        mbc.mem[0xFFFF] = 0x00;   // IE
    }

    u8 read(u16 addr, bool log_history=true) {
        u8 res;

        if(boot_rom_enabled && addr < 0x100) {
            res = boot_rom[addr];
        } else if(addr >= _VRAM_START && addr <= _VRAM_END) {
            res = can_access_vram ? mbc.read(addr) : 0;
        } else if(addr >= _OAM_START && addr <= _OAM_END) {
            res = can_access_oam ? mbc.read(addr) : 0;
        } else {
            res = mbc.read(addr);
        }

#ifdef ENABLE_HISTORY
        if(log_history)
            history += "read $" + to_hex_string(addr)
                       + " = " + to_hex_string(res) + "\n";
#endif

        return res;
    };

    void write(u16 addr, u8 val, bool log_history=true) {
#ifdef ENABLE_HISTORY
        if(log_history)
            history += "write $" + to_hex_string(addr) + " = " + to_hex_string(val) + "\n";
#endif

        if(addr == 0xff50) {  // disable boot rom
            std::cout << "boot rom disabled" << std::endl;
            boot_rom_enabled = false;
            mbc.mem[addr] = val;
            postboot_init();
            return;
        }

        if(addr == 0xff01) {  // link port
            std::cerr << bold(std::string(1, val), true, "32") << std::flush;
            mbc.mem[addr] = val;
            return;
        }

        if(addr == _LCDC) {
            /* std::cout << "LCDC is now " << to_bit_string(val) << std::endl; */
        }

        if(!can_access_vram && addr >= _VRAM_START && addr <= _VRAM_END) {
            std::cout << "trying to write in vram at " << to_hex_string(addr) << std::endl;
            return;
        }

        if(!can_access_oam && addr >= _OAM_START && addr <= _OAM_END) {
            std::cout << "trying to write in oam at " << to_hex_string(addr) << std::endl;
            return;
        }

        mbc.write(addr, val);
    };

    void set_bit(u16 addr, u8 bit) {
        write(addr, bit_set(read(addr), bit));
    }
};
