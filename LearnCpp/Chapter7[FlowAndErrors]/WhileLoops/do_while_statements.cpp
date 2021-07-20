#include <iostream>

// better to favour while loops for readability
int main() {
    int selection {};

    do { // always executed once
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }
    while (selection != 1 && selection != 2 &&
            selection != 3 && selection != 4);
    // only runs again while (condition) is true

    std::cout << "Selection option #" << selection << '\n';

    return 0;
}
