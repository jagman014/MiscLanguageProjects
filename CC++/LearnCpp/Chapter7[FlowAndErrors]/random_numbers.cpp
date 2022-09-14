#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()
#include <iostream>
#include <random> // for std::mt19937
#include "effolkronium/random.hpp" // use of header only external library

// use namespace to only declare mersenne seed once
namespace my_random {
    std::mt19937 mersenne 
                {static_cast<std::mt19937::result_type>(std::time(nullptr))};
}

// external library
using Random = effolkronium::random_static;

// simple example psuedo-random number generator
unsigned int PRNG() {
    // initial seed
    static unsigned int seed {5323};

    // generate next number using large numbers and overflow
    seed = 8253729 * seed + 2396403;

    // return values between 0 and 32767
    return seed % 32768;
}

// rand int function example
// generates between min and max inclusive
// assume std::srand() already called
// assume max - min <= RAND_MAX
int get_random_number(int min, int max) {
    // static used for efficiency, only calculated once
    static constexpr double fraction {1.0 / (RAND_MAX + 1.0)};

    // evenly distribute random number between range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

// better randint function using mersenne twister
int get_random_number_m(int min, int max) {
    std::uniform_int_distribution die {min, max};

    return die(my_random::mersenne);
}

int main() {
    // seed random values with current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::rand(); // initial call

    for (int count {1}; count <= 100; ++count) {
        std::cout << std::rand() << '\t';

        /*
        std::cout << PRNG() << '\t';
        */

        if (count % 5 == 0) {
            std::cout << '\n';
        }
    }

    std::cout << '\n';

    // initalise mersenne twister with clock seed
    // generates a 32-bit unsigned int, use std::mt19937_64 for 64-bit version
    /*
    std::mt19937 mersenne 
                {static_cast<std::mt19937::result_type>(std::time(nullptr))};
    */

    // create reusable uniform random number generator
    std::uniform_int_distribution die {1, 6};
    // need std::uniform_int_distribution<> die {1,6}; for less than C++17

    for (int count{1}; count <= 48; ++count) {
        std::cout << die(my_random::mersenne) << '\t'; // roll die

        if (count % 6 == 0) {
            std::cout << '\n';
        }
    }

    std::cout << '\n';

    // better rand int function
    std::cout << get_random_number_m(1, 6) << '\n';
    std::cout << get_random_number_m(1, 10) << '\n';
    std::cout << get_random_number_m(1, 20) << '\n';

    std::cout << '\n';

    // using external library
    std::cout << Random::get(1, 6) << '\n';
    std::cout << Random::get(1, 10) << '\n';
    std::cout << Random::get(1, 20) << '\n';

    return 0;
}
