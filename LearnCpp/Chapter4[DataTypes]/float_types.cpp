#include <iostream>
#include <iomanip> // std::setprecision
// floating point numbers are always signed
float f_val; // typically 4 bytes, +/- 10^(+/- 38), 6-9 s.f.
double d_val; // 8 bytes, +/- 10^(+/- 308), 15-18 s.f.
long double ld_val; // 8, 12, or 16 bytes, +/- 10^(+/- 4932), 18-36 s.f.

// decimal literals default to double precision
int x {5}; // literal int
double y {5.0}; // literal float, default to double
float z {5.0f}; // literal float, f states float type

// printing floats
int main() {
    std::cout << 5.0 << '\n'; // prints '5', drops zero fractional parts
    std::cout << 6.7 << '\n'; // prints '6.7'
    std::cout << 9876543.21 << "\n\n"; // prints '9.87654e+006

    // std::cout truncates floats to 6 s.f. by default
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << "\n\n";

    // can override default precision
    std::cout << std::setprecision(16);
    std::cout << 3.33333333333333333333333333333333333333f << '\n';
    std::cout << 3.33333333333333333333333333333333333333 << "\n\n";
    
    // choice of data type can lead to a loss of precison
    // best to use doubles over floats
    
    // floating point errors can also occur easily
    double d {0.1};
    std::cout << d << '\n';
    std::cout << std::setprecision(17);
    std::cout << d << "\n\n";

    double d1 {1.0};
    std::cout << d1 << '\n';

    double d2 {0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1};
    std::cout << d2 << "\n\n"; // should be 1

    // Inf a special floating point number, try to avoid zero division
    double zero {0.0};
    double posinf {1.0 / zero}; // positive infinity
    std::cout << posinf << '\n';

    double neginf {-1.0 / zero}; // negative infinity
    std::cout << neginf << '\n';

    double nan {zero / zero}; // not a number, undefined
    std::cout << nan << '\n';

    return 0; 
}
