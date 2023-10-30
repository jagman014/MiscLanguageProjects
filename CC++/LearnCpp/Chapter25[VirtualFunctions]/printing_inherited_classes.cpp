#include <iostream>


// operators cannot be virtual functions
class Base {
public:
    // overload operator first
    friend std::ostream& operator<<(std::ostream& out, const Base& b) {
        // delegate printing to virtual member function
        return b.print(out);
    }

    // rely on member function to do actual printing
    virtual std::ostream& print(std::ostream& out) const {
        out << "Base";
        return out;
    }
};


class Derived: public Base {
public:
    // override for print function
    std::ostream& print(std::ostream& out) const {
        out << "Derived";
        return out;
    }
};


int main() {
    Base b {};
    std::cout << b << '\n';

    Derived d {};
    std::cout << d << '\n'; // works without defining explicit operator<< for Derived

    Base& bref {d};
    std::cout << bref << '\n';

    return 0;
}
