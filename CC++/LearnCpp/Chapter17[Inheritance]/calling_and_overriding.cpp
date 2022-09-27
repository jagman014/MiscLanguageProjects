#include <iostream>


class Base {
protected:
    int m_value {};

public:
    Base(int value)
    : m_value {value} {}

    void identify() const {
        std::cout << "I am a Base\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Base& b) {
        out << "In Base\n";
        out << b.m_value << '\n';
        return out;
    }
};


class Derived: public Base {
public:
    Derived(int value)
    : Base {value} {}

    // override method
    void identify() const {
        // can call inherited methods within derived class, need :: to use right method
        Base::identify();
        std::cout << "I am a Derived\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Derived& d) {
        out << "In Derived\n";
        // use base overload through static cast
        out << static_cast<const Base&>(d);
        return out;
    }
};


int main() {
    Base base {5};
    base.identify();

    Derived derived {7};
    derived.identify();

    std::cout << derived << '\n';

    return 0;
}
