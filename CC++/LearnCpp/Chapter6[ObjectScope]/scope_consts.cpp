#include <iostream>

// best to call globals with g_ prefix
int g_x; // global variables are zero initialised
const int g_y {4}; // must initialise constant variables

void do_something() {
    // global vairables can be seen anywhere in the file
    std::cout << "g_x: " << g_x << '\n';
    std::cout << "g_y: " << g_y << '\n';
}

int main() {
    // local variable, only visable within the block it is defined in
    int x {3};
    std::cout << "x: " << x << '\n';

    {
        // local nested variable defined with same label as outer scope
        int x {2};
        std::cout << "nested x: " << x << '\n';
    } // nested x destroyed

    std::cout << "x: " << x << '\n';

    do_something();

    return 0;
} // local x destroyed, globals destroyed
