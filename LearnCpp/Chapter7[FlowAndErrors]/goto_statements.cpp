#include <iostream>
#include <cmath>

// unconditional jump, best to avoid as there are better alternatives

// goto statements and statement labels have function scope
void print_cats(bool skip) {
    if (skip) {
        goto end;
    }

    std::cout << "cats";

end:
    ; // null statement, label must have a statement
    // can jump forward, however cannot jump over variable initialisations
}

int main() {
    double x {};

try_again: // statement label
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0) {
        goto try_again; // goto -> statement label
    }
    
    std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';

    print_cats(true);
    print_cats(false);

    return 0;
}
