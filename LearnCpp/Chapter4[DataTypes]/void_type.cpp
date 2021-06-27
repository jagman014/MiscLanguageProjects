#include <iostream>
// used to state no type

// cannot define a variable as void type
void value;

// mainly used to state a function has no return value
void no_return(int x) {
    std::cout << "value of x is " << x << '\n';
}

// in C used to state a function has no params, not done in C++
// for C++ brackets left empty as implicit void
int get_value(void) {
    int x {};
    std::cin >> x;

    return x;
}
