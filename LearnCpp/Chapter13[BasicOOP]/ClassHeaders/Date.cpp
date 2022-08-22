#include "Date.h"

// class constructor
Date::Date(int year, int month, int day) {
    set_date(year, month, day);
}

// member function
void Date::set_date(int year, int month, int day) {
    m_year = year;
    m_month = month;
    m_day = day;
}
