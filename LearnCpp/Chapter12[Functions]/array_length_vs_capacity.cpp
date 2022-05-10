#include <iostream>
#include <vector>

int main() {
    std::vector<int> array {0, 1, 2}; // initialised with length 3, capacity 3
    array.resize(5); // set length to 5

    std::cout << "length is: " << array.size() << '\n';
    std::cout << "capacity is: " << array.capacity() << '\n';
    // resize changes length and capacity, capacity >= length

    std::vector<int> array_1 {};
    array_1 = {0, 1, 2, 3, 4}; // legnth = 5
    std::cout << "length: " << array_1.size() 
            << " capacity: " << array_1.capacity() << '\n';
    
    array_1 = {0, 1, 2}; // length now 3
    std::cout << "length: " << array_1.size() 
            << " capacity: " << array_1.capacity() << '\n';
    // modified length, not the capacity
    // didn't reallocate memory
    
    // [] and .at() are based on length not capacity

    return 0;
}
