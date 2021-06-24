#include "io.h"

// gets two user input numbers then returns the sum
int main() {
    int x {get_number()};
    int y {get_number()};

    write_answer(x + y);

    return 0;
}
