#include <iostream>

// specify type of value returned by function
// this is specifically return-by-value
int get_value_from_user() {
    std::cout << "Enter an integer: ";
    
    int input {};
    std::cin >> input;

    return input;
}

int main() {
    int num {get_value_from_user()};

    std::cout << num << " doubled is " << num * 2 << '\n';

    return 0;
}
