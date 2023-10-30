#include <iostream>
#include <string>


class MyString {
private:
    std::string m_string;

public:
    // explicit only, ineligible for implicit conversions
    explicit MyString(int x) { // allocate string of size x
        m_string.resize(x);
    }

    MyString(const char* string) { // allocate string to hold value
        m_string = string;
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};


std::ostream& operator<<(std::ostream& out, const MyString& s) {
    out << s.m_string;
    return out;
}

void print_string(const MyString& s) {
    std::cout << s;
}

int main() {
    MyString mine = 'x'; // would use MyString(int), error due to explicit call needed
    std::cout << mine << '\n';

    print_string('x'); // would use MyString(int), error due to explicit call needed

    std::cout << static_cast<MyString>(5); // allowed, explicit cast
    MyString str {'x'}; // still allowed, doesn't copy value to cast

    return 0;
}
