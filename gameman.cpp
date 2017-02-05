#include "util.cpp"
#include "disas.cpp"
#include "cpu.cpp"

i32 main() {
    std::vector<i8> dmg_rom = slurp_file("DMG_ROM.bin");
    auto it = dmg_rom.begin();
    while(it != dmg_rom.end())
        std::cout << disas(&it) << std::endl;
    return 0;
}
