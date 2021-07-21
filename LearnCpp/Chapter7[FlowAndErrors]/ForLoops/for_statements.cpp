#include <iostream>

// for (init-statement; condition; end-expression)

// integer exponentials
int pow(int base, int exponent) {
    int total {1};

    for (int i {0}; i < exponent; ++i) {
        total *= base;
    }

    return total;
}

int main() {
    for (int count {1}; count <= 10; ++count) {
        std::cout << count << ' ';
    }

    std::cout << "\n2 ** 3 = " << pow(2, 3) << '\n';

    // end expression can be anything that modifies the loop variable
    for (int count {9}; count >= 0; --count) {
        std::cout << count << ' ';
    }

    std::cout << '\n';

    // init and end statements can be omitted 
    // if loop variable or increment exist in another manor
    for (int count {9}; count >= 0; count -= 2) {
        std::cout << count << ' ';
    }

    return 0;
}
