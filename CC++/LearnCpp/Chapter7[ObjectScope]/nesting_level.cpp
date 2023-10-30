#include <iostream>
// c++ nesting limit of 256
// best to keep nested blocks to max 3 levels

int main() { // block 1, level 1
    std::cout << "Enter an integer: ";
    int val {};
    std::cin >> val;

    if (val > 0) { // block 2, level 2
        if (val % 2 == 0) { // block 3, level 3
            std::cout << val << " is positive and even\n";
        }
        else { // block 4, level 3
            std::cout << val << " is positive and odd\n";
        }
    }

    return 0;
}
