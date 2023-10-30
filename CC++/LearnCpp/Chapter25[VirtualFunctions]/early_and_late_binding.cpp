#include <iostream>

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int main() {
    int x {};
    std::cout << "Enter a number: ";
    std::cin >> x;

    int y {};
    std::cout << "Enter another: ";
    std::cin >> y;

    int op {};
    do {
        std::cout << "Enter an operation (0=add, 1=subtract, 2=multiply): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    int result {};

    // calls to the target function using early binding
    // compiler replaces the function calls with a jump to the function address
    switch (op) {
        case 0:
            result = add(x, y);
            break;
        case 1:
            result = subtract(x, y);
            break;
        case 2:
            result = multiply(x, y);
            break;
    }

    std::cout << "The result is " << result << '\n';

    // late binding via function pointer, compiler doesn't know when the function will be called
    std::cout << "Enter a number: ";
    std::cin >> x;

    std::cout << "Enter another: ";
    std::cin >> y;

    do {
        std::cout << "Enter an operation (0=add, 1=subtract, 2=multiply): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    // function pointer
    int (*p_fcn)(int, int) {nullptr};

    // assign function to pointer
    switch (op) {
        case 0:
            p_fcn = add;
            break;
        case 1:
            p_fcn = subtract;
            break;
        case 2:
            p_fcn = multiply;
            break;
    }

    // call to function uses late binding, less efficient
    std::cout << "The result is " << p_fcn(x, y) << '\n';

    return 0;
}
