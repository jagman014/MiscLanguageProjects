#include <algorithm>
#include <array>
#include <iostream>

int main() {
    // std::find to find an element by value
    std::array arr {13, 90, 99, 5, 40, 80};

    std::cout << "Enter a value to search for and replace with: ";
    int search {};
    int replace {};
    std::cin >> search >> replace;

    // std::find returns an iterator pointing to the found element
    // or the end of the container if not found
    auto found {std::find(arr.begin(), arr.end(), search)};

    if (found == arr.end()) {
        std::cout << "Could not find " << search << '\n';
    }
    else {
        *found = replace;
    }

    for (int i : arr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
