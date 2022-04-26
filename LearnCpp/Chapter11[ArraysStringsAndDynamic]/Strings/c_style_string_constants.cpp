#include <iostream>

// can consolidate similar literal string values
// literal strings have static duration
const char* get_name() {
    return "Jag";
}

int main() {
    char name[] {"Jag"}; // fixed array C-style
    std::cout << name << '\n';

    const char* name_1 {"Jag"}; // pointer to symbolic constant, C++
    std::cout << name_1 << '\n';

    // cout and pointers
    int n_array[5] {9, 7, 5, 3, 1};
    char c_array[] {"Hello!"};
    const char* name_2 {get_name()};

    std::cout << n_array << '\n'; // decays to type int*
    std::cout << c_array << '\n'; // decays to type char*
    std::cout << name_2 << '\n'; // already type char*

    // std::cout assumes char* -> print string
    // else print contents of pointer

    // leads to unexpected behaviour when printing address of chars
    // &c is of type char*, prints till \0 or out of memory
    char c {'Q'};
    std::cout << &c;

    return 0;
}
