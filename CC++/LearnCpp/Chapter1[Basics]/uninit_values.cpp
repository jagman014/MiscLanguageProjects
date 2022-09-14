// compiling with -Wall and -Werror flag warning as an error
#include <iostream>

int main() {
    int x;

    // x is uninitialised, will output any unassigned int value
    std::cout << x;

    return 0;
}
