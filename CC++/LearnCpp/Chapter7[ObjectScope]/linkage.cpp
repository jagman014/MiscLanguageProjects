#include <iostream>

// non-constant globals have external linkage by default
// external linkage -> global over all files
// internal linkage -> locally global
int g_w;
static int g_x; // static sets non-const global to internal linkage

// const and constexp globals have internal linkage by default
const int g_y {1};
constexpr int g_z {2};

// can make constant globals external using extern
// extern variables from other files must be forward declared
// in a similar manor to functions, but uninitialised
extern const int g_a {3};

// cannot forward declare constexpr
// using extern on non-constant globals is only as a forward declaration

// functions are external by default
// can define a static function, this won't be able to be shared between files
static void foo() {
    std::cout << "";
}

int main() {
    return 0;
}
