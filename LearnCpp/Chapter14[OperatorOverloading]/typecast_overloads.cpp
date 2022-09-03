#include <iostream>


class Cents {
private:
    int m_cents {};

public:
    Cents(int cents=0)
    : m_cents {cents} {}

    // overload int cast
    operator int() const {
        return m_cents;
    }

    int get_cents() const {
        return m_cents;
    }

    void set_cents(int cents) {
        m_cents = cents;
    }
};


class Dollars {
private:
    int m_dollars {};

public:
    Dollars(int dollars=0)
    : m_dollars {dollars} {}

    // allows coversion of dollars to cents
    operator Cents() const {
        return Cents{m_dollars * 100};
    }
};


void print_cents(Cents cents) {
    std::cout << cents; // implicit cast to int
}

int main() {
    Cents cents {7};
    print_cents(cents);

    std::cout << " cents\n";

    Dollars dollars {9};
    print_cents(dollars);

    std::cout << " cents\n";

    return 0;
}
