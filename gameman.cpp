/* #define DISAS_EVERYTHING */

#include "util.cpp"
#include "graphics.cpp"
#include "mmu.cpp"
#include "ppu.cpp"
#include "cpu.cpp"

static i32 total_instr_count = 0;

template<typename MBC>
void emulate_with_(std::vector<u8> rom) {
    CPU<MBC> cpu;

    std::vector<i8> dmg_rom = slurp_file("roms/DMG_ROM.bin");

    for(i8 v: dmg_rom) cpu.mmu.boot_rom.push_back((u8)v);
    cpu.mmu.insert_cartridge(rom);

    std::cout << "\nEXECUTION:" << std::endl;

    /* bool log = false; */
    bool log = true;
    cpu.reg.PC = 0xfe;  // skip boot rom
    i32 c = 0;
    /* for(int i=0 ; i<100 ; i++) { */
    /* for(int i=0 ; i<1000 ; i++) { */
    /* for(int i=0 ; i<10000 ; i++) { */
    /* for(int i=0 ; i<100000 ; i++) { */
    /* for(int i=0 ; i<1000000 ; i++) { */
    /* while(cpu.reg.PC != 0x00E9) {  // blargg's 01 infinite loop */
    auto tstart = now();
    i32 last_cycles = 0;
    while(true) {
        /* std::cout << "plop" << std::endl; */

        /* if(cpu.reg.PC == 0xff) break; */
        c++;
        u16 old_pc = cpu.reg.PC;
#ifdef DISAS_EVERYTHING
        if(log) std::cout << "#" << c << " " << cpu.disas() << std::endl;
        cpu.reg.PC = old_pc;
        Registers old_regs = cpu.reg;
#endif

        cpu.mmu.history = "";
        last_cycles += cpu.do_cycle();

        if(tdiff_micro(tstart, now()) > 1000000) {
            std::cout.imbue(std::locale(""));
            std::cout << "last second: " << last_cycles << " ops" << std::endl;
            tstart = now();
            last_cycles = 0;
        }

        if(cpu.reg.PC == 0x40) {
            /* std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl; */
            log = true;
        }

        /* if(old_pc == cpu.reg.PC && !cpu.halted) { */
        /*     std::cout << "\nINFINITE LOOP (after " << c << " instructions)" << std::endl; */
        /*     break; */
        /* } */

#ifdef DISAS_EVERYTHING
        if(log) {
            cpu.print_reg_diff(old_regs);
            if(cpu.mmu.history != "") std::cout << cpu.mmu.history << std::flush;
            std::cout << std::string(142, '#') << "\n" <<  std::endl;
        }
#endif
    }
    /* while(it != dmg_rom.end()) */
    /*     std::cout << disas(&it) << std::endl; */

    std::cout << std::string(30, '~') << "\n" << std::endl;
    total_instr_count += c;
}


void emulate(std::string rom_path) {
    std::cout << std::string(10, '=') << " " << basename(rom_path) << " " << std::string(10, '=') << std::endl;

    std::vector<i8> irom = slurp_file(rom_path);
    std::vector<u8> rom;
    for(i8 v: irom)
        rom.push_back((u8)v);

    std::cout << "Cartridge type: [" << to_hex_string(rom[0x147]) << "] "
              << get_default(MBC_NAME, rom[0x147], "UNKNOWN") << std::endl;

    switch(rom[0x147]) {
        case 0x00:
            emulate_with_<ROM_ONLY>(rom);
            break;
        case 0x01:
            emulate_with_<MBC1>(rom);
            break;
        case 0x03:
            emulate_with_<MBC1_RAM_BATTERY>(rom);
            break;
        /* case 0x13: */
        /*     emulate_with_<MBC3_RAM_BATTERY>(rom); */
        /*     break; */

        default:
            std::cout << "unimplemented MBC type" << std::endl;
            unreachable();
    }
}


i32 main() {
    the_ghandler.init();

    /* emulate("./roms/cpu_instrs/cpu_instrs.gb"); */
    /* emulate("./roms/instr_timing/instr_timing.gb"); */
    /* emulate("./roms/mem_timing/mem_timing.gb"); */
    /* emulate("./roms/mem_timing/individual/01-read_timing.gb"); */
    /* emulate("./roms/mem_timing/individual/02-write_timing.gb"); */
    /* emulate("./roms/mem_timing/individual/03-modify_timing.gb"); */
    /* emulate("./roms/mem_timing-2/mem_timing.gb"); */
    /* emulate("./roms/mem_timing-2/rom_singles/01-read_timing.gb"); */
    /* emulate("./roms/mem_timing-2/rom_singles/02-write_timing.gb"); */
    /* emulate("./roms/mem_timing-2/rom_singles/03-modify_timing.gb"); */

    emulate("./tetris.gb");
    /* emulate("./sml.gb"); */
    /* emulate("./sml2.gb"); */
    /* emulate("./pokemon_red.gb"); */

    /* emulate("roms/cpu_instrs/individual/01-special.gb"); */
    /* emulate("roms/cpu_instrs/individual/02-interrupts.gb"); */
    /* emulate("roms/cpu_instrs/individual/03-op sp,hl.gb"); */
    /* emulate("roms/cpu_instrs/individual/04-op r,imm.gb"); */
    /* emulate("roms/cpu_instrs/individual/05-op rp.gb"); */
    /* emulate("roms/cpu_instrs/individual/06-ld r,r.gb"); */
    /* emulate("roms/cpu_instrs/individual/07-jr,jp,call,ret,rst.gb"); */
    /* emulate("roms/cpu_instrs/individual/08-misc instrs.gb"); */
    /* emulate("roms/cpu_instrs/individual/09-op r,r.gb"); */
    /* emulate("roms/cpu_instrs/individual/10-bit ops.gb"); */
    /* emulate("roms/cpu_instrs/individual/11-op a,(hl).gb"); */

    std::cout << "total instr count: " << total_instr_count << std::endl;

    return 0;
}
