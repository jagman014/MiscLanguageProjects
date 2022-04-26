#include <iostream>
#include <new> // for std::nothrow

int main() {
    new int; // dynamically assign an integer (and discard)
    // new returns a pointer to the memory address allocated

    int* ptr {new int};

    // then perform indirection through pointer
    *ptr = 7;

    // initalise like previous
    int* ptr1 {new int {5}};

    delete ptr; // return memory to OS
    ptr = nullptr; // set ptr to nullptr

    // delete will cause a dangling pointer is not treated properly (i.e. set to nullptr)
    // only removes memory address, doesn't delete variable
    
    // if no available memory new can crash the program
    // avoid with std::nothrow, new will return a nullptr instead of crash
    int* value {new (std::nothrow) int {}};
    if (!value) {
        std::cerr << "Could not allocate memory\n";
    }

    // avoid memory leaks by deleting ptr before reassignment or loss out of scope
    int val {5};
    int* ptr2 {new int {}};
    delete ptr2;
    ptr2 = &val;

    return 0;
}
