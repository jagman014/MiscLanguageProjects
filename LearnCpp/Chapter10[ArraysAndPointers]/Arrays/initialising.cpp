#include <iostream>

// can initalise arrys just like python lists

// can use enum classes, however need to use static_cast
// simpler to use a namespace and standard enum
namespace student_names{
    enum student_names {
        alice,
        bob,
        charlie,
        debbie,
        ellie,
        max_students,
    };
}

int main() {
    int primes[5] {2, 3, 5, 7, 11}; // first five primes

    int array[5] {7, 4, 5}; // initialise the first three elements

    std::cout << array[0] << '\n';
    std::cout << array[1] << '\n';
    std::cout << array[2] << '\n';
    std::cout << array[3] << '\n';
    std::cout << array[4] << '\n';

    // best to include an initialiser
    int array_1[5] {}; // initialise all values to zero
    int array_2[5]; // uninitialised

    // can omit the length of the array, init list with set the length
    int array_3[5] {0, 1, 2, 3, 4};
    int array_4[] {0, 1, 2, 3, 4};

    // can use enums to give meaning to indices
    int test_scores[student_names::max_students] {};
    test_scores[student_names::bob] = 76;

    return 0;
}
