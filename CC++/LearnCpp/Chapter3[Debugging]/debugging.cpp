#include <iostream>

int get_value() {
// std::cerr is unbuffered, use for debugging
std::cerr << "get_value() called\n";

    return 4;
}

int main() {
// debug statements unindented to easily find and remove
std::cerr << "main() called\n";
    
    std::cout << get_value();

    return 0;
}
