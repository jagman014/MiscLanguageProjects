#include <iostream>

// the array is copied to the function unlike values
// passed by reference, not by value

void pass_value(int value) { // value is a copy
    value = 99; // changing it here won't change the original
}

void pass_array(int array[5]) { // this is the actual array
    array[0] = 11; // changing it here will change the original
    array[1] = 7;
    array[2] = 5;
    array[3] = 3;
    array[4] = 2;
}

int main() {
    int value {1};
    std::cout << "Value before passing: " << value << '\n';

    pass_value(value);
    std::cout << "Value  after passing: " << value << '\n';

    int prime[5] {2, 3, 5, 7, 11};
    std::cout << "Array before passing: {" 
                << prime[0] << ", " << prime[1] << ", " << prime[2] << ", " 
                << prime[3] << ", " << prime[4] << "}\n";

    pass_array(prime);
    std::cout << "Array  after passing: {" 
                << prime[0] << ", " << prime[1] << ", " << prime[2] << ", " 
                << prime[3] << ", " << prime[4] << "}\n";

    return 0;
}
