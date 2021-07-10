#include <iostream>

void print() { // lives in global namespace
    std::cout << " there\n";
}

namespace foo { // creates foo namespace
    void print() { // lives in foo namespace
        std::cout << "Hello";
    }

    void print_hello_there() {
        print(); // calls foo::print()
        ::print(); // calls global::print()
    }
}

int main() {
    foo::print_hello_there();

    return 0;
}
