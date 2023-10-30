#include <iostream>

int main() {
    int count {1}; 
    // iteration variables should be signed to avoid over / under flow

    // while condition is true execute statement / block
    while (count <= 10) {
        std::cout << count << ' ';
        ++count; // increment and assign count
    }

    // while (true) for infinite loops, require a break/return statement

    std::cout << "done!";

    return 0;
}
