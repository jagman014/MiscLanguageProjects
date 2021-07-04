#include <cstdint>
#include <iostream>

int main() {
    // set of bit masks, for bit maniuplation without std::bitset
    // can substitute for std::bitset and use bitwise for multiple changes
    // instead of just the .set, .reset, .flip, .test
    // naming the masks can give an insight into what each bit means
    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2
    /* 
    constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7
    */
    
    std::uint_fast8_t flags {0b0000'0101};

    // check if bit is on or off
    std::cout << "Bit 0 is " << ((flags & mask0) ? "on\n\n" : "off\n\n");
    std::cout << "Bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    // setting a bit, turning it on
    // using bitwise or, can set multiple bits with |= (maskn | maskm)
    std::cout << "Set bit 1\n";
    flags |= mask1;
    std::cout << "Bit 1 is " << ((flags & mask1) ? "on\n\n" : "off\n\n");

    // resetting a bit, turning it off
    // using bitwise and with not, multiple with &= ~(maskn | maskm)
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    std::cout << "Reset bit 2\n";
    flags &= ~mask2;
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n\n" : "off\n\n");

    // flipping a bit
    // using bitwise xor, multiple with ^= (maskn | maskm)
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    std::cout << "Flip bit 2\n";
    flags ^= mask2;
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    std::cout << "Flip bit 2\n";
    flags ^= mask2;
    std::cout << "Bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    // can combine with .any() method on bitsets to return true
    // for unsigned ints, need to static cast to bool

    return 0;
}
