#include <iostream>

// using boolean return values
bool is_equal(int x, int y) {
    return (x == y);
}

int main() {
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    // can use if statement for conditional use
    // set in block to allow for multiple lines
    if (x > 0) {
        std::cout << "The value is positive\n";
    }
    else if (x < 0)
    {
        std::cout << "The value is negative\n";
    }
    else {
        std::cout << "The value is non-zero\n";
    }

    std::cout << "Enter another integer: ";
    int y {};
    std::cin >> y;

    // returned bool type
    if (is_equal(x, y)) {
        std::cout << x << " and " << y << " are equal\n";
    }
    else {
        std::cout << x << " and " << y << " are not equal\n";
    }

    // can also use non-boolean conditionals, as any non-zero value is true

    return 0;
}
