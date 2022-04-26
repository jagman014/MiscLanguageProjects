#include <iostream>

int main() {
    const int x {5};
    int& ref {x}; // not allowed, as x is not modifiable

    const int& ref_1 {x}; // non-modifiable reference to const value

    std::cout << ref << '\n'; // can access value via reference
    ref_1 = 7; // cannot modify const object

    int y {5};
    const int& ref_2 {y}; // bind const ref to modifiable var

    ref_2 = 7; // cannot modify via const ref

    y = 6; // can still modify through original identifier

    const int& ref_3 {5}; // allowed as ref is non-modifiable, rvalue is const
    // creates a temporary object

    return 0;
}
