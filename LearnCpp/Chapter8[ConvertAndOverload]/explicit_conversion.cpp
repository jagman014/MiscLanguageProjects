#include <iostream>

// explicitly casting variable to another castable type
// looking mainly at c-style and static casting

int main() {
    int x {10};
    int y {4};

    // c-style casting using (<type>)<variable>
    double d {(double)x / y}; // convert x to double, floating point division
    std::cout << d << '\n';

    // c++ version of c-style allows function like use
    // better to use this than the pure c-style cast
    double d1 {double(y) / x};
    std::cout << d1 << '\n';

    // static cast, less powerful than c-style, but safer
    // allows for errors to be caught by compiler
    char c {'a'};
    std::cout << c << ' ' << static_cast<int>(c) << '\n';

    // use of static cast stops compiler errors occuring
    // as the casting is explicit
    int i {48};
    char ch {static_cast<char>(i)};

    std::cout << "i " << i << " ch(i) " << ch << '\n';

    int i1 {100};
    i1 = static_cast<int>(i1 / 2.5);

    std::cout << "int(100 / 2.5) " << i1 << '\n';

    return 0;
}
