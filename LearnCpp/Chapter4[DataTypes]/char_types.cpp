#include <iostream>

// char holds a single character; letter, digit, symbol, or whitespace
// stored as an integer value and ASCII interpreted as number from 0 to 127
// literal char between single quotes

char ch1 {97}; // init with int value -> 'a'
char ch2 {'a'}; // prefered init with char literal

// char ch {5} != char ch {'5'}

int main() {
    std::cout << ch1; // int interpreted as char
    std::cout << ch2; // init as char lit, printed as char
    std::cout << 'a' << "\n\n"; // print literal

    // can cast char value to int
    int i {ch1};
    std::cout << i << "\n\n";

    // better method is to use static type casting
    std::cout << ch2 << '\n';
    std::cout << static_cast<int>(ch2) << '\n';
    std::cout << ch2 << "\n\n";

    // can take char as user input
    std::cout << "Input a keyboard character: ";

    // input of multiple chars assigns first char, then following letters
    // are left in the input buffer queue, can be extracted via multiple
    // calls to std::cin
    char ch3 {};
    std::cin >> ch3;
    std::cout << ch3 << " has ASCII code " << static_cast<int>(ch3) << '\n';

    std::cin >> ch3;
    std::cout << ch3 << " has ASCII code " << static_cast<int>(ch3) << '\n';

    // charN_t are for UTF-N encoded chars
    // char8_t is from C++20

    return 0;
}
