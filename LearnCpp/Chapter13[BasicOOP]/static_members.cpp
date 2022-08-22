#include <iostream>
#include <vector>


class Something {
public:
    static int s_value; // declare static variable
};

// define static variable
// can be done in the class like normal
int Something::s_value {1};


class SomethingElse {
private:
    static inline int s_id_generator {1}; // c++17
    int m_id {};

public:
    SomethingElse()
    : m_id {s_id_generator++} {} // use next value from id gen

    int get_id() const {
        return m_id;
    }
};


class SomethingTheThird {
private:
    static int s_value;

public:
    static int get_value() { // static method
        return s_value;
    }
};

// initialiser, cannot initalise static values in constructors
int SomethingTheThird::s_value {1}; 


// class declarations
class IDGenerator {
private:
    static int s_next_id;

public:
    static int get_next_id();
};


// class definitions
int IDGenerator::s_next_id {1};

int IDGenerator::get_next_id() {
    return s_next_id++;
}


// can initialise by executing code using lambdas
class MyClass {
public:
    static std::vector<char> s_my_chars;
};


std::vector<char> MyClass::s_my_chars {
    [] { // inside lambda declare vector and loop
        std::vector<char> v {};

        for (char ch {'a'}; ch <= 'z'; ++ch) {
            v.push_back(ch);
        }

        return v;
    } () // call lambda right away
};


int main() {
    Something first;
    Something second;

    // static members are shared between instances
    first.s_value = 2;

    std::cout << first.s_value << '\n';
    std::cout << second.s_value << '\n';

    SomethingElse first_e;
    SomethingElse second_e;
    SomethingElse third_e;

    std::cout << first_e.get_id() << '\n';
    std::cout << second_e.get_id() << '\n';
    std::cout << third_e.get_id() << '\n';

    std::cout << SomethingTheThird::get_value() << '\n';

    for (int count {0}; count < 5; ++count) {
        std::cout << "The next ID is: " << IDGenerator::get_next_id() << '\n';
    }

    return 0;
}
