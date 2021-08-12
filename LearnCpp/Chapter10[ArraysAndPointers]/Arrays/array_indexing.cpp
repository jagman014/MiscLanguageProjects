#include <algorithm> // for std::count_if()
#include <iostream>
#include <iterator> // for std::size()

// arrays are laid out sequentially in memory,
// distance apart is equal to sizeof array type

bool is_vowel(char ch) {
    switch (ch) {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return true;
        
        default:
            return false;
    }
}


int main() {
    int array[] {9, 7, 5, 3, 1};

    // memory addresses separated by 4 bytes, sizeof(int)
    std::cout << "Element 0 has address: " << &array[0] << '\n';
    std::cout << "Element 1 has address: " << &array[1] << '\n';
    std::cout << "Element 2 has address: " << &array[2] << '\n';
    std::cout << "Element 3 has address: " << &array[3] << '\n';

    // combining with pointer arithmetic, allows for accessing other values
    // using the base array pointer
    std::cout << "&array[1] " << &array[1] << '\n';
    std::cout << "array + 1 " << array + 1 << '\n';

    // can also dereference to get array values
    std::cout << "array[1] " << array[1] << '\n';
    std::cout << "*(array + 1) " << *(array + 1) << '\n';

    // generally array[n] -> *(array + n)

    // can use a pointer to step through an array
    char name[] {"Mollie"};
    int array_length {static_cast<int>(std::size(name))};
    int num_vowels {0};

    for (char* ptr {name}; ptr != (name + array_length); ++ptr) {
        if (is_vowel(*ptr)) {
            ++num_vowels;
        }
    }

    std::cout << name << " has " << num_vowels << " vowels\n"; 

    // can replace the above look with the std::count_if function
    // std::begin and std::end return an iterator pointer
    // std::end returns the pointer to the last element + 1

    // only works if the array hasn't decayed,
    // otherwise need to calculate length manually
    // with (array + array_length), not (array + array_length - 1)

    char name_1[] {"Giacomo"};
    array_length = static_cast<int>(std::size(name_1));

    auto num_vowels_1 {
                std::count_if(std::begin(name_1), std::end(name_1), is_vowel)
    };

    std::cout << name_1 << " has " << num_vowels_1 << " vowels\n";

    return 0;
}
