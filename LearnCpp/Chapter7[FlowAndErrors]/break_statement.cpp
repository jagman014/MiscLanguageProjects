#include <iostream>

void print_maths(int x, int y, char ch) {
    switch (ch) {
    case '+':
        std::cout << x << " + " << y << " = " << x + y << '\n';
        break; // break statement in switch statments prevent fallthrough
    
    case '-':
        std::cout << x << " - " << y << " = " << x - y << '\n';
        break;

    case '*':
        std::cout << x << " * " << y << " = " << x * y << '\n';
        break;
    
    case '/':
        std::cout << x << " / " << y << " = " << x / y << '\n';
        break;
    }        
}

int main() {
    print_maths(2, 3, '+');

    // can use break to exit a loop early
    int sum {0};

    for (int count {0}; count <= 10; ++count) {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num {};
        std::cin >> num;

        if (num == 0) {
            break;
        }
        
        sum += num;
    }

    std::cout << "Total sum: " << sum << '\n';

    while (true) {
        std::cout << "Enter 0 to exit, or anything else to continue: ";
        int num {};
        std::cin >> num;

        if (num == 0) {
            break;
        }
    }

    std::cout << "We're out of the loop\n";    

    return 0;
}
