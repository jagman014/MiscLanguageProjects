#include <iostream>
#include <limits> // for std::numeric_limits

// purges the std::cin buffer
void ignore_line() {
    // ignores amount of chars until a specified char
    // std::numeric_limits gets the max of the std::streamsize to purge line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double get_double() {
    while (true) {
        std::cout << "Enter a double value: ";
        double x {};
        std::cin >> x;
        
        if (std::cin.fail()) { // has the previous extraction failed?
            std::cin.clear(); // reset operating mode of cin
            ignore_line(); // purge cin buffer
            std::cout << "Invalid value, try again\n";
        }
        else {
            ignore_line(); // purge cin buffer
            return x;
        }
    }
}

char get_operator() {
    while (true) { // input validation
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op {};
        std::cin >> op;
        ignore_line(); // purge cin buffer

        // check for meaningful input
        switch (op) {
            case '+':
            case '-':
            case '*':
            case '/':
                return op; // return to caller
            
            default: // flag error to user
                std::cout << "Invalid input, try again\n";
        }
    }
}

void print_results(double x, char op, double y) {
    switch (op) {
        case '+':
            std::cout << x << " + " << y << " is " << x + y << '\n';
            break;
        
        case '-':
            std::cout << x << " - " << y << " is " << x - y << '\n';
            break;

        case '*':
            std::cout << x << " * " << y << " is " << x * y << '\n';
            break;

        case '/':
            std::cout << x << " / " << y << " is " << x / y << '\n';
            break;
        
        default: // added robustness
            std::cerr << "Something went wrong:" 
                        << "print_result() got an invalid operator\n";
    }
}

int main() {
    double x {get_double()};
    char op {get_operator()};
    double y {get_double()};

    print_results(x, op, y);

    return 0;
}
