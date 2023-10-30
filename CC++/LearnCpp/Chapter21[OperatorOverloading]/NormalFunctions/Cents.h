#ifndef CENTS_H
#define CENTS_H

class Cents {
private:
    int m_cents {};

public:
    Cents(int cents)
    : m_cents {cents} {}

    int get_cents() const {
        return m_cents;
    }
};

// unlike friend function, need to provide prototype for operator overload
Cents operator+(const Cents& c1, const Cents& c2);

#endif
