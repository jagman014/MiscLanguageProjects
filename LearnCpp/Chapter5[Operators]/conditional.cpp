#include <iostream>

// (<condition> ? <true expression> : <false expression>)
// good for simple conditionals or variable assignment
int main() {
    int x {1};
    int y {2};

    int larger {};

    if (x > y) {
        larger = x;
    }
    else {
        larger = y;
    }

    // if statement compacts to:
    larger = ((x > y) ? x : y);

    // can used as an expression unlike if / else
    constexpr bool in_big_classroom {false};
    constexpr int class_size {in_big_classroom ? 30 : 20};

    // values of both returned expressions must be the same or easily converted

    return 0;
}