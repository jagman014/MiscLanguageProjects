#include <iostream>

// five basic types of numeric conversion
// may result in a loss of data 
// depending on the conversion (i.e. double to int)
// best to explicitly static_cast when conversion narrows the value

int main() {
    // integral to integral (excluding promotions)
    short s = 3; // int to short
    long l = 3; // int to long
    char ch = s; // short to char

    // floating point to floating point (excluding promotions)
    float f = 3.0; // double to float
    long double ld = 3.0; // double to long double

    // floating point to integral
    int i = 3.5; // double to int

    // integral to floating point
    double d = 3; // int to double

    // integral / floating point to bool
    bool b1 = 3; // int to bool
    bool b2 = 3.0; // double to bool

    return 0;
}
