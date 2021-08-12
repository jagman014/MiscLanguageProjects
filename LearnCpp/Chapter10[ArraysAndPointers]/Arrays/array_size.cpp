#include <iostream>
#include <iterator> // for std::size()

// can use std::size to get the size of an array (C++17)
// cannot be used within a function the array is passed to

// need to use sizeof before C++17
// will only return the size of a pointer when used in a function

int main() {
    int array[] {1, 1, 2, 3, 5, 8, 13, 21};
    std::cout << "The array has " << std::size(array) << " elements\n";

    // size of array = size of pointers * size of int  
    std::cout << "The array is " << sizeof(array) << " bytes\n";
    std::cout << "An int is " << sizeof(int) << " bytes\n";
    std::cout << "Therefore the array has " 
                << (sizeof(array) / sizeof(array[0])) << " elements\n";

    return 0;
}
