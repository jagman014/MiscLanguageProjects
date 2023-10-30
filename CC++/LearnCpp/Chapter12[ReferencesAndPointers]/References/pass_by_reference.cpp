#include <iostream>
#include <string>

void print_value(std::string& y) { // pass reference to function
    std::cout << y << '\n';
}

void add_one(int& y) { // can modify original object, cannot accept const or rvalues
    ++y;
}

void print_value(const int& y) { // pass by const ref, cannot modify value in function however
    std::cout << y << '\n';
}

int main() {
    std::string x {"Hello, World!"};

    print_value(x); // x passed by reference into y, cheaper than copying

    int y {5};

    std::cout << "value = " << y << '\n';

    add_one(y);

    std::cout << "value = " << y << '\n'; // y has been modified

    print_value(y); // y is modifiable

    const int z {5};
    print_value(z); // z is non-modifiable

    print_value(5); // 5 is an rvalue

    return 0;
}