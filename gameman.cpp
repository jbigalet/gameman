/* #define DISAS_EVERYTHING */

#include "util.cpp"
#include "mmu.cpp"
#include "cpu.cpp"

i32 main() {
    CPU cpu;

    std::vector<i8> dmg_rom = slurp_file("roms/DMG_ROM.bin");
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/cpu_instrs.gb"); */

    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/01-special.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/03-op sp,hl.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/04-op r,imm.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/05-op rp.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/06-ld r,r.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/07-jr,jp,call,ret,rst.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/08-misc instrs.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/09-op r,r.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/10-bit ops.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/11-op a,(hl).gb"); */

    std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/02-interrupts.gb");


    for(i8 v: dmg_rom) cpu.mmu.boot_rom.push_back((u8)v);
    for(i8 v: rom)     cpu.mmu.rom.push_back((u8)v);

    std::cout << "cartridge type: " << to_hex_string(cpu.mmu.rom[0x147]) << std::endl;

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
#ifdef DISAS_EVERYTHING
        u16 old_pc = cpu.reg.PC;
        std::cout << "#" << c << " " << cpu.disas() << std::endl;
        cpu.reg.PC = old_pc;
        Registers old_regs = cpu.reg;
#endif

        cpu.mmu.history = "";
        cpu.exec_op();

#ifdef DISAS_EVERYTHING
        cpu.print_reg_diff(old_regs);
        if(cpu.mmu.history != "") std::cout << cpu.mmu.history << std::flush;
        std::cout << "##############################################################################################################################################\n" <<  std::endl;
#endif
    }
    /* while(it != dmg_rom.end()) */
    /*     std::cout << disas(&it) << std::endl; */
    return 0;
}
