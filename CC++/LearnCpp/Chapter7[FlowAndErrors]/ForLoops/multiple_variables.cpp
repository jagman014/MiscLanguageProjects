#include <iostream>

int main() {
    // use multiple variables by use of comma operators
    for (int x {0}, y {9}; x < 10; ++x, --y) {
        std::cout << x << ' ' << y << '\n';
    }

    return 0;
}
