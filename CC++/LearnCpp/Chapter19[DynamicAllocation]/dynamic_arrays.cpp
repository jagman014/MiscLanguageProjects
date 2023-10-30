#include <iostream>

int main() {
    std::cout << "Enter a positve integer: ";
    int length {};
    std::cin >> length;

    int* array {new int[length] {}}; // use of array new

    std::cout << "just allocated an array of length " << length << '\n';

    array[0] = 5;

    delete[] array; // array delete
    array = nullptr;

    // since C++11 can initalise dynamic arrays like fixed arrays
    int* arr {new int[5] {1, 2, 3, 4, 5}};
    std::cout << arr[0] << '\n';

    return 0;
}
