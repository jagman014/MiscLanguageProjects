#include <algorithm>
#include <array>
#include <iostream>

void double_number(int& i) {
    i *= 2;
}

int main() {
    std::array arr{ 1, 2, 3, 4 };

    // modifies each element using a function
    std::for_each(arr.begin(), arr.end(), double_number);
    // std::for_each(arr, double_number); // don't need .begin() or .end since C++20
    
    // can skip elements at start or end using std::next
    // std::for_each(std::next(arr.begin()), arr.end(), double_number);

    for (int i : arr) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}
