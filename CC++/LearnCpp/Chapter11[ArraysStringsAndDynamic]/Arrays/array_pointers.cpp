#include <iostream>

// due to array decay, they are passed to functions as a pointer
// best to favour this method, 
// explicitly states object being treated as a pointer, passed by reference
void print_size(int* array) {
    std::cout << sizeof(array) << '\n';
}

// array is implicity changed to pointer
void print_size_1(int array[]) {
    std::cout << sizeof(array) << '\n';
}

int main() {
    int array[5] {9, 7, 5, 3, 1};

    // calling the base array returns a pointer to the first element
    // array still has type int[5], not int*
    std::cout << "Element 0 has address: " << &array[0] << '\n';
    std::cout << "The array decays to a pointer holding address " 
                << array << '\n';

    // dereferencing an array will return the first element
    // this is still due to the above
    std::cout << *array << '\n';

    char name[] {"Alice"}; // c-style string is still an array
    std::cout << *name << '\n';

    // arrays are not just pointers, clearly seen by sizeof()
    int* ptr {array};

    std::cout << sizeof(array) << '\n'; // sizeof(int) * # of elements
    std::cout << sizeof(ptr) << '\n'; // sizeof(int*)

    // the address of an array returns a pointer to the entire array
    // &array is of type int*[5]

    // in both cases array passed as pointer to function
    print_size(array);
    print_size_1(array);

    return 0;
}
