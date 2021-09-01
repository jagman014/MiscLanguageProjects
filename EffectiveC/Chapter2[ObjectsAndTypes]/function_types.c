// type of the function is dependent on its return value and param types

// function declarations:
    int f(void); // no params, returns an int
    int *fip(); // no specified params, returns an int pointer, not recommended in C
    void g(int i, int j); // params identifiers specified
    void h(int, int); // no identifiers specified

// function definition:
    int max(int a, int b) { // return type specifier, function declarator
        return a > b ? a : b; // function body
    }
