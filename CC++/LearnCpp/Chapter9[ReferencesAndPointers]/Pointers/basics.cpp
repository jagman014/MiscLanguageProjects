#include <iostream>
#include <typeinfo> // for typeid()

// variables that hold the memory address of a value

int main() {
    int x {5};

    // reference memeory with &, dereference memeory with *
    std::cout << x << '\n'; // print value of x
    std::cout << &x << '\n'; // print memory address of x
    std::cout << *(&x) << "\n\n"; // print value at memory address of x

    // initialise pointers with * between type and name
    // type of the pointer has to match the object it points to
    // cannot init a pointer with a literal, 
    // only another variable or not at all
    int v {5};
    int* ptr {&v};

    std::cout << &v << '\n';
    std::cout << ptr << "\n\n";

    // & returns a pointer
    // need to demangle to get "int*" -> "basics.exe | c++filt -t"
    std::cout << typeid(ptr).name() << "\n\n";

    // can dereference a pointer
    std::cout << ptr << '\n';
    std::cout << *ptr << "\n\n";

    // can reassign pointers just like variables,
    // reassigning the dereferenced pointer will reassign the original value
    int value {5};
    int* pointer {&value};

    std::cout << "value = " << value << '\n';

    *pointer = 7;

    std::cout << "Pointer reassigned, value = " << value << "\n\n";

    // size of a pointer is the same independent of type
    char* c_ptr {};
    int* i_ptr {};
    double* d_ptr{};

    std::cout << typeid(c_ptr).name() << " " << sizeof(c_ptr) << " Bytes\n";
    std::cout << typeid(i_ptr).name() << " " << sizeof(i_ptr) << " Bytes\n";
    std::cout << typeid(d_ptr).name() << " " << sizeof(d_ptr) << " Bytes\n";

    return 0;
}
