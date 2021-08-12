#include <iostream>

// arrays allow for multiple values in the same variable
// <type> <name>[<size>] {};

// subscript arrays like python lists with [n], 
// and must be an intergral type -> char, int, bool, etc...
// as a compile time constant

// indexing outside of array indicies will give undefined behaviour
// instead of an error

int main() {
    int prime[5] {}; // hold the first five primes
    prime[0] = 2; // start at index zero
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11; // last element has index n-1    

    std::cout << "The lowest prime is: " << prime[0] << '\n';
    std::cout << "The sum of the first five primes is: "
                << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] 
                << '\n';

    // arrays can have any data type
    double battery_life_in_hours[3] {};
    battery_life_in_hours[0] = 2.0;
    battery_life_in_hours[1] = 3.0;
    battery_life_in_hours[2] = 4.3;

    std::cout << "The average battery life is: "
                << (battery_life_in_hours[0] 
                    + battery_life_in_hours[1]
                    + battery_life_in_hours[2]) / 3.0
                << '\n';
    
    // can also have an array of structs

    struct Rectangle {
        int length {};
        int width {};
    };

    Rectangle rects[5] {};
    rects[0].length = 24;

    return 0;
}   
