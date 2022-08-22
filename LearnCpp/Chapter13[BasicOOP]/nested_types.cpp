#include <iostream>


class Fruit {
public:
    // enum types put in public class namespace
    // can be used within class declaratino
    enum FruitType {
        apple,
        banana,
        cherry
    };

private:
    FruitType m_type {};
    int m_percentage_eaten {0};

public:
    Fruit(FruitType type)
    : m_type {type} {}

    FruitType get_type() const {
        return m_type;
    }

    int get_percentage_eaten() const {
        return m_percentage_eaten;
    }
};


int main() {
    // can use public types from class
    Fruit apple {Fruit::apple};

    if (apple.get_type() == Fruit::apple) {
        std::cout << "I am an apple\n";
    }
    else {
        std::cout << "I am not an apple\n";
    }

    return 0;
}
