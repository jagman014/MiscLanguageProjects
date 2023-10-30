#include <iostream>

int main() {
    int count {1};

    while (count <= 50) {
        // using if statments allow control for certain interations
        if (count < 10) {
            std::cout << '0'; // pad with inital zero if less than 10
        }

        std::cout << count << ' ';

        if (count % 10 == 0) {
            // multiples of ten produce a new line
            std::cout << '\n';
        }

        ++count;
    }

    return 0;
}
