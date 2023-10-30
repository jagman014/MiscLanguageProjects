#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// return true if element matches
bool contains_nut(std::string_view str) {
    // std::string_view::find returns std::string_view::npos if it doesn't
    // find the substring. Otherwise returns the index of the substring
    return (str.find("nut") != std::string_view::npos);
}

int main() {
    std::array<std::string_view, 5> arr {"apple", "banana", "walnut", "lemon", "peanut"};
    
    auto count {std::count_if(arr.begin(), arr.end(), contains_nut)};
    // std::count also available

    std::cout << "Counted " << count << " nuts\n";

    return 0;
}
