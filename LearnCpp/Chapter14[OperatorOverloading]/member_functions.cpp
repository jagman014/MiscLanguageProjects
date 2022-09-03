#include <iostream>
/* Not all operators can be overloaded as friends
 * i.e. =, [], (), ->  // required by language
 *
 * Some cannot be member functions
 * i.e. <<, >>  // left operand is not part of the class
 */


class Cents {
private:
    int m_cents {};

public:
    Cents(int cents)
    : m_cents {cents} {}

    // overload Cents + int
    Cents operator+(int value);

    int get_cents() const {
        return m_cents;
    }
};


// this is a member function
Cents Cents::operator+(int value) {
    return Cents {m_cents + value};
}

int main() {
    Cents cents1 {6};
    Cents cents2 {cents1 + 2};

    std::cout << "I have " << cents2.get_cents() << " cents\n";

    return 0;
}
