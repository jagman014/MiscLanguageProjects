#include <stdio.h>

// first attempt, using pass-by-value
void swap_1(int a, int b){
    // using temp variable to store and swap values
    int t = a;
    a = b;
    b = t;

    printf("swap_1: a = %d, b = %d\n", a, b);
}

// second attempt using pass-by-reference
void swap_2(int *pa, int *pb) {
    // using temp variavle to store and swap pointer values
    int t = *pa;
    *pa = *pb;
    *pb = t;

    printf("swap_2: a = %d, b = %d\n", *pa, *pb);
}

int main(void) {
    // variables declared and assigned
    int a = 21;
    int b = 17;

    // values passed to function via arguments
    swap_1(a,b);
    printf("main: a = %d, b = %d\n\n", a, b);

    // addresses passed to function via arguments
    swap_2(&a, &b);
    printf("main: a = %d, b = %d\n", a, b);

    return 0;
}
