#include <iostream>

// define default values in the same manor as python
// defaults must be the last in the list of params
// defaults can only be in either the function or forward def, not both
// best practice to have the default in the forward def (i.e. header file)

void print(int x, int y=4) { // y set to default value of four
    std::cout << "x " << x << '\n';
    std::cout << "y " << y << '\n';
}

// can have multiple default values

void print_2(int x=10, int y=20, int z=30) {
    std::cout << "Values: " << x << ' ' << y << ' ' << z << '\n';
}

int main() {
    print(1, 2);
    print(3);

    print_2(1, 2, 3);
    print_2(1, 2);
    print_2(1);
    print_2();

    return 0;
}
