#include <iostream>

int main() {
    std::cout << "Enter your height (in cm): ";
    int x {};
    std::cin >> x;

    if (x >= 140) {
        std::cout << "You are tall enough to ride\n";
    }
    else { // blocks after if and else allow multiple true/false statements
        std::cout << "You are not tall enough to ride\n";
        std::cout << "Too bad\n";
    }

    return 0;
}
