#include <iostream>
// bool values of true and false

bool b1 {true};
bool b2 {false};
bool b3 {}; // default init to false

// can have bool return functions via comparitors
bool is_equal(int x, int y) {
    return (x == y);
}

// bools print to either 1 or 0
int main() {
    std::cout << true << '\n'; // evals to 1
    std::cout << !true << '\n'; // evals to 0, ! -> not

    std::cout << b2 << '\n'; // evals to 0
    std::cout << !b2 << "\n\n"; // evals to 1

    // can get std::cout to print true / false
    std::cout << std::boolalpha;

    std::cout << true << '\n';
    std::cout << false << "\n\n";

    // can't list assign numbers to bools, can copy assign however
    // 0 is false, anything else is true
    bool b4 = 4;
    bool b5 = 0;

    std::cout << b4 << '\n';
    std::cout << b5 << "\n\n";

    // accepting inputs, std::cin defaults to only allow 0 and 1 for bools
    // need to enable std::boolalpha to accept "true" and "false"
    // disables conversion of "1" and "0" however
    bool b6 {};
    std::cout << "Enter a boolean value: ";

    std::cin >> std::boolalpha;
    std::cin >> b6;

    std::cout << "You entered: " << b6 << "\n\n";

    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    std::cout << "Enter another: ";
    int y {};
    std::cin >> y;

    std::cout << "are " << x << " and " << y << " equal? ";
    std::cout << is_equal(x, y);

    return 0;
}
