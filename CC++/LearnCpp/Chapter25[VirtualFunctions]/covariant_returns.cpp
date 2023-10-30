#include <iostream>
#include <string_view>


class Base {
public:
    // returns a pointer to a Base class
    virtual Base* get_this() {
        std::cout << "called Base::get_this()\n";
        return this;
    }

    void print_type() {
        std::cout << "returned Base\n";
    }
};


class Derived: public Base {
public:
    // overrides normally need to the return the same type, but Deived comes from Base
    Derived* get_this() override {
        std::cout << "called Derived::get_this()\n";
        return this;
    }

    void print_type() {
        std::cout << "returned Derived\n";
    }
};


int main() {
    Derived d {};
    Base* b {&d};

    d.get_this()->print_type();
    b->get_this()->print_type(); // because get_this is virtual the Base* is upcast to a Derived*

    return 0;
}
