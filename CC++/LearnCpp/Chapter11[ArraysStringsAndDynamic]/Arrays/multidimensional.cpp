#include <iostream>

// multidimensional arrays accessed like numpy arrays

/*
    // defined by two sets of array brackets, [row][col]
    int array[3][5] { 
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14}
    };

    // can ommit values, to have zero init
    int array_1[3][5] {
        {1, 2}, // same as {1, 2, 0, 0, 0}
        {6, 7, 8},
        {11, 12, 13, 14}
    };

    // can only omit the left most array index
    int array_2[][5] {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    // as always can zero init entire array
    int array_3[3][5] {};
*/

int main() {
    constexpr int num_rows {10};
    constexpr int num_cols {10};
    
    // declare 10x10 array
    int product[num_rows][num_cols] {};

    // calculate multiplication table
    for (int row {1}; row < num_rows; ++row) {
        for (int col {1}; col < num_cols; ++col) {
            product[row][col] = row * col;
        }
    }

    // print table
    for (int row {1}; row < num_rows; ++row) {
        for (int col {1}; col < num_cols; ++col) {
            std::cout << product[row][col] << '\t';
        }

        std::cout << '\n';
    }

    return 0;
}
