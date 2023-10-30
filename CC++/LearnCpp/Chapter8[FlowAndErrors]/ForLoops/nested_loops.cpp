#include <iostream>

int main() {
    for (char c {'a'}; c <= 'e'; ++c) { // outer loop on letters
        std::cout << c;

        for (int i {0}; i < 3; ++i) {// inner loop on integers
            std::cout << i;
        }
        
        std::cout << '\n';
    }

    return 0;
}
