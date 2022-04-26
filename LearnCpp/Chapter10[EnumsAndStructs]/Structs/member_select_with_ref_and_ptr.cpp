#include <iostream>
#include <string>

struct Employee {
    int id {};
    int age {};
    double wage {};
};

void print_employee(const Employee& e) {
    // reference acts like the object itself
    std::cout << "Id: " << e.id << '\n';
    std::cout << "Age: " << e.age << '\n';
    std::cout << "Wage: " << e.wage << '\n';
}

struct Paw {
    int claws {};
};

struct Animal {
    std::string name {};
    Paw paw {};
};

int main() {
    Employee joe {1, 34, 65000.0};

    ++joe.age;
    joe.wage = 68000.0;

    print_employee(joe);

    // member selection of pointer using "->"
    Employee* ptr {&joe};
    std::cout << ptr->id << '\n'; // works like ".", but has implicit dereference

    // can mix pointer and object member selection
    Animal puma {"Puma", {5}};
    Animal* ptr_1 {&puma};

    // ptr_1 is a pointer use ->
    // paw is not a pointer use .
    std::cout << ptr_1->paw.claws << '\n';

    return 0;
}
