#include <iostream>
#include <iterator> // for std::size()

// can loop through arrays like python lists
// check loop conditions for off-by-one errors -> undefined behaviour

int main() {
    int scores[] {84, 92, 76, 81, 56};
    int num_students {static_cast<int>(std::size(scores))};
    int total_score {0};
    int max_score {0};

    // loop to sum scores
    for (int student {0}; student < num_students; ++student) {
        total_score += scores[student];
    }

    auto average_score {static_cast<double>(total_score) / num_students};

    // loop to get max score
    for (int student {0}; student < num_students; ++student) {
        if (scores[student] > max_score) {
            max_score = scores[student];
        }
    }

    std::cout << "The average score was: " << average_score << '\n';
    std::cout << "The top score was: " << max_score << '\n';

    return 0;
}
