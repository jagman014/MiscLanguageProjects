#include <cassert>
#include <iostream>


class Foo {
public:
    int m_x {};
    int m_y {};
};


class Fraction {
private:
    int m_numerator {};
    int m_denominator {};

public:
    // default constructor, akin to __init__()
    // overload, to allow for value assignment
    Fraction(int numerator=0, int denominator=1) {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    // c++ will create a default constructor if not provided

    int get_numerator() {
        return m_numerator;
    }
    int get_denominator() {
        return m_denominator;
    }
    double get_value() {
        return static_cast<double>(m_numerator) / m_denominator;
    }
};


class Date {
private:
    int m_year {1900};
    int m_month {1};
    int m_day {1};

public:
    // can tell compiler to create a default constructor
    Date() = default;

    Date(int year, int month, int day) {
        m_year = year;
        m_month = month;
        m_day = day;
    }
};


int main() {
    // can list init when all attributes are public
    Foo foo {6, 7};

    Fraction frac {};
    std::cout << frac.get_numerator() << '/' << frac.get_denominator() << '\n';
    std::cout << frac.get_value() << '\n';

    Fraction five_thirds {5, 3}; // list initalisation, call Fraction(int, int)
    Fraction three_quarters(3, 4); // direct initalisation

    Date date {}; // init to 1900-01-01
    Date today {2022, 8, 21}; // init to today

    return 0;
}
