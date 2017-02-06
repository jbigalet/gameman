struct MMU {
    u8 mem[0x10000];

    u8 read(u16 addr) {
        return mem[addr];
    };

    void write(u16 addr, u8 val) {
        mem[addr] = val;

        if(addr == 0xff01)  // link port
            std::cerr << val << std::flush;
    };
};
