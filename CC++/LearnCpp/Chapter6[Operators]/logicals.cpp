#include <iostream>

/*
!, not -> prefix operator, !x
&&, and -> binary operator, x && y
||, or -> binary operator, x || y
*/
// logical and / or can "short circuit" if value of first false / true
// any assignment evaluations after this won't occur
int main() {
    int x {5};
    int y {7};

    // logical not has president over comparitors
    // best to negate expression in brackets
    if (!(x > y)) {
        std::cout << x << " is not greater than " << y << '\n';
    }
    else {
        std::cout << x << " is greater than " << y << "\n\n";
    }

    std::cout << "Enter an integer: ";
    int value {};
    std::cin >> value;

    if (value == 0 || value == 1) {
        std::cout << "You entered 0 or 1\n\n";
    }
    else {
        std::cout << "You didn't enter 0 or 1\n\n";
    }

    std::cout << "Enter an integer: ";
    int val {};
    std::cin >> val;

    if (val > 10 && val < 20) {
        std::cout << "Your number is between 10 and 20\n";
    }
    else {
        std::cout << "Your number is not between 10 and 20\n";
    }

    // combining operators should be in brackets to show explicit relation

    return 0;
}
