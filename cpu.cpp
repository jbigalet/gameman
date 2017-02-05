#define DOUBLE_REG(a, b) \
    union {              \
        struct {         \
            u8 b;        \
            u8 a;        \
        };               \
        u16 a##b;        \
    }

struct Registers {
    DOUBLE_REG(A, F);
    DOUBLE_REG(B, C);
    DOUBLE_REG(D, E);
    DOUBLE_REG(H, L);
    u16 SP;
    u16 PC;
};

struct Flags {
    bool Z, N, H, C;
};

struct Cpu {
    Registers reg;
    Flags flag;
    // TODO mem;

#include "cpu_prototypes.cpp"
#include "cpu_dispatcher.cpp"
};

