#include <iostream>


class Point {
private:
    double m_x {};
    double m_y {};
    double m_z {};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
    : m_x {x}
    , m_y {y}
    , m_z {z} {}

    friend std::ostream& operator<<(std::ostream& out, const Point& point);
    friend std::istream& operator>>(std::istream& in, Point& point);
};


// need to be careful with return type, need to return reference
// non-reference disallowed to be copied, this also allows chaining
std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "Point(" << point.m_x << ", " << point.m_y << ", "
        << point.m_z << ")";

    return out; // return std::ostream to chain operator<< calls
}

std::istream& operator>>(std::istream& in, Point& point) {
    // point object must be non-const to allow this
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;

    return in;
}

int main() {
    const Point point1 {2.0, 3.0, 4.0};

    std::cout << "Enter a point: ";

    Point point2;
    std::cin >> point2;

    std::cout << point1 << ' ' << point2 << '\n';

    return 0;
}
