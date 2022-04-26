#include <cstring> // for std::strcpy(), std::strlen()
#include <iostream>
#include <iterator> // for std::size()

// char arrays ending in a null terminator (\0)
// C-style strings have length one greater
// than number of letter due to terminator char

// act like arrays, cannot assign values to entire object
// need to use [] to assign individual chars

// overwriting the null terminator will cause
// std::cout to continue printing adjacent memory until it finds one

int main() {
    char my_string[] {"string"};
    const int length {static_cast<int>(std::size(my_string))};

    std::cout << my_string << " has " << length << " characters\n";

    for (int index {0}; index < length; ++index) {
        std::cout << static_cast<int>(my_string[index]) << ' ';
    }

    std::cout << '\n';

    // safe method to use std::cin with char arrays
    char name[255] {}; // array holds 254 chars + \0
    std::cout << "Enter your name: ";
    std::cin.getline(name, std::size(name));
    std::cout << "You entered: " << name << '\n';

    // can copy char arrays, can cause overflow if not careful
    char source[] {"Copy this!"};
    char dest[50] {};

    std::strcpy(dest, source);
    std::cout << dest << '\n';

    // can use strncpy() to specify buffer size, but is not null terminated
    // can use strcpy_s, but need to "#define __STDC_WANT_LIB_EXT1__ 1" to use
    // no universal solution for copying C-style strings

    // std::strlen() will return the length of the C-style string without \0
    char name_1[20] {"Jag"};
    std::cout << "My name is " << name_1 << '\n';
    std::cout << name_1 << " has " << std::strlen(name_1) << " letters\n";
    std::cout << name_1 << " has " 
                << std::size(name_1) << " characters in the array\n";

    return 0;
}
