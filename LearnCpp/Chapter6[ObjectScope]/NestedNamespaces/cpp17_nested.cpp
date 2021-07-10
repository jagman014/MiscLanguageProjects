#include <iostream>

// since c++17 nested namespaces can be defined as:
namespace foo::bar {
    int add(int x, int y) {
        return x + y;
    }
}

int main() {
    // can also alias namespaces to shorten names
    // allow for easy movement of functionality to another namespace
    namespace active = foo::bar;
    std::cout << active::add(4, 3) << '\n';

    return 0;
}
