#include <algorithm> // for std::sort
#include <array> // for std::array
#include <chrono> // for std::chrono
#include <cstddef> // for std::size_t
#include <iostream>
#include <numeric> // for std::iota

const int g_array_elements {10000};


class Timer {
private:
    // type aliases for cleaner / easier code
    using clock_type = std::chrono::steady_clock;
    using second_type = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_type> m_beg {clock_type::now()};

public:
    void reset() {
        m_beg = clock_type::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
    }
};


// simple swap sort
void sort_array(std::array<int, g_array_elements>& array) {
    for (std::size_t start_index {0}; start_index < (g_array_elements - 1); ++start_index) {
        std::size_t smallest_index {start_index};

        for (std::size_t current_index {start_index + 1}; current_index < g_array_elements; ++current_index) {
            if (array[current_index] < array[smallest_index]) {
                smallest_index = current_index;
            }
        }

        std::swap(array[start_index], array[smallest_index]);
    }
}

int main() {
    std::array<int, g_array_elements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fill array with values 10000 to 1

    std::cout << "Begin swap sort...\n";
    Timer t;

    sort_array(array);

    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    std::array<int, g_array_elements> array_1;
    std::iota(array_1.rbegin(), array_1.rend(), 1);

    std::cout << "Begin std::sort...\n";
    t.reset();

    std::ranges::sort(array_1); // c++ 20

    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    return 0;
}
