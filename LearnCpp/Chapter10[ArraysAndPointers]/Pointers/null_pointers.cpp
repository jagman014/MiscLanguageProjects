#include <cstddef> // for NULL, std::nullptr_t
#include <iostream>

// assigning or initialising a pointer with a literal 0, 
// will produce a null pointer
// null pointers evaluate to false
// dereferencing a null point will cause undefined behaviour

// use std::nullptr_t to get type of nullptr, i.e. for functions

void print(int x) {
    std::cout << "print(int): " << x << '\n';
}

void print(int* x) {
    if (!x) {
        std::cout << "print(int*): null\n";
    }
    else {
        std::cout << "print(int*): " << x << '\n';
    }
}

int main() {
    float* fptr; // uninitialised, best to initialise as null instead
    fptr = 0; // now a null pointer

    std::cout << "fptr: " << fptr << '\n';

    double* dptr {0}; // null pointer

    if (dptr) {
        std::cout << "dptr is pointing to a double value\n";
    }
    else {
        std::cout << "dptr is a null pointer\n";
    }

    // C-standard library defines a NULL macro, best to avoid however
    // due to it being implementation defined
    // NULL is defined as 0 in some implementations, giving a value of int 0
    int* iptr {NULL};

    print(iptr); // calls print(int*)
    print(0); // calls print(int)
    // print(NULL); conflit due to overloaded functions

    // C++11 introduced nullptr keyword, prefered method
    int* x {nullptr};

    // both call print(int*) as desired
    print(x);
    print(nullptr);

    return 0;
}
