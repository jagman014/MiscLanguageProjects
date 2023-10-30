#include <iostream>


class Base {
public:
    int m_id {};

    Base(int id=0)
    : m_id {id} {
        std::cout << "Base\n";
    }

    int get_id() const {
        return m_id;
    }
};


class Derived: public Base {
public:
    double m_cost {};

    Derived(double cost=0.0)
    : m_cost {cost} {
        std::cout << "Derived\n";
    }

    double get_cost() const {
        return m_cost;
    }
};


class A {
public:
    A() {
        std::cout << "A\n";
    }
};


class B: public A {
public:
    B() {
        std::cout << "B\n";
    }
};


class C: public B {
public:
    C() {
        std::cout << "C\n";
    }
};


class D: public C {
public:
    D() {
        std::cout << "D\n";
    }
};


int main() {
    std::cout << "Instantiating Base\n";
    Base base;

    // derived class instantiates from the base to the most child
    std::cout << "Instantiating Derived\n";
    Derived derived;

    std::cout << "Constructing A\n";
    A a;

    std::cout << "Constructing B\n";
    B b;

    std::cout << "Constructing C\n";
    C c;

    std::cout << "Constructing D\n";
    D d;

    return 0;
}
