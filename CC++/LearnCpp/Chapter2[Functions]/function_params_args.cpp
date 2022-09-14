#include <iostream>

int get_user_value() {
    std::cout << "Enter an integer: ";

    int input {};
    std::cin >> input;

    return input;
}

// takes in an integer as a parameter
void print_double(int value) {
    std::cout << value << " doubled is " << value * 2 << '\n';
}

int main() {
    int num {get_user_value()};

    // after num is initialised it is then passed as an argument
    // this is pass-by-value
    print_double(num);

    return 0;
}
