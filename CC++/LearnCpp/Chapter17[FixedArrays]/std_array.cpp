#include <algorithm> // for std::sort
#include <array> // for std::array, std::to_array
#include <cstddef> // for std::size_t
#include <iostream>

// pass by reference to avoid coping
void print_length(const std::array<double, 5>& array) {
    std::cout << "length " << array.size() << '\n'; // .size() -> length of array
}
// size is always known, can use for-each loops

// template array function, need to account for variable type and size
template <typename T, std::size_t size>
void print_array(const std::array<T, size>& array) {
    for (auto element : array) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

// can make an array of structs
struct House {
    int number {};
    int floors {};
    int rooms_per_floor {};
};

int main() {
    // need to provide the length of the array unlike fixed arrays
    std::array<int, 3> my_array; // integer array of length 3
    std::array<int, 5> my_array_2 {9, 7, 5, 3, 1}; // initialise array like before

    // since C++17, can omit type AND length, but not one of the other
    // only if explicitly initialised
    std::array an_array {9, 7, 5, 3, 1}; // std::array<int, 5>
    std::array an_array_2 {9.7, 5.3}; // std::array<double, 2>

    // since C++20, can omit length using std::to_array
    // more expensive than std::array due to coping C-style arrays over
    auto another {std::to_array<int, 5>({9, 7, 5, 3, 1})}; // specify type and size
    auto another_1 {std::to_array<int>({9, 7, 5, 3, 1})}; // specify type only
    auto another_2 {std::to_array({9, 7, 5, 3, 1})}; // decude type and size

    // assignment an access are the same as other arrays
    my_array = {1, 2, 3}; // fine
    my_array = {1, 2}; // fine, element 3 set to 0
    my_array = {1, 2, 3, 4}; // too many elements -> error

    std::cout << an_array[3] << '\n';
    an_array[4] = 9;

    // also have an .at() method like python dict.get()
    // will throw error is out of bounds, unlike []
    // slower but safer
    another.at(1) = 15;
    another.at(6) = 10;

    // manually cleansup when goes out of scope

    // arrays can be sorted with std::sort
    std::array array {7, 3, 5, 1, 9};

    std::sort(array.begin(), array.end()); // sort array forwards
    std::sort(array.rbegin(), array.rend()); // sort array backwards

    for (int element : array) {
        std::cout << element << ' ';
    }

    std::cout << '\n';

    // indexed for loops take a strange shape, require i to be type std::size_t
    // as not to mismatch type of comparison or index
    for (std::size_t i {0}; i < array.size(); ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    // reverse for loop
    // postfix --, decrement before loop starts so that the comparison 
    // works without wrapping the std::size_t unsigned int
    for (auto i {array.size()}; i-- > 0; ) { 
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    // can populate array of struct with lists
    std::array<House, 3> houses {};

    houses[0] = {13, 4, 30};
    houses[1] = {14, 3, 10};
    houses[2] = {15, 3, 40};

    for (const auto& house : houses) {
        std::cout << "House number " << house.number
            << " has " << (house.rooms_per_floor * house.floors)
            << " rooms\n";
    }

    // when initialising, need a second set of braces
    // first set of inner braces is sent to array, then each next inner brace to struct
    std::array<House, 3> houses_1 {{
        {13, 4, 30},
        {14, 3, 10},
        {15, 3, 40}
    }};

    return 0;
}
