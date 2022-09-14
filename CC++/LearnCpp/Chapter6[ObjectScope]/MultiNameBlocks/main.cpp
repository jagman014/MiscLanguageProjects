#include "add.h" // for basic_maths::add
#include "circle.h" // for basic_maths::pi
#include "growth.h" // for basic_maths::e
#include <iostream>

int main() {
    std::cout << basic_maths::pi << '\n';
    std::cout << basic_maths::e << '\n';
    std::cout << basic_maths::add(4, 3) << '\n';

    return 0;
}
