#include <iostream>
#include <string>
#include <string_view>


class Base {
public:
    int m_id {};

    Base(int id)
    : m_id {id} {}
    
    int get_id() const {
        return m_id;
    }
};


class Derived: public Base {
public:
    double m_cost {};

    Derived(double cost=0.0, int id=0)
    : Base {id} // pass relevant arguments to the base class to init properly
    , m_cost {cost} {}

    double get_cost() const {
        return m_cost;
    }
};


class Person {
private:
    std::string m_name;
    int m_age {};

public:
    Person(const std::string_view name="", int age=0)
    : m_name {name}
    , m_age {age} {}

    const std::string& get_name() const {
        return m_name;
    }

    int get_age() const {
        return m_age;
    }
};


class BaseballPlayer: public Person {
private:
    double m_batting_average {};
    int m_home_runs {};

public:
    BaseballPlayer(
        const std::string_view name="", 
        int age=0, 
        double batting_average=0.0, 
        int home_runs=0
    )
    : Person {name, age}
    , m_batting_average {batting_average}
    , m_home_runs {home_runs} {}

    double get_batting_average() const {
        return m_batting_average;
    }

    int get_home_runs() const {
        return m_home_runs;
    }
};


// same applys to inheritance chains
class A {
public:
    A(int a) {
        std::cout << "A: " << a << '\n';
    }
};


class B: public A {
public:
    B(int a, double b) 
    : A {a} {
        std::cout << "B: " << b << '\n';
    }
};


class C: public B {
public:
    C(int a, double b, char c)
    : B {a, b} {
        std::cout << "C: " << c << '\n';
    }
};
// destructors are called in the reverse order to constructors


int main() {
    Derived derived {1.3, 5};

    std::cout << "Id: " << derived.get_id() << '\n';
    std::cout << "Cost: " << derived.get_cost() << '\n';

    BaseballPlayer pedro {"Pedro Cerrano", 32, 0.342, 42};

    std::cout << pedro.get_name() << '\n';
    std::cout << pedro.get_age() << '\n';
    std::cout << pedro.get_batting_average() << '\n';
    std::cout << pedro.get_home_runs() << '\n';

    C c {5, 4.3, 'R'};

    return 0;
}
