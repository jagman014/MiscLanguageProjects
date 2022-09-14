#include <iostream>

int main() {
    // print on the same line, use std::endl to move cursor to next line
    std::cout << "Hi" << std::endl;
    std::cout << "Hello" << std::endl;

    // easier to just add "\n" as cout flushes output anyway
    int x {5};
    std::cout << "x is equal to " << x << '\n';
    std::cout << "that's all \n";

    return 0;
}
