#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>

struct Car {
    std::string make {};
    std::string model {};
};

void invoke(const std::function<void()>& fn) {
    fn();
}

int main() {
    std::array<std::string_view, 4> array {
        "apple",
        "banana",
        "walnut",
        "lemon"
    };

    std::cout << "Search for: ";

    std::string search {};
    std::cin >> search;

    // lambda functions can't "see" variables outside the scope of the lambda
    // need to pass objects in the capture clause
    auto found {
        std::find_if(
            array.begin(),
            array.end(),
            [search](std::string_view str) { // provide variable to lambda function
                return (str.find(search) != std::string_view::npos);
            } // captured objects are clones, the the actual object
        ) // captured as const values, cannot be modified within lambda
    };

    if (found == array.end()) {
        std::cout << "Not found\n";
    }
    else {
        std::cout << "Found " << *found << '\n';
    }

    // to allow lambda to change the copied value need mutable key word
    int ammo {10};

    auto shoot {
        [ammo]() mutable { // value now editable
            --ammo;
            std::cout << "Pew! " << ammo << " shot(s) left\n";
        }
    };

    shoot();
    shoot();

    // doesn't modify original value
    std::cout << ammo << " shot(s) left\n";

    // can modify original value if passed by reference
    auto shoot_ref {
        [&ammo]() { // use of pass by reference, now affects original object
            --ammo;
            std::cout << "Pew! " << ammo << " shot(s) left\n";
        }
    };

    shoot_ref();

    std::cout << ammo << " shot(s) left\n";

    // using pass by reference to see how many comparisons std::sort does

    std::array<Car, 3> cars {{
        {"Volkswagon", "Golf"},
        {"Toyota", "Corolla"},
        {"Honda", "Civic"}
    }};

    int comparisons {0};

    std::sort(
        cars.begin(),
        cars.end(),
        [&comparisons](const auto& a, const auto& b) {
            ++comparisons; // captured by reference, mutable by default
            // sort cars by make
            return (a.make < b.make);
        }
    );

    std::cout << "Comparisons: " << comparisons << '\n';

    for (const auto& car: cars) {
        std::cout << car.make << ' ' << car.model << '\n';
    }

    // can capture multiple values (by value or by reference) using commas in []
    // can use default values {= or &} to capture all used values by val or ref
    // defaults can be mixed with normal captures as well
    std::array areas {100, 25, 121, 40, 56};

    int width {};
    int height {};

    std::cout << "Enter width and height: ";
    std::cin >> width >> height;

    auto found_1 {
        std::find_if(
            areas.begin(),
            areas.end(),
            [=](int known_area) { // will default capture width and height
                return (width * height == known_area); // as they are mentioned here
            }
        )
    };

    // default must come first, cannot mix '=' with other by values
    // or '&' with other by reference

    if (found_1 == areas.end()) {
        std::cout << "Area not found\n";
    }
    else {
        std::cout << "Area found\n";
    }

    // can define a new variable within the lambda scope

    // calculate value before searching
    auto found_2 {
        std::find_if(
            areas.begin(),
            areas.end(),
            [user_area {width * height}](int known_area) { // create new variable in capture clause
                return (user_area == known_area); // type of new variable is auto deduced
            }
        )
    };

    if (found_2 == areas.end()) {
        std::cout << "Area not found (again)\n";
    }
    else {
        std::cout << "Area found (again)\n";
    }

    // careful about lifespans with lambdas
    // if variable dies before lambda -> undefined behaviour

    // copies of mutable lambdas will make exact copy at instance
    // values in copy don't change when original called and vice versa

    // can deal with mutable lambdas and avoid static values using
    // std::reference_wrapper or std::ref from <functional>
    // returns reference to lambda instead of a copy

    int i {0};

    auto count {
        [i]() mutable {
            std::cout << ++i << '\n';
        }
    };

    // ensures lambda treated like a reference
    // only one version of the function exists
    invoke(std::ref(count));
    invoke(std::ref(count));
    invoke(std::ref(count));

    return 0;
}
