#include "util.cpp"
#include "autogen/disas.cpp"
#include "mmu.cpp"
#include "cpu.cpp"

i32 main() {
    CPU cpu;

    std::vector<i8> dmg_rom = slurp_file("roms/DMG_ROM.bin");
    std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/01-special.gb");
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/02-interrupts.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/03-op sp,hl.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/04-op r,imm.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/05-op rp.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/06-ld r,r.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/07-jr,jp,call,ret,rst.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/08-misc instrs.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/09-op r,r.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/10-bit ops.gb"); */
    /* std::vector<i8> rom = slurp_file("roms/cpu_instrs/individual/11-op a,(hl).gb"); */


    u32 pos = 0;
    for(i8 v: rom) {
        cpu.mmu.mem[pos++] = (u8)v;
    }
    pos = 0;
    for(i8 v: dmg_rom) {
        cpu.mmu.mem[pos++] = (u8)v;
    }

    cpu.reg.PC = 0x100;
    cpu.postboot_init();
    /* for(int i=0 ; i<10 ; i++) { */
    for(int i=0 ; i<1000000 ; i++) {
    /* while(cpu.reg.PC != 0x00E9) {  // blargg's 01 infinite loop */
    /* while(true) { */
        /* if(cpu.reg.PC == 0x00E9) cpu.reg.FZ = true; */
        /* if(cpu.reg.PC == 0x00FA) cpu.reg.FZ = true; */
        auto it = &cpu.mmu.mem[cpu.reg.PC];
        /* std::cout << disas(&it) << std::endl; */
        cpu.exec_op();
        /* cpu.reg.print(); */
        /* std::cout << "\n\n" << std::endl; */
    }
    /* while(it != dmg_rom.end()) */
    /*     std::cout << disas(&it) << std::endl; */
    return 0;
}
