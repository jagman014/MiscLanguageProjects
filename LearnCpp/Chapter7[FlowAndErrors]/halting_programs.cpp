#include <cstdlib> // for std::exit(), normal program exiting
#include <iostream>

// std::abort and std::terminate are available for abnormal exiting

void cleanup() {
    // code to cleanup
    std::cout << "cleanup!\n";
}

int main() {
    // register cleanup() function to be called when std::exit is called
    std::atexit(cleanup);

    std::cout << 1 << '\n';

    std::exit(0); // terminate and return 0 to OS
    // best to avoid as explicit calling doesn't cleanup the call stack

    std::cout << 2 << '\n'; // never executed

    return 0;
} // end of main implicitly calls std::exit(return value)
