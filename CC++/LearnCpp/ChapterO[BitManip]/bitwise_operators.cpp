#include <bitset>
#include <iostream>

/*
<<, bitshift left -> x << y, x shifted left by y bits
>>, bitshift right -> x >> y, x shifted right by y bits
~, bitwise not -> ~x, flip all bits
&, bitwise and -> x & y, each bit in x AND y
|, bitwise or -> x | y, each bit in x OR y
^, bitwise xor -> x ^ y, each bit in x XOR y
*/

// rotate left, put left most bit on the right side
std::bitset<4> rotl(std::bitset<4> bits) {
    return (bits << 1) | (bits >> 3);
}

// rotate right, put right most bit on the left side
std::bitset<4> rotr(std::bitset<4> bits) {
    return (bits >> 1) | (bits << 3);
}

int main() {
    std::bitset<4> x {0b1100};

    std::cout << "x:\t" << x << '\n';
    std::cout << "x >> 1:\t" << (x >> 1) << '\n'; // shift right by 1, 0110
    std::cout << "x << 1:\t" << (x << 1) << "\n\n"; // shift left by 1, 1000

    // bitwise not flips all bits, result dependent on size of object
    std::bitset<4> y {0b0100u};
    std::bitset<8> z {0b0100u};
    std::cout << "y = " << y << "\t~y = " << ~y << '\n';
    std::cout << "z = " << z << "\t~z = " << ~z << "\n\n";

    // bitwise or applies a digit by digit comparison
    // any true result gives a 1, false gives a 0
    std::bitset<4> a {0b0101};
    std::bitset<4> b {0b0110};
    std::cout << a << " |\n" << b << "\n------\n" << (a | b) << "\n\n";

    // works for compound or statements
    std::bitset<4> c {0b0111};
    std::bitset<4> d {0b0011};
    std::bitset<4> e {0b0001};
    std::cout << c << " |\n" << d << " |\n" << e 
                << "\n------\n" << (c | d | e) << "\n\n";
    
    // bitwise and works in the same manor as bitwise or
    std::cout << a << " &\n" << b << "\n------\n" << (a & b) << "\n\n";
    std::cout << c << " &\n" << d << " &\n" << e 
                << "\n------\n" << (c & d & e) << "\n\n";

    // again bitwise xor works as above
    std::cout << a << " ^\n" << b << "\n------\n" << (a ^ b) << "\n\n";
    std::cout << c << " ^\n" << d << " ^\n" << e 
                << "\n------\n" << (c ^ d ^ e) << "\n\n";

    // all of the above can be combined with = to assign the result to the
    // variable, in the same way as the arithmetic operators
    std::bitset<4> f {0b1011};
    std::cout << "f =\t" << f << "\nrotl(f) =\t" << rotl(f) 
                << "\nrotr(f) = \t" << rotr(f) << '\n';

    return 0;
}
