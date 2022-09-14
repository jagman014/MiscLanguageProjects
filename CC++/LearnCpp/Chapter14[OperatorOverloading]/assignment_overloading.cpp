#include <cassert>
#include <iostream>


class Fraction {
private:
    int m_numerator {0};
    int m_denominator {1};

public:
    // default constructor
    Fraction(int numerator=0, int denominator=1)
    : m_numerator {numerator}
    , m_denominator {denominator} {
        assert(denominator != 0);
    }

    // copy constructor
    Fraction(const Fraction& copy)
    : m_numerator {copy.m_numerator}
    , m_denominator {copy.m_denominator} {
        std::cout << "copy constructor called\n";
    }

    // overload assignment
    Fraction& operator=(const Fraction& fraction);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};


std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

Fraction& Fraction::operator=(const Fraction& fraction) {
    // self assignment guard
    if (this == &fraction) {
        return *this;
    }

    // do copy
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return existing so that it can be chained
    return *this;
}


class MyString {
private:
    char* m_data {};
    int m_length {};

public:
    MyString(const char* data=nullptr, int length=0)
    : m_length {length} {
        if (length) {
            m_data = new char[length];

            for (int i {0}; i < length; ++i) {
                m_data[i] = data[i];
            }
        }
    }

    ~MyString() {
        delete[] m_data;
    }

    MyString& operator=(const MyString& str);

    friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};


std::ostream& operator<<(std::ostream& out, const MyString& s) {
    out << s.m_data;
    return out;
}

MyString& MyString::operator=(const MyString& str) {
    // self assignment guard
    if (this == &str) {
        return *this;
    }

    // if data exists in current string delete it
    if (m_data) delete[] m_data;

    m_length = str.m_length;

    m_data = new char[str.m_length];

    for (int i {0}; i < str.m_length; ++i) {
        m_data[i] = str.m_data[i];
    }

    return *this;
}

int main() {
    Fraction five_thirds {5, 3};
    Fraction f;
    f = five_thirds;

    std::cout << f << '\n';

    MyString jag {"Jag", 4};
    MyString employee;
    employee = jag;

    std::cout << employee << '\n';

    return 0;
}
