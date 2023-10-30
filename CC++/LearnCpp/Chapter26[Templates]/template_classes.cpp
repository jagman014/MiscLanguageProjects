#include <iostream>
#include "Array.h"

int main() {
    Array<int> int_array {12};
    Array<double> double_array {12};

    for (int count {0}; count < int_array.get_length(); ++count) {
        int_array[count] = count;
        double_array[count] = count + 0.5;
    }

    for (int count {int_array.get_length() - 1}; count >= 0; --count) {
        std::cout << int_array[count] << '\t' << double_array[count] << '\n';
    }

    return 0;
}
