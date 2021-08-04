#include <iostream>

// enumerated types are user-defined types
// enumerator names are put into global scope
// cannot have the same name in different enumerations

enum Colour {
    // define all types that can be held, separted by commas
    colour_black,
    colour_red,
    colour_blue,
    colour_green,
    colour_white,
    colour_cyan,
    colour_yellow,
    colour_magenta,
};

// define variables as the same
Colour paint = colour_white;
Colour house (colour_blue);
Colour apple {colour_red};

// can assign base type as well, can only forward declare with base
enum Shade : int {
    indigo,
    sky_blue,
    blue,
};

enum Feeling {
    happy,
    angry,
    blue, // error as blue already in global namespace from Shades
};

// best to prefix enumerators with common prefix
// values assigned an index starting with 0
// can be assigned to something else, but best to avoid

// can be assigned to int values, but ints cant be assigned to them
int my_colour {colour_magenta};

Colour colour {4}; // comipler error, can be forced with static_cast<Colour>

// cannot assign with std::cin, without static_cast of another variable

Feeling feeling {colour_black}; // comiple error, enum types are distinct

// need switch-case function to print enum names
void print_colour(Colour colour) {
    switch (colour) {
    case colour_black:
        std::cout << "Black";
        break;

    case colour_red:
        std::cout << "Red";
        break;

    case colour_blue:
        std::cout << "Blue";
        break;
    
    case colour_green:
        std::cout << "Green";
        break;
    
    case colour_white:
        std::cout << "White";
        break;
    
    case colour_cyan:
        std::cout << "Cyan";
        break;
    
    case colour_yellow:
        std::cout << "Yellow";
        break;
    
    case colour_magenta:
        std::cout << "Magenta";
        break;
    
    default:
        std::cout << "Who knows!";
    }
}
