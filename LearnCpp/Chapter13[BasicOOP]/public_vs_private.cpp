#include <iostream>

struct DateStruct { // public members by default
    int day {};
    int month {};
    int year {};
};


class DateClass { // private members by default
    int m_day {};
    int m_month {};
    int m_year {};

public: // add specifier to allow public access, best practice use getters / setters
    void set_date(int day, int month, int year) {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    void print() {
        std::cout << m_year << '-' << m_month << '-' << m_day;
    }

    // access works on a per-class basis, not per-object
    // allows access tp private variables of one object from another of the same class
    void copy_from(const DateClass& d) {
        m_day = d.m_day;
        m_month = d.m_month;
        m_year = d.m_year;
    }
};


int main() {
    DateStruct date; // public members can be accessed by anyone
    date.day = 21;
    date.month = 8;
    date.year = 2022;

    DateClass date_1; // private members can only be accessed within the class
    date_1.set_date(21, 8, 2022);
    date_1.print();
    std::cout << '\n';

    DateClass copy;
    copy.copy_from(date_1);
    copy.print();
    std::cout << '\n';

    return 0;
}
