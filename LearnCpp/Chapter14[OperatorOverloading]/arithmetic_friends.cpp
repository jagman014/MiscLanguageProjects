#include <iostream>


class Cents {
private:
    int m_cents {};

public:
    Cents(int cents)
    : m_cents {cents} {}

    // add Cents + Cents using friend function
    friend Cents operator+(const Cents& c1, const Cents& c2);

    // add Cents - Cents using friend function
    friend Cents operator-(const Cents& c1, const Cents& c2);

    // can be defined within the class if desired
    // still not member functions
    friend Cents operator+(const Cents& c1, int value) {
        return {c1.m_cents + value};
    }

    friend Cents operator+(int value, const Cents& c1) {
        return {c1.m_cents + value};
    }

    int get_cents() const {
        return m_cents;
    }
};


// not a member function
Cents operator+(const Cents& c1, const Cents& c2) {
    // use Cents constructor and operator+(int, int)
    // use m_cents directly as friend
    return Cents{c1.m_cents + c2.m_cents};
}

// not a member function
Cents operator-(const Cents& c1, const Cents& c2) {
    // use Cents constructor and operator-(int, int)
    // use m_cents directly as friend
    return Cents{c1.m_cents - c2.m_cents};
}


class MinMax {
private:
    int m_min {}; // minimum seen so far
    int m_max {}; // maximum seen so far

public:
    MinMax(int min, int max)
    : m_min {min}
    , m_max {max} {}

    int get_min() {
        return m_min;
    }

    int get_max() {
        return m_max;
    }

    friend MinMax operator+(const MinMax& m1, const MinMax& m2);
    friend MinMax operator+(const MinMax& m1, int value);
    friend MinMax operator+(int value, const MinMax& m1);
};


MinMax operator+(const MinMax& m1, const MinMax& m2) {
    int min {m1.m_min < m2.m_min ? m1.m_min : m2.m_min};
    int max {m1.m_max > m2.m_max ? m1.m_max : m2.m_max};

    return {min, max};
}

MinMax operator+(const MinMax& m1, int value) {
    int min {m1.m_min < value ? m1.m_min : value};
    int max {m1.m_max > value ? m1.m_max : value};

    return {min, max};
}

MinMax operator+(int value, const MinMax& m1) {
    // call operator+(MinMax, int)
    return {m1 + value};
}

int main() {
    Cents cents_1 {6};
    Cents cents_2 {2};
    Cents cents_sum {cents_1 + cents_2};
    Cents cents_diff {cents_1 - cents_2};

    std::cout << "I have " << cents_sum.get_cents() << " cents total\n";
    std::cout << "I have " << cents_diff.get_cents() << " cents difference\n";

    Cents c1 {Cents{4} + 6};
    Cents c2 {6 + Cents{4}};

    std::cout << "I have " << c1.get_cents() << " cents\n";
    std::cout << "I have " << c2.get_cents() << " cents\n";

    MinMax m1 {10, 15};
    MinMax m2 {8, 11};
    MinMax m3 {3, 12};

    MinMax m_final {m1 + m2 + 5 + 8 + m3 + 16};

    std::cout << "Result: (" << m_final.get_min() << ", "
            << m_final.get_max() << ")\n";

    return 0;
}
