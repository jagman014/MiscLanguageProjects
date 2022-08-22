#include <iostream>


class Something {
public:
    int m_value {};

    Something()
    : m_value {0} {}

    void set_value(int value) {
        m_value = value;
    }

    // const required so const object can still call
    // cannot have const on modifying methods
    int get_value() const {
        return m_value;
    }
};


// same thing for when passing by const reference
// non-modifying methods need const keyword
class Date {
private:
    int m_year {};
    int m_month {};
    int m_day {};

public:
    Date(int year, int month, int day) {
        set_date(year, month, day);
    }

    void set_date(int year, int month, int day) {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    int get_year() const {
        return m_year;
    }

    int get_month() const {
        return m_month;
    }

    int get_day() const {
        return m_day;
    }
};


void print_date(const Date& date) {
    std::cout << date.get_year() << '-' << date.get_month()
            << '-' << date.get_day() << '\n';
}

int main() {
    const Something something {};

    something.m_value = 5; // compiler error, modifies const
    something.set_value(5); // compiler error, modifies const

    std::cout << something.get_value() << '\n';

    Date date {2022, 8, 22};
    print_date(date);

    return 0;
}
