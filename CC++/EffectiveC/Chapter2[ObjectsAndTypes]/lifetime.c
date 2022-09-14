#include <stdio.h>

// most objects have automatic duration
// global variables have static duration, destroyed when program ends

/*
// static objects must be initialised with a constant value, not a variable
int *func(int i) {
    const int j = i; // ok
    static int k = j; // error
    
    return &k;
}
*/

void increment(void) {
    static unsigned int counter = 0; // object has static duration
    counter++;

    printf("%d ", counter);
}

int main(void) {
    for (int i = 0; i <5; i++) {
        increment();
    }

    return 0;
}
