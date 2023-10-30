#include <algorithm> // for std::max
#include <cmath>     // for std::abs
#include <iostream>

/*
>, greater than
<, less than
>=, greater than or equal
<=, less than or equal
==, equal
!=, not equal
avoid using == and != with floating point numbers due to imprecision
*/

// better solution for equating floats:
// giving a threshold to equality
bool is_almost_equal(double a, double b, double epsilon) {
    // delta(a, b) <= epsilon -> close enough for threshold
    // multiply by max to scale epsilon as proportional threshold
    double threshold {std::max(std::abs(a), std::abs(b)) * epsilon};
    return (std::abs(a - b) <= threshold);
}

// relative threshold breaks down near zero, require absolute threshold
bool approx_equal_abs_rel(double a, double b, 
                            double abs_epsilon, double rel_epsilon) {
    double diff {std::abs(a - b)};
    if (diff <= abs_epsilon) {
        return true;
    }

    double threshold {std::max(std::abs(a), std::abs(b)) * rel_epsilon};
    return diff <= threshold;
}

int main() {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
 
    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;
 
    if (x == y)
        std::cout << x << " equals " << y << '\n';
    if (x != y)
        std::cout << x << " does not equal " << y << '\n';
    if (x > y)
        std::cout << x << " is greater than " << y << '\n';
    if (x < y)
        std::cout << x << " is less than " << y << '\n';
    if (x >= y)
        std::cout << x << " is greater than or equal to " << y << '\n';
    if (x <= y)
        std::cout << x << " is less than or equal to " << y << "\n\n";

    double a {0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 +0.1 + 0.1};
    
    std::cout << is_almost_equal(a, 1.0, 1e-8) << '\n';
    std::cout << is_almost_equal(a - 1.0, 0.0, 1e-8) << '\n';
    std::cout << approx_equal_abs_rel(a - 1.0, 0.0, 1e-12, 1e-8) << '\n';

    return 0;
}
