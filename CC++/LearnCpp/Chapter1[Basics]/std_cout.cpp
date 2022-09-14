#include <iostream>

int main() {
    // output string to console using "<<" insertion operator
    std::cout << "Hello World\n";

    // output number to console
    std::cout << 4 << "\n";

    // direct list assignment of variable, printed to console
    int x {5};
    std::cout << x << "\n";

    // multiple << to concat
    std::cout << "Hello" << " world\n";
    std::cout << "x is equal to: " << x << "\n";

    return 0;
}
