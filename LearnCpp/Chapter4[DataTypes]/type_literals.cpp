#include <bitset> // for std::bitset
#include <iostream>

// literal constants
int x {4}; // literal int
bool is_true {true}; // literal bool
double y {3.2}; // literal double
char ch {'a'}; // literal char
const char str[14] {"Hello, world!"}; // literal C-style string

// literals have defined suffixes as well
/*
int: u -> unsigned -> 5u
int: l -> long -> 5l
int: ul -> unsinged long -> 5ul
int: ll -> long long -> 5ll
int: ull -> unsinged long long -> 5ull
double: f -> float -> 5.0f
double: l -> long double -> 5.0l
*/

// scientific literals
double avagadro {6.02e23};
double electron {1.6e-19};

// octal and hexadecimal literals
int z {012}; // initial 0 means octal -> 10
int a {0xF}; // initial 0x means hexadecimal -> 15

// binary literals, C++14
int b {0b1}; // inital 0b means binary

// can separate long literals with '
int c {1'000'000};

int main() {
    int x {12};
    std::cout << x << '\n'; // default decimal
    std::cout << std::hex << x << '\n'; // hexadecimal
    std::cout << std::oct << x << '\n'; // octal
    std::cout << std::dec << x << "\n\n"; // back to decimal

    // printing binary literals
    std::bitset<8> bin1 {0b1100'0101}; // binary literal
    std::bitset<8> bin2 {0xC5}; // hexadecimal literal

    std::cout << bin1 << ' ' << bin2 << '\n';
    std::cout << std::bitset<4> {0b1010} << '\n'; // direct bitset print

    return 0;
}
