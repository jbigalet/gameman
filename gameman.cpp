/* #define DISAS_EVERYTHING */

#include "util.cpp"
#include "mmu.cpp"
#include "cpu.cpp"

static i32 total_instr_count = 0;

void emulate(std::string rom_path) {
    std::cout << std::string(10, '=') << " " << basename(rom_path) << " " << std::string(10, '=') << std::endl;

    CPU cpu;

    std::vector<i8> dmg_rom = slurp_file("roms/DMG_ROM.bin");
    std::vector<i8> rom = slurp_file(rom_path);

    for(i8 v: dmg_rom) cpu.mmu.boot_rom.push_back((u8)v);
    for(i8 v: rom)     cpu.mmu.rom.push_back((u8)v);

    std::cout << "HEADER:" << std::endl;
    cpu.mmu.init_mbc();
    std::cout << "\nEXECUTION:" << std::endl;

    bool log = false;
    cpu.reg.PC = 0x100;
    cpu.postboot_init();
    i32 c = 0;
    /* for(int i=0 ; i<100 ; i++) { */
    /* for(int i=0 ; i<1000 ; i++) { */
    /* for(int i=0 ; i<10000 ; i++) { */
    /* for(int i=0 ; i<100000 ; i++) { */
    /* for(int i=0 ; i<1000000 ; i++) { */
    /* while(cpu.reg.PC != 0x00E9) {  // blargg's 01 infinite loop */
    while(true) {
        if(cpu.reg.PC == 0xff) break;
        c++;
        u16 old_pc = cpu.reg.PC;
#ifdef DISAS_EVERYTHING
        if(log) std::cout << "#" << c << " " << cpu.disas() << std::endl;
        cpu.reg.PC = old_pc;
        Registers old_regs = cpu.reg;
#endif

        cpu.mmu.history = "";
        cpu.do_cycle();
        if(cpu.reg.PC == 0x40) {
            /* std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl; */
            log = true;
        }

        if(old_pc == cpu.reg.PC) {
            std::cout << "\nINFINITE LOOP (after " << c << " instructions)" << std::endl;
            break;
        }

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


i32 main() {
    /* emulate("roms/cpu_instrs/cpu_instrs.gb"); */

    /* emulate("roms/cpu_instrs/individual/01-special.gb"); */
    /* emulate("roms/cpu_instrs/individual/03-op sp,hl.gb"); */
    /* emulate("roms/cpu_instrs/individual/04-op r,imm.gb"); */
    /* emulate("roms/cpu_instrs/individual/05-op rp.gb"); */
    /* emulate("roms/cpu_instrs/individual/06-ld r,r.gb"); */
    /* emulate("roms/cpu_instrs/individual/07-jr,jp,call,ret,rst.gb"); */
    /* emulate("roms/cpu_instrs/individual/08-misc instrs.gb"); */
    /* emulate("roms/cpu_instrs/individual/09-op r,r.gb"); */
    /* emulate("roms/cpu_instrs/individual/10-bit ops.gb"); */
    /* emulate("roms/cpu_instrs/individual/11-op a,(hl).gb"); */

    emulate("roms/cpu_instrs/individual/02-interrupts.gb");

    std::cout << "total instr count: " << total_instr_count << std::endl;

    return 0;
}
