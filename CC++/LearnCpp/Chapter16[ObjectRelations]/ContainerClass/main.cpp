#include <iostream>
#include "IntArray.h"

int main() {
    // declare array of 10 elements
    IntArray array(10);

    // fill numbers 1 to 10
    for (int i {0}; i < 10; ++i) {
        array[i] = i + 1;
    }

    // resize to 8
    array.resize(8);

    // insert 20 before 5th value
    array.insert_before(20, 5);

    // remove element at 3rd index
    array.remove(3);

    // add 30 to end, 40 to beginning
    array.insert_at_end(30);
    array.insert_at_beginning(40);

    // print all numbers
    for (int i {0}; i < array.get_length(); ++i) {
        std::cout << array[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}
