#include <iostream>
// blocks allow for multiple statements to be executes as a single statment
// example -> if statements can only execute one line,
// if blocks allow multiple lines to be executed given a condition

int main() { // start of main block
    std::cout << "Enter an integer: ";
    int val {};
    std::cin >> val;

    if (val >= 0) { // start of inner if block
        std::cout << val << " is a positive integer (or zero)\n";
        std::cout << "Double this number is " << val * 2 << '\n';
    } // end of if block
    else { // start of inner else block
        std::cout << val << " is a negative number\n";
        std::cout << "The positive of this is " << -val << '\n';
    } // end of else block

    return 0;
} // end of main block
