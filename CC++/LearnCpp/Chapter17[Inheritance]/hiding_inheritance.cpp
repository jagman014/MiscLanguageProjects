#include <iostream>


class Base {
public:
    int m_value;

    Base() = default;

    Base(int value)
    : m_value {value} {}

    int get_value() const {
        return m_value;
    }

protected:
    void print_value() const {
        std::cout << m_value;
    }
};


class Derived: public Base {
private:
    // m_value now set to private within derived
    using Base::m_value;

public:
    Derived(int value) {
        m_value = value; // can't init as Base member, can assign value
    }

    // can change protected to public with using statement
    using Base::print_value;

    int get_value() = delete; // mark inherited function as inaccessible
};


int main() {
    Derived derived {7};

    // can use protected base method, as set as public in derived
    derived.print_value();
    std::cout << '\n';

    // std::cout << derived.m_value; // won't work as member is private
    // std::cout << derived.get_value(); // won't work as method is deleted

    // can still call deleted function through Base
    std::cout << derived.Base::get_value() << '\n';

    // or can cast object and call function
    std::cout << static_cast<Base&>(derived).get_value() << '\n';

    return 0;
}
