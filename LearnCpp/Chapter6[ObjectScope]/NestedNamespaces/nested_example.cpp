#include <iostream>

namespace foo {
    namespace bar { // bar namespace inside foo namespace
        int add(int x, int y) {
            return x + y;
        }
    }
}

int main() {
    std::cout << foo::bar::add(4, 3) << '\n';

    return 0;
}
