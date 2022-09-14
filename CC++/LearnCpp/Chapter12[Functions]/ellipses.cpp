#include <cstdarg> // needed for ellipses
#include <iostream>
#include <string>

// ellipsis must be last param
// count is how many params are being passed
double find_average(int count, ...) {
    // ellipsis suspend type checks, can cause many issues
    // also removes the count of params
    int sum {0};

    // need va_list to access ellipsis values
    std::va_list list;

    // initalise va_list with va_start, pass object
    // and the last non-ellipsis argument
    va_start(list, count);

    // loop through ellipsis elements
    for (int arg {0}; arg < count; ++arg) {
        // need va_arg to get params
        // first param is the va_list, second is the type of param
        sum += va_arg(list, int);
    }

    // clean up va_list once done
    va_end(list);

    return static_cast<double>(sum) / count;
}

// issues of a count value, can be fixed using a sentinal value
double find_average_2(int first, ...) {
    int sum {first}; // treat first value seperately

    std::va_list list;

    va_start(list, first);

    int count {1};

    // loop indefinately until we find sentinal value
    while (true) {
        int arg {va_arg(list, int)};

        if (arg == -1) { // sentinal value of -1
            break;
        }

        sum += arg;
        ++count;
    }

    va_end(list);

    return static_cast<double>(sum) / count;
}

// another solution is a decoder string
double find_average_3(std::string decoder, ...) {
    double sum {0};

    std::va_list list;

    va_start(list, decoder);

    int count {0};

    while (true) {
        char codetype {decoder[count]};
        switch (codetype) { // decoder string used to determine value type
            default:
            case '\0':
                // va_list cleanup
                va_end(list);
                return sum / count;
            
            case 'i':
                sum += va_arg(list, int);
                ++count;
                break;
            
            case 'd':
                sum += va_arg(list, double);
                ++count;
                break;
        }
    }
}

int main() {
    std::cout << find_average(5, 1, 2, 3, 4, 5) << '\n';
    std::cout << find_average(6, 1, 2, 3, 4, 5, 6) << '\n';

    std::cout << find_average_2(1, 2, 3, 4, 5, -1) << '\n';
    std::cout << find_average_2(1, 2, 3, 4, 5, 6, -1) << '\n';

    std::cout << find_average_3("iiiii", 1, 2, 3, 4, 5) << '\n';
    std::cout << find_average_3("iiiiii", 1, 2, 3, 4, 5, 6) << '\n';
    std::cout << find_average_3("iiddi", 1, 2, 3.5, 4.5, 5) << '\n';

    return 0;
}
