#include <iostream>
#include <utility> // for std::swap

// can rewrite ugly syntax with using or std::function
/*
 * using ValidateFunction = bool(*)(int, int);
 * bool validate(int x, int y, ValidateFunction pfunc);
 * 
 * bool validate(int x, int y, std::function<bool(int, int)> func);
 */

// use function pointer to pass funtion to other function, can add default function as well
void selection_sort(int* array, int size, bool (*comparitor)(int, int) = ascending) {
// void selection_sort(int* array, int size, bool comparitor(int, int)) // can be rewritten like so, but ONLY for function params
    // Step through each element of the array
    for (int start_index {0}; start_index < (size - 1); ++start_index) {
        // smallest_index is the index of the smallest element we've encountered so far.
        int smallest_index {start_index};

        // Look for smallest element remaining in the array (starting at start_index+1)
        for (int currentIndex {start_index + 1}; currentIndex < size; ++currentIndex) {
            // If the current element is smaller than our previously found smallest
            if (comparitor(array[smallest_index], array[currentIndex])) { // COMPARISON DONE HERE
                // This is the new smallest number for this iteration
                smallest_index = currentIndex;
            }
        }

        // Swap our start element with our smallest element
        std::swap(array[start_index], array[smallest_index]);
    }
}

bool ascending(int x, int y) {
    return x > y;
}

bool descending(int x, int y) {
    return x < y;
}

// allows for custom sort order functions
bool evens_first(int x, int y) {
    // if x is even and y is odd, x goes first
    if ((x % 2) == 0 && !(y % 2 == 0)) {
        return false;
    }
    // if x is odd and y is even, y goes first
    if (!(x % 2 == 0) && (y % 2 == 0)) {
        return true;
    }
    // else
    return ascending(x, y);
}

void print_array(int* array, int size) {
    for (int index {0}; index < size; ++index) {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';
}

int main() {
    int array[9] {3, 7, 9, 5, 6, 1, 8, 2, 40};

    // pass comparison function to sorting function
    selection_sort(array, 9, descending);
    print_array(array, 9);

    selection_sort(array, 9, ascending);
    print_array(array, 9);

    selection_sort(array, 9, evens_first);
    print_array(array, 9);

    return 0;
}
