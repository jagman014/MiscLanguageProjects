#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>


class Point2D {
private:
    // composition of two points
    int m_x;
    int m_y;

public:
    // default constructor
    Point2D()
    : m_x {0}
    , m_y {0} {}

    // specific constructor
    Point2D(int x, int y)
    : m_x {x}
    , m_y {y} {}

    // overload of output operator
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point) {
        out << '(' << point.m_x << ", " << point.m_y << ')';
        return out;
    }

    // access functions
    void set_point(int x, int y) {
        m_x = x;
        m_y = y;
    }
};

#endif
