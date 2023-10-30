#include <iostream>

// same named functions with a different set of params
// can be a different number or different type of param
// type aliases are not unique, therefore aren't distinct for overloading

int add(int x, int y) { // integer version
    return x + y;
}

double add(double x, double y) { // floating point version
    return x + y;
}

int add(int x, int y, int z) { // multiple params
    return x + y + z;
}

// depending on types of arguments in function call
// can result in ambiguity between overloaded functions
// resolve ambiguity with another overloaded function, static cast, or literal

int main() {
    std::cout << add(3, 5); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(3.2, 5.7); // calls add(double, double)

    return 0;
}
