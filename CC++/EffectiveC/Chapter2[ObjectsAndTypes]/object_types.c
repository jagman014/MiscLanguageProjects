#include <stdbool.h> // for bool, true, and false
#include <wchar.h> // for wchar_t

// boolean type declarations, can only have values of 1 or 0
    _Bool flag1 = 0; // reserved declartion type
    bool flag2 = false; // included declaration type, better method

// character types, char contains ASCII values
    // signed and unsigned char are incompatible with char
    // wchar_t for more than ASCII chars
    char c;
    unsigned char uc;
    signed char sc;
    wchar_t wc;

// numerical types

    // integer types:
        // signed ints, for negative / positive whole numbers
        signed char sc;
        short s;
        int i;
        long l;
        long long ll;

        // unsigned ints, only positive whole numbers
        unsigned char uc;
        unsigned short us;
        unsigned int ui;
        unsigned long ul;
        unsigned long long ull;

        // specific width types in <stdint.h> or <inttypes.h>
        // also contain the max width types uintmax_t and intmax_t

    // enum types:
        // allow for names to be assigned to integer values and enumerated
        // can assign values manually, or automatically increment
        enum day {sun, mon, tue, wed, thu, fri, sat};
        enum cardinal_points {north=0, east=90, south=180, west=270};
        enum months {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
    
    // floating-point types:
        // used for real numbers
        float f;
        double d;
        long double ld;

// void types:
    // cannot hold any value
    void;
