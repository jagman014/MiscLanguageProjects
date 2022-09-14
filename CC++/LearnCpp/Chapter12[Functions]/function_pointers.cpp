#include <functional> // for std::function
#include <iostream>

int foo() { // code for foo starts at this memeory address
    return 5;
}

int goo() {
    return 6;
}

double hoo(int x) {
    return static_cast<double>(x);
}

int main() {
    foo(); // code jumps to foo memory address

    // print function pointer, returns function address
    // cast to void pointer so g++ compiles
    std::cout << reinterpret_cast<void*>(foo) << '\n';

    // function pointer for function that has no arguments and returns an int
    // brackets are required
    int (*fnc_ptr)() {&foo};
    fnc_ptr = &goo; // reassign to goo function pointer

    // type of function pointer needs to match return and argument types
    double (*fnc_ptr_2)(int) {&hoo};

    // can null init
    int (*fnc_ptr_1)() {nullptr};

    // C++ will implicity convert functions to pointers, 
    // but not func pointers to void pointers

    // can call function through pointer, either explicitly
    (*fnc_ptr_2)(5);

    // or implicitly
    fnc_ptr_2(5);

    // cannot use default params through func pointers, due to being run-time objects

    // can rewrite syntax with std::function
    std::function<int()> fnc_ptr_3 {&foo};

    // can also use auto
    auto fnc_ptr_4 {&hoo};

    return 0;
}
