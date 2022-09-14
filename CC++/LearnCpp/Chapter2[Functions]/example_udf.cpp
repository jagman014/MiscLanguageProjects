#include <iostream>

// example udf, void type doesn't return a value
void do_print() {
    std::cout << "in do_print()\n";
}

int main() {
    std::cout << "start main()\n";

    // main will call function when running program
    do_print();
    do_print();

    std::cout << "end main()";

    return 0;
}
