#include <iostream>


// this pointer is equivilent to self
class Something {
private:
    int data;

public:
    Something(int data) {
        this->data = data; // disambiguate memeber and input values of same names
    }
};


// can use this to chain methods
class Calc {
private:
    int m_value {};

public:
    Calc& add(int value) {
        m_value += value;
        return *this;
    }

    Calc& sub(int value) {
        m_value -= value;
        return *this;
    }

    Calc& mult(int value) {
        m_value *= value;
        return *this;
    }

    int get_value() {
        return m_value;
    }
};


int main() {
    Calc calc {};
    calc.add(5).sub(3).mult(4); // chainable methods

    std::cout << calc.get_value() << '\n';
    return 0;
}
