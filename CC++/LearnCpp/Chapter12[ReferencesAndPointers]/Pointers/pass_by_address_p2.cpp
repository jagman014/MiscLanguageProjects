#include <iostream>
#include <string>

void greet(std::string* name=nullptr) { // optional argument
    std::cout << "Hello ";
    std::cout << (name ? *name : "guest") << '\n';
}

// better to do pass by reference and overloads however
// can pass literal strings and don't need to worry about dereferencing
void greet() {
    std::cout << "Hello guest" << '\n';
}

void greet(const std::string& name) {
    std::cout << "Hello " << name << '\n';
}

// pass by address by reference, pass by address is a copy of a pointer
// can pass the reference of the address to modify the pointer
void nullify(int*& refptr) {
    refptr = nullptr;
}

int main() {
    // greet();

    std::string name {"Joe"};
    greet(&name);

    int x {5};
    int* ptr {&x}; // ptr points to x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    return 0;
}
