#include <iostream>


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


void print(const Cents& cents) {
    std::cout << cents.get_cents() << '\n';
}

Cents add(const Cents& c1, const Cents& c2) {
    return {c1.get_cents() + c2.get_cents()}; // return anonymous cents value
}

int main() {
    print(Cents {6}); // anonymous object created and discarded once function ends

    // print anonymous object value
    std::cout << "I have " << add(Cents {6}, Cents {8}).get_cents() << " cents\n";

    return 0;
}
