#include <iostream>


class Rectangle {
private:
    // use of default values here, no need for values within the constructor itself
    double m_length {1.0};
    double m_width {1.0};

public:
    Rectangle() = default; // needed for default initialisation

    Rectangle(double length, double width)
    : m_length {length}
    , m_width {width} {}
    
    Rectangle(double length) // still needed for single value initalisation
    : m_length {length} {}

    void print() {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }
};


int main() {
    Rectangle x {};
    x.print();

    Rectangle y {2.0, 3.0};
    y.print();

    Rectangle z {4.0};
    z.print();

    return 0;
}
