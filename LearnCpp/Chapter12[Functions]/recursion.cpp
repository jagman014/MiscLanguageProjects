#include <iostream>
#include <vector>

void count_down(int count) {
    std::cout << "push " << count << '\n';

    if (count > 1) { // termination condition, avoids infinite calls
        count_down(count - 1); // recursive, calls self
    }

    std::cout << "pop " << count << '\n';
}

// sum value from 1 up to val inclusive
// return 0 for negative numbers
int sum_to(int val) {
    if (val <= 0) {
        return 0; // base case
    }
    else if (val == 1) {
        return 1; // normal case
    }
    else {
        return sum_to(val - 1) + val; // recursive call
    }
}

// inificient, calls function twice for each non-base case
int fibonacci(int count) { 
    if (count == 0) {
        return 0;
    }
    if (count == 1) {
        return 1;
    }
    return fibonacci(count - 1) + fibonacci(count - 2);
}

// more efficient memorisation method
int fibonacci_(int count) {
    static std::vector<int> results {0, 1}; // cache results already seen

    if (count < static_cast<int>(std::size(results))) {
        return results[count];
    }
    else {
        results.push_back(fibonacci_(count - 1) + fibonacci_(count -2));
        return results[count];
    }
}

int main() {
    count_down(5);

    std::cout << "sum_to(5) = " << sum_to(5) << '\n';

    for (int count {0}; count < 13; ++count) {
        std::cout << fibonacci(count) << ' '; // results in 1205 calls
    }
    std::cout << '\n';

    for (int count {0}; count < 13; ++count) {
        std::cout << fibonacci_(count) << ' '; // results in 35 calls
    }
    std::cout << '\n';

    return 0;
}
