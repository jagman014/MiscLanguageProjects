#include <iostream>

// implicit conversion, aka coercion
// performed automatically by the compiler, when a different type is supplied
// if a conversion is not available there will be a compile error

float do_something() {
    return 3.0; // return value implicitly converted from double to float
}

void do_thing(long l) {

}

int main() {
    double d {3}; // 3 and 6 are implicitly converted from ints to doubles
    d = 6;

    double div {4.0 / 3}; // 3 converted from int to double

    if (5) {
        // 5 converted from int to bool
    }

    do_thing(4); // converted from int to long

    int x {3.5}; 
    // brace-init disallows loss of data during initialisation, error raised

    return 0;
}
