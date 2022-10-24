/*
 * Used to solve the diamond inheritance pattern
 * e.g.:
 *      Base <- Child_1
 *      ^- Child_2 <^- Grandchild
 * 
 * Prevent multiple Base class objects being created
*/

#include <iostream>


class PoweredDevice {
public:
    PoweredDevice(int power) {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};


class Scanner: virtual public PoweredDevice { // PoweredDevice now a virtual base class
public:
    Scanner(int scanner, int power)
    : PoweredDevice {power} { // required to make PoweredDevice, ignored in this case
        std::cout << "Scanner: " << scanner << '\n';
    }
};


class Printer: virtual public PoweredDevice { // PoweredDevice now a virtual base class
public:
    Printer(int printer, int power)
    : PoweredDevice {power} { // required to make PoweredDevice, ignored in this case
        std::cout << "Printer: " << printer << '\n';
    }
};


class Copier: public Scanner, public Printer {
public:
    Copier(int scanner, int printer, int power)
    : PoweredDevice {power} // PoweredDevice created here
    , Scanner {scanner, power}
    , Printer {printer, power} {}
};


int main() {
    Copier copier {1, 2, 3};

    return 0;
}
