#include <iostream>

int main() {
    int x {5}; // x is a normal integer variable
    int& ref {x}; // ref is a lvalue reference that can be used as an alias for x

    std::cout << x << '\n'; // print value of x
    std::cout << ref << '\n'; // print value of x via ref

    std::cout << "x: " << x << ", ref: " << ref << '\n';

    x = 6; // change value of x

    std::cout << "x: " << x << ", ref: " << ref << '\n';

    ref = 7; // change value of x via ref

    std::cout << "x: " << x << ", ref: " << ref << '\n';

    const int y {5};
    int& invalid_ref {y}; // can't reference non-modifiale lvalue
    int& invalid_ref_2 {0}; // can't reference rvalue

    double z {2.0};
    int& invalid_ref_3 {z}; // wrong type match
    double& invalid_ref_4 {x}; // wrong type match

    // cannot reseat reference to another object
    ref = y; // sets x to the value of y
    // doesn't set ref to reference y -> x = y

    return 0;
}
