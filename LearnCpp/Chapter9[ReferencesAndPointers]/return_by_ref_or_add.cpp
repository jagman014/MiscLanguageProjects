#include <iostream>
#include <string>

// return by address works similarly to return by reference
// need to be careful of nullptr dereferencing however

// objects returned by reference must live beyond scope of function
const std::string& get_program_name() { // returns a const reference
    static const std::string s_program_name {"Calculator"}; // static duration, lasts till end of program
    return s_program_name;
}

// avoid non-const returned references, changes value each time called
const int& get_next_id() {
    static int s_x {0};
    ++s_x;
    return s_x;
}

// can return reference from passed references
const std::string& first_alphabetically(const std::string& a, const std::string& b) {
    return (a < b) ? a : b;
}

int& max(int& x, int& y) {
    return (x > y) ? x : y;
}

int main() {
    std::cout << "This program is called: " << get_program_name() << '\n';

    // initialising from returned reference
    const int& id1 {get_next_id()}; // correct
    const int id2 {get_next_id()}; // copies value from reference, defeats point

    std::cout << id1 << id2 << '\n';

    std::string hello {"hello"};
    std::string world {"world"};

    std::cout << first_alphabetically(hello, world) << '\n';

    // can modify via returned reference
    int x {5};
    int y {6};

    max(x, y) = 7; // sets max of x or y to 7

    std::cout << x << y << '\n';

    return 0;
}
