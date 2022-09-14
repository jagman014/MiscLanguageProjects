#include <stdio.h> // for puts(), EOF
#include <stdlib.h> // for EXIT_SUCCESS, EXIT_FAILURE

int main(void) {
    // puts() function can produce a write error, EOF == -1
    // can be improved with if statement
    if (puts("Hello, World!") == EOF) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
