#include "bar.h"
#include "foo.h"
#include <iostream>
// require defined namespace to destinguish functions
// resolve namespace via scope resolution operator "::"

int main() {
    std::cout << "foo namespace: " << foo::do_something(4, 3) << '\n';
    std::cout << "bar namespace: " << bar::do_something(4, 3) << '\n';

    return 0;
}
