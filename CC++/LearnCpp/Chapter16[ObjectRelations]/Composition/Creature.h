#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "Point2D.h"


class Creature {
private:
    // composition of a name and location
    std::string m_name;
    Point2D m_location;

public:
    Creature(const std::string& name, const Point2D& location)
    : m_name {name}
    , m_location {location} {}

    friend std::ostream& operator<<(std::ostream& out, const Creature& creature) {
        out << creature.m_name << " is at " << creature.m_location;
        return out;
    }

    void move_to(int x, int y) {
        m_location.set_point(x, y);
    }
};

#endif
