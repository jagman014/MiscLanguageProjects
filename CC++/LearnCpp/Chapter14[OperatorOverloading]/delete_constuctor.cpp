#include <iostream>
#include <string>


class MyString {
private:
    std::string m_string;

public:
    MyString(char) = delete; // use of this constructor is an error

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
    MyString mine('x'); // error as MyString(char) is deleted
    std::cout << mine << '\n';

    return 0;
}
