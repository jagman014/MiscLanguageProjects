#include <cmath> // for std::pow
#include <cstdint> // for std::int_fast64_t
#include <iostream>

// exponent must be non-negative
std::int_fast64_t powint(int base, int exp) {
    std::int_fast64_t result {1};

    // while exp not zero
    while (exp) {
        // bitwise AND with 1
        if (exp & 1) {
            // multiply result by base
            result *= base;
        }
        // bitshift right by 1 place
        exp >>= 1;
        // double base exponent
        base *= base;
    }

    return result;
}

int main () {
    // return value and params are doubles
    // may result in errors in ints / whole numbers
    double x {std::pow(3.0, 4.0)};

    std::cout << "3 ** 4 = " << x << '\n';

    std::cout << "7 ** 12 = " << powint(7, 12) << '\n';

    return 0;
}
