#include "Cents.h"

#include <iostream>

int main() {
    Cents cents_1 {6};
    Cents cents_2 {8};
    Cents cents_sum {cents_1 + cents_2}; // needs prototype from Cents.h

    std::cout << "I have " << cents_sum.get_cents() << " cents total\n";

    return 0;
}

