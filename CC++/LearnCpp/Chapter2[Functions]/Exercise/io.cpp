#include "io.h"
#include <iostream>

// returns the number from user input
int get_number() {
    std::cout << "Enter a number: ";
    
    int x {};
    std::cin >> x;

    return x;
}

// prints x to the console
void write_answer(int x) {
    std::cout << "The answer is " << x << '\n';
}
