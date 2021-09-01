// most type are unqualified
// three qualifing keywords: const, volatile, and restrict

// const
    // non modifiable, read-only
    const int i = 1;
    i = 2; // runtime error

// volatile
    // value in memory may change at any given time
    volatile int port;
    port = port;

// restrict
    // optomised pointers, restrict when the pointer looks
    void f(unsigned int n, int * restrict p, int * restrict q) {
        while (n-- > 0) {
            *p++ = *q++;
        }
    }
