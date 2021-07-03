#include <iostream>
/*
Unary: -x, negation
        +x, value
Binary: x + y, addition
        x - y, subtraction
        x * y, multiplication
        x / y, division
        x % y, modulus
All binary operators can be combined with assignment, i.e. +=
*/

int main() {
    int x {7};
    int y {4};

    // division of ints results in quotient being returned
    std::cout << "int / int = " << x / y << '\n';
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
    std::cout << "double / double = " 
                 << static_cast<double>(x) / static_cast<double>(y) << "\n\n";
    
    // division by zero results in an error
    std::cout << "Enter a divisor: ";
    int z {};
    std::cin >> z;

    std::cout << "12 / " << z << " = " << 12 / z << '\n';

    return 0;
}
