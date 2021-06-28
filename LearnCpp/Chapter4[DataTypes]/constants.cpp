#include <iostream>

// constant variables, cannot be changed doing so gives an error
const double gravity {9.8}; // compile-time constant
// use const keyword before definition
// defining without a value will also cause an error

// constant variables can be initialised from other vairables
int age {23};

const int const_age {age};

// can also be used in function parameters
// function will not change the value passed
void print_int(const int val){
    std::cout << val; // val is a runtime constant
}

// compile time constants my be able to be initialised at compile
// use constexpr to be more specific
constexpr double sum {4 + 5};
// const made from functions / user input cannot be constexpr

// symbolic constants, best to use constexpr varibles
// can be defined in a header file to centralise use
// using namespace and inline constexpr
