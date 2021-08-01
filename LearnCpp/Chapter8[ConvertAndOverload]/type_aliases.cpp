#include <iostream>

// aliases are subject to scoping rules just like variables
// can be included in a header file to be imported with global scope
// best to use the "using" syntax
// can use "typedef <type> <alias>", but can get difficult to read

int main() {
    // alias type with using keyword, best to as _t suffix
    // this doesn't define a new type, only aliases the type
    using distance_t = double;

    // define variable of type double
    distance_t miles_to_destination {3.4};

    std::cout << miles_to_destination << '\n'; // prints double value

    // can have sytactically valid but sematically invalid code
    using miles_t = long;
    using speed_t = long;

    // both are just renamed longs
    miles_t distance {5};
    speed_t mph {3200};

    // possible, but semantically wrong
    distance = mph; 

    return 0;
}
