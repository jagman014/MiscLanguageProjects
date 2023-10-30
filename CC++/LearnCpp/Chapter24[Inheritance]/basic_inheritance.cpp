#include <iostream>
#include <string>


class Person {
public:
    std::string m_name {};
    int m_age {};

    Person(const std::string& name="", int age=0)
    : m_name {name}
    , m_age {age} {}

    const std::string& get_name() const {
        return m_name;
    }

    int get_age() const {
        return m_age;
    }
};


// BaseballPlayer publicly inherits from Person
class BaseballPlayer: public Person {
public:
    double m_batting_average {};
    int m_home_runs {};

    BaseballPlayer(double batting_average=0.0, int home_runs=0)
    : m_batting_average {batting_average}
    , m_home_runs {home_runs} {}
};


// Employee publicly inherits from Person
class Employee: public Person {
public:
    double m_hourly_salary {};
    long m_employee_id {};

    Employee(double hourly_salary=0.0, long employee_id=0)
    : m_hourly_salary {hourly_salary}
    , m_employee_id {employee_id} {}

    void print_name_and_salary() const {
        std::cout << m_name << ": " << m_hourly_salary << '\n';
    }
};


// Supervisor inherits from Employee
class Supervisor: public Employee {
public:
    // oversees a max of 5 employees
    long m_oversees_ids[5] {};
};


// Person <- Employee <- Supervisor [inheritance chain]
//        ^- BaseballPlayer
int main() {
    BaseballPlayer joe {};
    joe.m_name = "Joe"; // object inherits all public attributes

    std::cout << joe.get_name() << '\n';

    Employee frank {20.25, 12345};
    frank.m_name = "Frank";

    frank.print_name_and_salary();

    return 0;
}
