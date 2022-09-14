#include <bitset>
#include <iostream>

// bits used as truth values are called bit flags
// can use an unsigned int of specific size (8, 16, 32, 64)
// or can use std::bitset
int main() {
    std::bitset<8> bits {0b0000'0101}; // 8 bits
    bits.set(3); // sets postition 3 to 1, 0000'1101
    bits.flip(4); // flips position 4 to opposite value, 0001'1101
    bits.reset(4); // sets position 4 to 0, 0000'1101

    std::cout << "All bits: " << bits << '\n';
    std::cout << "Bit 3: " << bits.test(3) << '\n';
    std::cout << "Bit 4: " << bits.test(4) << '\n';

    return 0;
}
