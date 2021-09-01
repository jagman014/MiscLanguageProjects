#include <stdio.h> // for printf()
#include <stdlib.h> // for EXIT_SUCCESS, EXIT_FAILURE

int main(void) {
    // printf() returns the number of chars printed
    // or a negative value if it errors
    if (printf("%s\n", "Hello, World!") < 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
