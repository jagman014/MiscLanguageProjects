#include <algorithm> // for std::sort()
#include <iostream>
#include <iterator> // for std::size()
#include <utility> // for std::swap()

int main() {
    int x {2};
    int y {4};

    // simple variable-value swap
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << "\n\n";

    // selection sort arrays
    int array[] {30, 50, 20, 10, 40};
    constexpr int length {static_cast<int>(std::size(array))};

    // print before
    std::cout << "array before: \n\t";
    for (int index {0}; index < length; ++index) {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';

    // step through every element of the array, except the last
    for (int start_index {0}; start_index < (length - 1); ++start_index) {
        // index of smallest element for this iteration
        int smallest_index {start_index};

        // look for smaller element in the rest of the array
        for (int current_index {start_index + 1}; 
                current_index < length; ++current_index) {
            // if element is less than current smallest
            if (array[current_index] < array[smallest_index]) {
                // keep track of smallest
                smallest_index = current_index;
            }

        }
        
        // smallest index is now smallest element for this loop
        // swap with starting element of iteration
        std::swap(array[start_index], array[smallest_index]);

    }

    // print array to show it worked
    std::cout << "array after: \n\t";
    for (int index {0}; index < length; ++index) {
        std::cout << array[index] << ' ';
    }

    std::cout << "\n\n";

    int array_1[] {30, 50, 20, 10, 40};

    std::cout << "array before: \n\t";
    for (int index {0}; index < length; ++index) {
        std::cout << array_1[index] << ' ';
    }
    
    std::cout << '\n';

    std::sort(std::begin(array_1), std::end(array_1));

    std::cout << "array after: \n\t";
    for (int index {0}; index < length; ++index) {
        std::cout << array_1[index] << ' ';
    }

    std::cout << '\n';

    return 0;
}
