// compile with 
// g++ -w -IC:\tools\plog-1.1.5\include -o logging logging.cpp
#include <iostream>
#include <plog/Log.h> // Step 1 include logger

int get_user_input() {
    LOGD << "get_user_input() called";

    std::cout << "Enter a number: ";

    int x {};
    std::cin >> x;

    return x;
}

int main() {
    // step 2 initialise logger, can turn off with plog::none instead of debug
    plog::init(plog::debug, "Logfile.log");

    // step 3 output to log file
    LOGD << "main() called"; 

    int x {get_user_input()};
    std::cout << "You entered: " << x;

    return 0;
}
