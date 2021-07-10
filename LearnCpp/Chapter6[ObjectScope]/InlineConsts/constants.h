#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
    // only available in c++17 and above
    // allowed to be defined in multiple files
    // inline variables have external linkage by default
    // best comprimise between internal / external constants
    inline constexpr double pi {3.14159};
    inline constexpr double avagadro {6.0221413e23};
    inline constexpr double gravity {9.81};
}

#endif
