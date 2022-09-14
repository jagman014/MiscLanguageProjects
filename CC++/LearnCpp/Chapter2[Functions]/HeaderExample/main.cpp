// compile with "g++ -Wall -Werror -o main main.cpp add.cpp"
// header file added via #include and quotes instead of forward declaration
// best practice udf > 3rd party > std
#include "add.h"
#include <iostream>

int main() {
    std::cout << "Sum of 3 and 4 is " << add(3, 4) << '\n';

    return 0;
}
