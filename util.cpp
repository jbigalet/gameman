#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>

typedef char           i8;
typedef unsigned char  u8;
typedef short          i16;
typedef unsigned short u16;
typedef int            i32;
typedef unsigned int   u32;
typedef long           i64;
typedef unsigned long  u64;
typedef float          f32;
typedef double         f64;


static inline void assert_impl(bool cond, const i8 *expr, const i8 *file, int line) {
    if (!cond) {
        fprintf(stderr, "assertion failed : %s\n", expr);
        fprintf(stderr, "at %s:%d\n", file, line);
        exit(1);
    }
}
#define check(c) assert_impl((c), #c, __FILE__, __LINE__)
#define assert check
#define unreachable() { check(false && "unreachable"); __builtin_unreachable(); }


template<typename T>
std::string to_hex_string(T i, bool with_spaces=false, bool with_sign=false) {
    std::stringstream stream;
    std::string str;

    if(with_sign) {
        if(i<0) {
            str += "-$";
            i = -i;
        } else {
            str += "+$";
        }
    }

    i32 n = i;
    stream << std::uppercase << std::hex << n;
    std::string s = stream.str();

    // padding + remove lead FF for negative numbers
    i8 str_size = 2*sizeof(i);
    if(s.size() > str_size)
        s = s.substr(s.size()-str_size);
    else
        while(s.size() < str_size)
            s = "0" + s;

    // spaces
    if(with_spaces)
        for(i8 pos=2 ; pos<str_size ; pos+=2)
            s.insert(str_size-pos, " ");

    str += s;
    return str;
}


static std::vector<i8> slurp_file(std::string name) {
    std::ifstream file(name, std::ios::binary | std::ios::ate);
    check((bool)file);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<i8> buffer(size);
    check((bool)file.read(buffer.data(), size));
    file.close();
    return buffer;
}

template<typename T>
T read(std::vector<i8>::iterator* it) {
    T v = *(T*)(&**it);
    (*it) += sizeof(T);
    return v;
}
