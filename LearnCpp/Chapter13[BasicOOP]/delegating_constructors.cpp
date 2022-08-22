#include <iostream>
#include <string>
#include <string_view>


class Employee {
private:
    int m_id {};
    std::string m_name {};

public:
    Employee(int id=0, std::string_view name="")
    : m_id {id}
    , m_name {name} {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // delegated constructor, calls other constructor to minimise code
    Employee(std::string_view name)
    : Employee {0, name} {}
};


class Foo {
private:
    const int m_value {0};

    // setup method to be shared by constructors
    // can't intialise and share code between constructors
    void setup() {
        std::cout << "Setting things up...\n";
    }

public:
    Foo() {
        setup();
    }

    Foo(int value)
    : m_value {value} { // need to initalised m_value, can't delegate constructor
        setup();
    }
};


class Bar {
private:
    int m_a {1};
    int m_b {2};

public:
    Bar() {}

    Bar(int a, int b)
    : m_a {a}
    , m_b {b} {}

    void print() {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void reset() {
        // create default object then assign to overwrite members
        *this = Bar();
    }
};
