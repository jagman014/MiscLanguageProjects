#include <iostream>

// main calls do_a, which calls do_b
// cannot have nested functions
void do_b() {
    std::cout << "in do_b()\n";
}

void do_a() {
    std::cout << "start do_a()\n";

    do_b();

    std::cout << "end do_a()\n";
}

int main() {
    std::cout << "start main()\n";

    do_a();

    std::cout << "end main()";

    return 0;
}
