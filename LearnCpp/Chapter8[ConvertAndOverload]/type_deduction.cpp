#include <iostream>

// auto allows for the compiler to infer the type of the object
// reducing redundancy of using type keyword and type literals
// cannot use auto on zero init variables

// prefer expicit return and param types instead of auto
int add(int x, int y) {
    return x + y;
}

int main() {
    auto d {5.0}; // double literal -> d is double
    auto i {1 + 2}; // evaluates to int -> i is int
    auto x {i}; // i is int -> x is int

    auto sum {add(5, 6)}; // return value is int -> sum is int

    const int y {4};
    auto z {y}; // auto will not keep the const of a variable

    // need to explicitly state const for auto
    // same for object references
    const auto a {y};

    // can produce side effects if the incorrect literal was supplied

    return 0;
}
