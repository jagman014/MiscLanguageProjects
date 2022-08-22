#include "Date.h"

#include <iostream>

int main() {
    Date date {2022, 8, 22};

    std::cout << date.get_year() << '-' << date.get_month() 
            << '-' << date.get_day() << '\n';

    return 0;
}
