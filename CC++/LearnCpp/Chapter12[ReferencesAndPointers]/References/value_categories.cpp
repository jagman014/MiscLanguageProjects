#include <iostream>

int return_5(){
    return 5;
}

int main() {
    int x {5}; // 5 is an rvalue (non-lvalue / literal [except string literals])
    const double d {1.2}; // 1.2 is an rvalue expression

    std::cout << x << '\n'; // x is an lvalue, an object with an identity
    std::cout << d << '\n'; // d is a non-modifiable lvalue expression
    std::cout << return_5(); // return_5() is an rvalue expression
    std::cout << x + 1 << '\n'; // x + 1 is an rvalue expression
    std::cout << static_cast<int>(d) << '\n'; // rvalue expression

    // lvalues are implicitly changed to rvalues for assignment operations

    return 0;
}
