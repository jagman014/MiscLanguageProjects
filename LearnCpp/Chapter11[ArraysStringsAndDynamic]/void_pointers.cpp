#include <iostream>
#include <cassert>

void notes() {
    // void pointers can point to any type
    int ivalue;
    float fvalue;

    struct Something {
        int i;
        float f;
    };

    Something svalue;

    void* ptr;
    ptr = &ivalue; // all valid references for void pointer
    ptr = &fvalue;
    ptr = &svalue;

    // cannot dereference a void pointer (i.e. std::cout << *void_ptr; not allowed)
    int value {5};
    void* void_ptr {&value};

    // can cast then dereference
    int* int_ptr {static_cast<int*>(void_ptr)};

    std::cout << *int_ptr << '\n';
}

enum class Type {
    t_int,
    t_float,
    t_cstring
};

void print_value(void* ptr, Type type) {
    switch (type)
    {
    case Type::t_int:
        std::cout << *static_cast<int*>(ptr) << '\n';
        break;

    case Type::t_float:
        std::cout << *static_cast<float*>(ptr) << '\n';
        break;

    case Type::t_cstring:
        std::cout << static_cast<char*>(ptr) << '\n';
        break;

    default:
        assert(false && "type not found");
        break;
    }
}

int main() {
    int i_value {5};
    float f_value {7.5f};
    char cs_value[] {"Mollie"};

    print_value(&i_value, Type::t_int);
    print_value(&f_value, Type::t_float);
    print_value(&cs_value, Type::t_cstring);

    return 0;
}
