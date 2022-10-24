#include <iostream>


class Base {
public:
    virtual ~Base() { // best to make any explicit destructors virtual when dealing with inheritance
        std::cout << "Calling ~Base()\n";
    }

    virtual const char* get_name() const {
        return "Base";
    }
};


class Derived: public Base {
private:
    int* m_array;

public:
    Derived(int length)
    : m_array {new int[length]} {}

    virtual ~Derived() {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }

    virtual const char* get_name() const {
        return "Derived";
    }
};


int main() {
    Derived* derived {new Derived(5)};
    Base* base {derived};

    // can ignore virtual functiobs by calling the Base function explicitly
    std::cout << base->get_name() << '\n';
    std::cout << base->Base::get_name() << '\n';

    // deleting base requires deleting the m_array of the Derived it points to
    delete base;

    return 0;
}
