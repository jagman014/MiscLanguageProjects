#include <iostream>
#include <typeinfo> // for typeid()

// arithmetic, relational, and bitwise operators
// require operands of the same type
// type of lower priority is converted to the higher type (or promoted)

// **typeid.name is compiler dependent**
// **for g++, pipe into c++filt to demangle**
// **a.exe | c++filt -t**

int main() {
    int i {2};
    double d {3.5};

    // shows type of int + double -> double
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n';

    short a {4};
    short b {5};

    // shows type of short + short -> int
    std::cout << typeid(a + b).name() << ' ' << a + b << '\n';

    // hierachy issues when mixing signed and unsigned
    std::cout << typeid(5u - 10).name() << ' ' << 5u - 10 << '\n';

    // negative signed int convered to unsigned int
    std::cout << std::boolalpha << (-3 < 5u);

    return 0;
}
