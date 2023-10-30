#include <algorithm>
#include <array>
#include <iostream>

// can be replaced with std::greater from <functional>
bool greater(int a, int b) {
    // Order @a before @b if @a is greater than @b.
    return (a > b);
}

int main() {
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    // Pass greater to std::sort
    std::sort(arr.begin(), arr.end(), greater);
    // std::sort(arr.begin(), arr.end(), std::greater{}); // need the {}

    for (int i : arr) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}
