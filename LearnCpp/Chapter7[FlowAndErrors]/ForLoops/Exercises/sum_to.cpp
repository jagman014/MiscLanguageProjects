#include <iostream>

// returns the sum of the integers up to and including n
int sum_to(int n) {
    int sum {};

    // faster to return (n * (n + 1)) / 2
    for (int i {1}; i <= n; ++i) {
        sum += i;
    }

    return sum;
}

int main() {
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    std::cout << "Sum from 1 to " << x << " is " << sum_to(x) << '\n';

    return 0;
}
