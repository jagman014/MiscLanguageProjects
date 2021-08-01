#include <iostream>

// templates allow for placeholder types
// compiler creates the necessary overloaded functions
// convention of single captial letters starting with T

template <typename T> // template param declaration
T max(T x, T y) { // template function
    return (x > y) ? x : y;
}

// can create templates with non-template params
template <typename U>
int some_fcn(U x, double y) {
    return 5;
}

// can create templates with multiple template params
// as well as an auto return value for the compiler to handle
template <typename V, typename W>
auto min(V x, W y) {
    return (x < y) ? x : y;
}

// can be abbreviated in C++20 or newer with just auto
auto do_thing(auto x, auto y) {
    return ((x / y) > x) ? x : y;
}

int main() {
    // to call template function, need to specify used type in <>
    // instantiates and call max<int>(int, int)
    std::cout << max<int>(1, 2) << '\n'; 

    // uses already made max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n'; 
    
    // creates max<double>(double, double)
    std::cout << max<double>(1, 2) << '\n'; 

    // can remove angled brackets so that the compiler will also look at
    // other overloaded functions instead of just the template ones
    // i.e. max(1, 2) -> max() or max<int>(int, int)

    // will deduce type of template from params if no type specified
    // i.e. max<>(1, 2) -> max<int>(int, int)

    // favour template deduction, reduce redundant code

    some_fcn(1, 3.4); // matches some_fcn(int, double)
    some_fcn(1, 3.4f); // matches some_fcn(int, double) -- float promoted
    some_fcn(1.2, 3.4); // matches some_fcn(double, double)
    some_fcn(1.2f, 3.4); // matches some_fcn(float, double)
    some_fcn(1.2f, 3.4f); // matches some_fcn(float, double) -- float promoted

    // no compiler errors due to muliple input types
    // return type deduced by compiler when making function from template
    std::cout << min(2, 1.5) << '\n';

    std::cout << do_thing(15, 2.5) << '\n';

    return 0;
}
