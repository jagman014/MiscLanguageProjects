#include <iomanip> // for std::ws
#include <iostream>
#include <string>

// strings are char arrays terminated by \0
// string literals surrounded by ""

// C++ string type
std::string my_name {"Jag"}; 
std::string my_id {"52"}; // "52" is different to 52

// strings are output as expected
int main() {
    std::cout << "My name is: " << my_name << "\n\n";

    // empty strings will output ""
    std::string empty {};
    std::cout << '[' << empty << ']' << "\n\n";

    // input strings, std::cin breaks on whitespace
    // need to use std::getline to break on newline instead
    std::cout << "Enter your full name: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);
    // std::ws tells std::cin to ignore leading whitespace

    std::cout << "Enter your age: ";
    std::string age {};
    std::cin >> age;

    std::cout << "Your name is " << name 
                << " and your age is " << age << "\n\n";

    // string length via .length() member function (method)
    std::cout << my_name << " has " << my_name.length() << " characters\n";

    return 0;
}
