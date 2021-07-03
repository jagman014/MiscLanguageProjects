#include <iostream>

// <evaluated first> , <evaluated second and returned>
// better to write seperate lines for each statement
int main() {
    int x {1};
    int y {2};

    // does both operations by returns ++y to cout
    std::cout << (++x, ++y); 

    int z;
    z = (x, y); // evaluated then y assigned to z
    z = x, y; // x assigned to y, then y evaluated and discarded

    return 0;
}
