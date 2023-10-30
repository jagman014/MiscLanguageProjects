#include <iostream>
#include <string>
#include <string_view>


class Person {
private:
    std::string m_name;
    int m_age {};

public:
    Person(std::string_view name, int age)
    : m_name {name}
    , m_age {age} {}

    const std::string& get_name() const {
        return m_name;
    }

    int get_age() const {
        return m_age;
    }
};


class Employee {
private:
    std::string m_employer;
    double m_wage {};

public:
    Employee(std::string_view employer, double wage)
    : m_employer {employer}
    , m_wage {wage} {}

    const std::string& get_employer() const {
        return m_employer;
    }

    double get_wage() const {
        return m_wage;
    }
};


// Teacher publicly inherits from both Person and Employee
class Teacher: public Person, public Employee {
private:
    int m_teachers_grade {};

public:
    Teacher(
        std::string_view name,
        int age,
        std::string_view employer,
        double wage,
        int teachers_grade
    )
    : Person {name, age}
    , Employee {employer, wage}
    , m_teachers_grade {teachers_grade} {}
};

/* multiple inheritance can cause issues if:
 *     more than one inherited class share member / method names
 *     more than one inherited class share a parent class
 * Best to avoid if possible
 */
int main() {
    Teacher teacher {"Mary", 45, "Boo", 14.3, 8};

    std::cout << teacher.get_name() << ' ' << teacher.get_age() << ' '
        << teacher.get_employer() << ' ' << teacher.get_wage() << '\n';

    return 0;
}
