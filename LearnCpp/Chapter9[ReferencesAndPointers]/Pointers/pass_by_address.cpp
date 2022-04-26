#include <iostream>
#include <string>

// can use pass by address to modify original object

void pass_by_value(std::string val) { // param is a copy of string
    std::cout << val << '\n'; // print value via copy
}

void pass_by_reference(std::string& ref) { // param is a reference that binds to string
    std::cout << ref << '\n'; // print value via reference
}

// cannot pass address of an rvalue
void pass_by_address(const std::string* ptr) { // point holds address of string
    std::cout << *ptr << '\n'; // print value of dereferenced pointer
}

int main() {
    std::string str {"Hello, World!"};

    pass_by_value(str); // pass str by value, makes a copy
    pass_by_reference(str); // pass str by reference, no copy
    pass_by_address(&str); // pass str by address, no copy

    std::string* ptr {&str};
    pass_by_address(ptr); // works as above using a pinter instead of address

    return 0;
}
