#include <iostream>

int break_or_return() {
    while (true) {
        std::cout << "Enter 'b' to break, or 'r' to return: ";
        char ch {};
        std::cin >> ch;

        if (ch == 'b') {
            break; // exits the loop
        }

        if (ch == 'r') {
            return 1; // returns to where the function was called
        }
    }

    std::cout << "Loop broken\n";

    return 0;
}

int main() {
    int return_value {break_or_return()};
    std::cout << "Returned value = " << return_value << '\n';

    return 0;
}
