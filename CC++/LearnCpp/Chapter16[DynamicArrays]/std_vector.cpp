#include <iostream>
#include <vector> // for std::vector

// vectors remember their length
void print_length(const std::vector<int>& array) {
    std::cout << "The length is " << array.size() << '\n';
}

int main() {
    // std::vector since C++03, dynamic array that handles own memory allocation
    // no need to specify length
    std::vector<int> array;
    std::vector<int> array2 {9, 7, 5, 3, 1};

    // since C++17 can omit type
    std::vector array3 {9, 7, 5, 3, 1}; // needs to be initalised though

    // can access elements like srd::array
    array[2] = 4; // doesn't bound check
    array.at(7) = 15; // does bound check

    // vector will self resize
    array = {1, 2, 3, 4, 5}; // now 5 elements
    array = {1, 2, 3}; // now 3 elements

    // vector will deallocate memory automatically if / when it goes out of scope

    std::vector array {9, 7, 5, 3, 1};
    print_length(array);

    std::vector<int> empty {};
    print_length(empty);

    // can resize vector manually, new elements will be set to default values
    // removed values will start from the right inwards
    std::vector array {1, 2, 3};
    print_length(array);

    array.resize(5);
    print_length(array);

    for (int i : array) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    array.resize(2);
    print_length(array);

    for (int i : array) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    // resizing is expensive
    // can initialise size with default values using direct init
    // using braces -> array of length 1 with a value of 5
    std::vector<int> array(5);
    print_length(array);

    for (int i : array) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    // std::vector will also compact 8 bools into a byte behind the scenes
    // doesn't affect usage
    std::vector<bool> array {true, false, false, true, true};
    print_length(array);

    for (int i : array) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}
