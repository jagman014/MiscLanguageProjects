#include <iostream>

// forward declaration of function prototype
int add(int x, int y);

// can then call main before the function
int main() {
    std::cout << "Sum of 3 and 4 is " << add(3, 4) << '\n';

    return 0;
}

// then define function
int add(int x, int y) {
    return x + y;
}
