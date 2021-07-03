#include <iostream>

// operators said to have a side effect
// permanently changes the value of the variable
// can cause undefined behaviour if used in function arguments
int main() {
    int x {5};
    // x is incremented, x is returned, then x is assigned to y
    int y = ++x; 

    std::cout << "prefix ++, x = " << x << ", y = " << y << '\n';

    x = 5;
    // x is incremented, then original copy of x is assigned to z
    int z = x++;

    std::cout << "postfix ++, x = " << x << ", z = " << z << "\n\n";

    x = 5;
    y = 5;

    std::cout << "Original:\tx = " << x << ",\t\ty = " << y << '\n';
    // values incremented before being sent to cout
    std::cout << "Prefix:\t\t++x = " << ++x << ",\t--y = " << --y << '\n';
    std::cout << "After:\t\tx = " << x << ",\t\ty = " << y << '\n';
    // values incremented after being sent to cout
    std::cout << "Postfix:\tx++ = " << x++ << ",\ty-- = " << y-- << '\n';
    std::cout << "After:\t\tx = " << x << ",\t\ty = " << y << '\n';
    
    return 0;
}
