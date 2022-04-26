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
    std::array<std::string_view, 4> arr {"apple", "banana", "walnut", "lemon"};
    
    auto found {std::find_if(arr.begin(), arr.end(), contains_nut)};

    if (found == arr.end()) {
        std::cout << "No Nuts\n";
    }
    else {
        std::cout << "Found " << *found << '\n';
    }

    return 0;
}
