#include <iostream>

// best to avoid variable shadowing

int val {5};

void foo() {
    std::cout << "Global value: " << val << '\n';
}

int main() {
    int apples {5}; // outer block variable

    { // nested block
        std::cout << apples << '\n'; // prints outer variable

        int apples {0}; // inner block variable, shadows outer variable

        apples = 10; // assignment to inner block variable

        std::cout << apples << '\n'; // prints nested variable
    } // inner variable destroyed

    std::cout << apples << "\n\n"; // prints outer variable

    foo();

    int val {7}; // variable shadows global val

    std::cout << "Local variable: " << val << '\n';

    ++val; // increments local variable

    std::cout << "Local variable: " << val << '\n';

    --(::val); // decrements global variable

    foo();

    return 0;
}
