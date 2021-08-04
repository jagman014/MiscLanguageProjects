#include <iostream>

int main() {
    // no need to prefix enumerators as they are strongly scoped to class
    enum class Colour {
        red, // scoped to Colour class
        blue,
    };

    enum class Fruit {
        banana, 
        apple,
    };

    Colour colour {Colour::red};
    Fruit fruit {Fruit::banana};

    if (colour == fruit) { 
        // compiler error, different enum classes cannot be compared
        // members of the same classes can be however
        // true case
    }
    else {
        // false case
    }
    
    // no longer implicitly cast to int
    std::cout << colour; // error
    std::cout << static_cast<int>(colour); // explicit casts are fine

    return 0;
}
