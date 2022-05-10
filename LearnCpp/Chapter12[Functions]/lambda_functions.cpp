#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>

/* [capture clause] (params) -> return_type {
 * statements;
 * }
 */

// don't know what fn is, std::function works with functions and lambdas
void repeat(int repetitions, const std::function<void(int)>& fn) {
    for (int i {0}; i < repetitions; ++i) {
        fn(i);
    }
}

// lambdas allow for single use functions without definitions
// no need for a function if a function pointer is needed
// get around the limitation of no nested functions in c++
int main() {
    constexpr std::array<std::string_view, 4> array {
        "apple", 
        "banana",
        "walnut", 
        "lemon"
    };

    const auto found {
        std::find_if(
            array.begin(),
            array.end(),
            [](std::string_view str) { // use lambda function instead of function pointer
                return (str.find("nut") != std::string_view::npos);
            } // no capture clause, implicit return type
        )
    };

    if (found == array.end()) {
        std::cout << "No nuts\n";
    }
    else {
        std::cout << "Found " << *found << '\n';
    }

    // more readable when storing the lambda as a variable

    // regular function pointer, only works without capture clause
    double (*add_numbers)(double, double) {
        [](double a, double b) {
            return (a + b);
        }
    };

    std::cout << add_numbers(1, 2) << '\n';

    // using std::function, lambda can have a capture clause
    // prior to c++17 std::function<double(double, double)>
    std::function add_numbers_2 {
        [](double a, double b) {
            return (a + b);
        }
    };

    std::cout << add_numbers_2(3, 4) << '\n';

    // using auto stores with real type of lambda
    auto add_numbers_3 {
        [](double a, double b) {
            return (a + b);
        }
    };

    std::cout << add_numbers_3(5, 6) << '\n';
    
    // can't always use auto, when type of lambda is 
    // unknown for passing to functions need to use std::function

    repeat(
        3,
        [](int i) {
            std::cout << i << '\n';
        }
    );

    // lambdas can use auto in the params (all functions since C++20)
    // called generic lambdas
    constexpr std::array months {
        "January",
        "Febuary",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    // search for two consecutive months that start with the same letter
    const auto same_letter {
        std::adjacent_find(
            months.begin(),
            months.end(),
            [](const auto& a, const auto& b) { // generic lambda  function
                return (a[0] == b[0]);
            }
        )
    };

    if (same_letter != months.end()) {
        std::cout << *same_letter << " and " << *std::next(same_letter)
            << " start with the same letter\n";
    }

    // auto not always the best choice, especially with strings
    // auto -> const char*

    const auto five_letter_months {
        std::count_if(
            months.begin(),
            months.end(),
            [](std::string_view str) {
                return (str.length() == 5);
            }
        )
    };

    std::cout << "There are " << five_letter_months
        << " months with five letters\n";

    // a unique lambda will be created for each auto resolution
    auto print {
        [](auto value) {
            static int call_count {0};
            std::cout << call_count++ << ": " << value << '\n';
        }
    };

    print("hello"); // 0: hello
    print("world"); // 1: world

    print(1); // 0: 1
    print(2); // 1: 2

    print("ding dong"); // 2: ding dong

    // all above use return type inference
    // requires all return types to be the same

    // add return type and let compiler convert convertable types
    auto divide {
        [](int x, int y, bool b_integer) -> double {
            if (b_integer) {
                return x / y;
            }
            else {
                return static_cast<double>(x) / y;
            }
        }
    };

    std::cout << divide(3, 2, true) << '\n';
    std::cout << divide(3, 2, false) << '\n';

    // <functional> header comes with some generic lambda functions
    std::array arr {13, 90, 99, 5, 40, 80};

    // example std::greater, need {} to instantiate object
    std::sort(arr.begin(), arr.end(), std::greater{});

    for (int i : arr) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}
