#include <iostream>

// smaller bit values are promoted to a larger type
// for a larger performance boost without a loss of precision 
// all promotions preserve values, but not necessarily signs

void print_int(int x) {
    // numeric promotion allows this function to be used with
    // short, unsigned, char, and anything able to be promoted to int
    std::cout << x << '\n';
}

void print_double(double d) {
    // similar premise as print_int()
    // can be used with anything that can be promoted to double
    std::cout << d << '\n';
}

int main() {
    // floating point promotions
    print_double(4.0); // no conversion 
    print_double(4.0f); // numeric promotion from float to double

    // integral promotions
    print_int(2);

    // unsigned versions can be promoted, only if they will fit in int
    short s {3}; // no short literal
    print_int(s); // short promoted to int

    print_int('a'); // char promoted to int, prints int value of char i.e. 97
    print_int(true); // bool promoted to int

    return 0;
}
