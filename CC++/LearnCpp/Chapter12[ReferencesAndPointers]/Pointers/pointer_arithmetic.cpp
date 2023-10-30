#include <iostream>

// can perform integer addition and subtraction on pointers
// will return the previous or next location in memory
// change in value of memory will be scaled by the type of the pointer
// i.e. char +/- 1 byte, int +/- 4 bytes

int main() {
    int value {7};
    int* iptr {&value};

    std::cout << "int*\n";
    std::cout << iptr << '\n'; // memory values differ by 4 bytes
    std::cout << iptr + 1 << '\n';
    std::cout << iptr + 2 << '\n';
    std::cout << iptr + 3 << '\n';

    short svalue {7};
    short* sptr {&svalue};

    std::cout << "short*\n";
    std::cout << sptr << '\n'; // memory values differ by 2 bytes
    std::cout << sptr + 1 << '\n';
    std::cout << sptr + 2 << '\n';
    std::cout << sptr + 3 << '\n';

    return 0;
}
