#include <array>
#include <iostream>
#include <iterator> // for std::begin and std::end

int main() {
    // pointer as an iterator
    std::array data {0, 1, 2, 3, 4, 5, 6};

    auto begin {&data[0]}; // .data() also returns a pointer to the first element
    auto end {begin + std::size(data)}; // points to one after last element of array

    // for loop with pointer
    for (auto ptr {begin}; ptr != end; ++ptr) { // ++ move to next element
        std::cout << *ptr << ' '; // indirection to get element value
    }
    std::cout << '\n';

    // other ways to get beginning and end
    auto begin {data.begin()};
    auto end {data.end()};

    // or
    auto begin {std::begin(data)};
    auto end {std::end(data)};

    // for-each loops use std::begin and std::end behind the scenes

    // be careful modifying object being iterated over
    // can lead to undefined behaviour is referenced element is removed before
    // the iterator has been moved

    return 0;
}
