#include <iostream>

int main() {
    for (int count{0}; count < 10; ++count) {
        if (count % 4 == 0) {
            continue; // skips current iteration
        }

        std::cout << count << '\n';

        // continue jumps to here
    }

    return 0;
}
