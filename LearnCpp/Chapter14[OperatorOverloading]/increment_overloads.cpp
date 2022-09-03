#include <iostream>


class Digit {
private:
    int m_digit {};

public:
    Digit(int digit=0)
    : m_digit {digit} {}

    Digit& operator++(); // prefix has no arguments
    Digit& operator--(); // prefix has no arguments

    Digit operator++(int); // postfix has an int param
    Digit operator--(int); // postfix has an int param

    friend std::ostream& operator<<(std::ostream& out, const Digit& d);
};


Digit& Digit::operator++() {
    // if number is already 9 wrap around to 0
    if (m_digit == 9) {
        m_digit = 0;
    }
    else {
        ++m_digit;
    }

    return *this;
}

Digit& Digit::operator--() {
    // if number is already 0 wrap around to 9
    if (m_digit == 0) {
        m_digit = 9;
    }
    else {
        --m_digit;
    }

    return *this;
}

Digit Digit::operator++(int) {
    // create temp object with current digit
    Digit temp {*this};

    // use prefix to increment
    ++(*this);

    return temp;
}

Digit Digit::operator--(int) {
    // create temp object with current digit
    Digit temp {*this};

    // use prefix to decrement
    --(*this);

    return temp;
}

std::ostream& operator<<(std::ostream& out, const Digit& d) {
    out << d.m_digit;
    return out;
}

int main() {
    Digit digit {5};

    std::cout << digit;
    std::cout << ++digit; // Digit::operator++()
    std::cout << digit++; // Digit::operator++(int)
    std::cout << digit;
    std::cout << --digit; // Digit::operator--()
    std::cout << digit--; // Digit::operator--(int)
    std::cout << digit;

    return 0;
}
