#include <iostream>

int main() {
    std::cout << "Enter a number: ";
    
    // use cin to get input, using ">>" extraction operator
    int x {}; // zero-initialise x
    std::cin >> x;

    std::cout << "You entered: " << x << '\n';

    // can get multiple inputs from the user
    std::cout << "Enter two numbers seperated by a space: ";

    int y {};
    std::cin >> x >> y;

    std::cout << "You entered " << x << " and " << y << '\n';

    return 0;
}
