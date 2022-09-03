#include <cassert>
#include <iostream>


class Fraction {
private:
    int m_numerator {};
    int m_denominator {};

public:
    // default constructor
    Fraction(int numerator=0, int denominator=1)
    : m_numerator {numerator}
    , m_denominator {denominator} {
        assert(denominator != 0);
    }

    // copy constructor, making private prevents copies
    // must be a reference parameter
    Fraction(const Fraction& fraction)
    // can access private variables, as we are inside the class
    : m_numerator {fraction.m_numerator}
    , m_denominator {fraction.m_denominator} {
        // no need to check, already checked in inital object
        std::cout << "Copy constructor called\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};


std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

int main() {
    Fraction five_thirds {5, 3}; // direct initialisation with Fraction(int, int)
    Fraction f_copy {five_thirds}; // direct init, with copy constructor

    std::cout << f_copy << '\n';

    return 0;
}
