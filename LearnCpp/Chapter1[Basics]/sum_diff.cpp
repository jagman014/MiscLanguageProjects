#include <iostream>

int main() {
    std::cout << "Enter two integers serparated by a space: ";

    int x {}, y {};
    std::cin >> x >> y;

    std::cout << x << " + " << y << " is " << x + y << '\n';
    std::cout << x << " - " << y << " is " << x - y << '\n';

    return 0;
}
