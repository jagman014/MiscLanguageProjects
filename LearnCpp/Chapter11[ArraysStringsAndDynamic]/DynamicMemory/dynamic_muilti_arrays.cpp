#include <iostream>

int get_single_index(int row, int col, int num_of_cols) {
    return (row * num_of_cols) + col;
}

int main() {
    // pointers to pointers
    int* ptr; // pointer to an int
    int** ptrptr; // pointer to a pointer to an int

    // works like a normal pointer
    int value {5};

    int* ptr {&value};
    std::cout << *ptr << '\n'; // indirection through pointer to get int

    int** ptrptr {&ptr};
    std::cout << **ptrptr << '\n'; // indirection through pointer to get pointer, then again to get int

    /* cannot set directly, & needs an lvalue but &var is an rvalue
    int val {5};
    int** ptrptr {&&val};
    */

    // can set directly to nullptr
    int** ptrptr {nullptr};

    // can be used to allocate an array of pointers
    int** array {new int*[10]};

    // then be used to dynamically allocate n-D arrays, requires a loop
    int** array {new int*[10]}; // these are the rows
    for (int count = 0; count < 10; ++count) {
        array[count] = new int[5]; // these are the columns
    }

    // can then access like a normal array
    array[9][4] = 3;

    // can allocate non-rectangular arrays
    int** array {new int*[10]};
    for (int count = 0; count < 10; ++count) {
        array[count] = new int[count + 1];
    }

    // dealocating also requires a look
    for (int count = 0; count < 10; ++count) {
        delete[] array[count];
    }
    delete[] array; // needs to be done last

    // better to just flatten the array to avoid this however
    int* array {new int[50]};

    // then use maths to convert array indices
    // set array[9, 4] of flattened array
    array[get_single_index(9, 4, 5)] = 3;

    return 0;
}
