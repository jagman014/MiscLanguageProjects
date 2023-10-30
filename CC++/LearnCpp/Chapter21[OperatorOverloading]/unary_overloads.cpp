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

    // convert to negative equivilent
    Point operator-() const;

    // return true if point is at origin
    bool operator!() const;

    double get_x() const {
        return m_x;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& point);

    double get_y() const {
        return m_y;
    }

    double get_z() const {
        return m_z;
    }
};


Point Point::operator-() const {
    return {-m_x, -m_y, -m_z};
}

bool Point::operator!() const {
    return {m_x == 0.0 && m_y == 0.0 && m_z == 0.0};
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "Point(" << point.m_x << ", " << point.m_y << ", "
        << point.m_z << ")";

    return out;
}

int main() {
    Point point1 {1.0, 2.3, 4.0};
    Point point2 {};

    std::cout << point1 << ' ' << -point1 << '\n';

    if (!point2) {
        std::cout << "point2 is at the origin\n";
    }
    else {
        std::cout << "point2 is not at the origin\n";
    }

    return 0;
}
