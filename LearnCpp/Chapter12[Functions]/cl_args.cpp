#include <iostream>
#include <sstream> // for std::stringstream
#include <string>

// argc -> argument count
// argv -> argument vectors
int main(int argc, char* argv[]) {
    std::cout << "There are " << argc << " arguments\n";

    // loop through arguments and print values
    for (int count {0}; count < argc; ++count) {
        std::cout << count << ": " << argv[count] << '\n';
    }
    // arg 0 is always the name of the program

    // all arguments are always strings
    if (argc <= 1) {
        if (argv[0]) {
            std::cout << "Usage: " << argv[0] << " <number>\n";
        }
        else {
            std::cout << "Usage: <program name> <number>\n";
        }

        return 1;
    }

    // setup stringstream valiable to convert value
    std::stringstream convert {argv[1]};

    int my_int {};
    if (!(convert >> my_int)) { // do the conversion
        my_int = 0; // if fails, set to default value
    }

    std::cout << "Got integer: " << my_int << '\n';

    return 0;
}
