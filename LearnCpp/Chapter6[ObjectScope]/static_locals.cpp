#include <iostream>

// static local variables keep their value 
// after the block of code that inits them
// are created at program start, and destroyed at program end
void increment_and_print() {
    // prefixed static local variables with s_
    static int s_val {1}; // initialisation only occurs once
    ++s_val;
    std::cout << s_val << '\n';
    // avoid static locals, unless value doesn't need to be reset
}

int main() {
    increment_and_print();
    increment_and_print();
    increment_and_print();

    return 0;
}
