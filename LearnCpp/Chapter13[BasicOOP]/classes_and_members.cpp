#include <iostream>
#include <string>
#include <vector>

// like python, define class. members and methods
// public keyword for accessible members
class DateClass {
public:
    int m_year {}; // use m_ to disern object member variables
    int m_month {};
    int m_day {};

    void print() {
        std::cout << m_year << '-' << m_month << '-' << m_day << '\n';
    }
};


class Employee {
public:
    std::string m_name {};
    int m_id {};
    double m_wage {};

    void print() {
        std::cout << "Name " << m_name << "\tID: " 
                << m_id << "\tWage: £" << m_wage << '\n';
    };
};


class Calculator {
public:
    using number_type = int; // nested type alias

    std::vector<number_type> m_result_history {};

    number_type add(number_type a, number_type b) {
        auto result {a + b};

        m_result_history.push_back(result);

        return result;
    }
};

// able to use later defined methods within a class unlike
// functions that need a forward declaration

int main() {
    DateClass today {2022, 05, 11}; // initalise class like struct objects

    today.m_day = 12; // access members with '.' notation
    today.print(); // same for methods

    Employee alex {"Alex", 1, 25.00};
    Employee joe {"Joe", 2, 22.25};

    alex.print();
    joe.print();

    Calculator calculator;

    std::cout << calculator.add(3, 4) << '\n';
    std::cout << calculator.add(99, 24) << '\n';

    for (Calculator::number_type result : calculator.m_result_history) { // can use nested type using '::'
        std::cout << result << '\n';
    }

    return 0;
}
