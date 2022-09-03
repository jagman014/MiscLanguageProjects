#include "Cents.h"

// not a memeber nor a friend function
Cents operator+(const Cents& c1, const Cents& c2) {
    // different level of access compared to friend function
    return {c1.get_cents() + c2.get_cents()};
}
