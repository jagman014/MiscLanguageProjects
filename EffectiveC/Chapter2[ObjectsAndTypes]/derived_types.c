#include <string.h> // for strcpy
// types constructed from other types

// pointer types:
    // referenced type, provides a reference to an entity of that type
    int *ip;
    char *cp;
    void *vp;

    // use the & operator to take the address of an object
    int i = 17;
    int *ip = &i;

// arrays:
    // sequence of objects of the same element type
    int ia[11]; // int array of length 11
    float *afp[17]; // float pointer array of length 17

    // create string "0123456789"
    char *digits(void) {
        char str[11];

        for (unsigned int i = 0; i < 10; ++i) {
            str[i] = '0' + i; // converts uint to char
        }

        str[10] = '\0'; // null terminator

        return str;
    }

    // can delare multi-dimensional arrays with more []
    int arr[3][5];

// typedefs:
    // can assign aliases to types
    // simple alias:
        typedef unsigned int uint_type;
    // alias of type, type pointer, and type function pointer
        typedef signed char schar_type, *schar_p, (*fp)(void);

// structures:
    // sequentially allocated object members, with distinct names and types
        // defines a struct; object, and pointer of the struct type 
        struct sigrecord {
            // defines three members of different types / sizes
            int signum;
            char signame[20];
            char sigdesc[100];
        } sigline, *sigline_p;

        // reference members with .
        // reference member pointers with ->
        void assign(void){
            sigline.signum = 5;
            strcpy(sigline.signame, "SIGINT");
            strcpy(sigline.sigdesc, "Interrupt from keyboard");

            sigline_p = &sigline;

            sigline_p->signum = 5;
            strcpy(sigline_p->signame, "SIGINT");
            strcpy(sigline_p->sigdesc, "Interrupt from keyboard");
        }

// unions:
    // like structs, but can only contain one type at a time
    // allows for better storage of some objects
    union {
        struct {
            int type;
        } n;

        struct {
            int type;
            int intnode;
        } ni;

        struct {
            int type;
            double doublenode;
        } nf;
    } u;
    
    void assign_1(void) {
        u.nf.type = 1;
        u.nf.doublenode = 3.14;
    }
