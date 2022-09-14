#include <iostream>
#include <string>

int main() {
    constexpr int fibonacci[] {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    
    // iterate over array, similar to python: for x in y
    for (auto number : fibonacci) { // good use for auto as declaration needs to match type given
        std::cout << number << ' ';
    }

    std::cout << '\n';

    std::string array[] {"peter", "likes", "frozen", "yogurt"};

    // use of references for non-fundamental types, as less expensive than copies
    for (auto& element : array) { 
        std::cout << element << ' ';
    }

    std::cout << '\n';

    // for-each doesn't work with array pointers, don't know array length

    // can enumerate for-each loops with an init statement
    std::string names[] {"Alex", "Betty", "Caroline", "Dave", "Emily"};
    constexpr int scores[] {84, 92, 76, 81, 56};
    int max_score {0};

    for (int i {0}; auto score : scores) {
        if (score > max_score) {
            std::cout << names[i] << " beat previous best of " << max_score
                << " by " << (score - max_score) << " points\n";
            max_score = score;
        }
        ++i;
    }

    std::cout << "The best score was " << max_score << '\n';

    return 0;
}
