// fixed width ints guarentee size of object
#include <cstddef> // to get std::size_t
#include <cstdint>
#include <iostream>
/*
std::int8_t -> 1 B signed
std::uint8_t -> 1 B unsigned
... for 8, 16, 32, and 64 bits (1, 2, 4, 8 Bytes)

std::int8_t and std::uint8_t may act like chars
best to avoid fixed 8 bit ints

should be avoided as are less portable
*/

// std::int_fast#_t for fastest signed int type of at least # bits
// std::int_least#_t for smallest signed int type if at least # bits
// also has unsigned variants, but are guarenteed to be defined

int main() {
    std::cout << "fast 8: " << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
    std::cout << "fast 64: " << sizeof(std::int_fast64_t) * 8 << " bits\n\n";

    std::cout << "least 8: " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << "least 64: " << sizeof(std::int_least64_t) * 8 << " bits\n\n";

    std::int8_t myint {65};
    std::cout << "int8_t {65}: " << myint << '\n'; // prints 'A' not 65

    // sizeof and length return a value of type std::size_t
    // it is guarenteed to be unsigned and at least 16-bit
    std::cout << "size_t: " << sizeof(std::size_t) << '\n';

    return 0;
}
