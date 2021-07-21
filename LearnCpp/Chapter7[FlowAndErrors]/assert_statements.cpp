#include <cassert> // for assert()
#include <cmath> // for std::sqrt()
#include <iostream>

// compile time asserts available -> static_assert keyword
// static_assert(condition, error_message)

double calculate_fall_time(double height, double gravity) {
    assert(gravity > 0.0); 
    // assertion statement, calls std::abort when false
    // returns file and line where assertion error occured

    if (height <= 0.0) {
        return 0;
    }

    return std::sqrt((2.0 * height) / gravity);
}

int main() {
    std::cout << "Took " << calculate_fall_time(100, -9.8) << " s\n";

    return 0;
}
