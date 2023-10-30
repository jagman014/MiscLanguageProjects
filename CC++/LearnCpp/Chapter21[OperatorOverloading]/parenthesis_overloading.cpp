#include <cassert>
#include <iostream>


class Matrix {
private:
    double m_data[4][4] {};

public:
    // overloading operator() allows for variable types and a variable amount of arguments
    double& operator()(int row, int col);
    double operator()(int row, int col) const;
    void operator()();
};


// can also be used to implement functors (function objects, can store data)
class Accumulator {
private:
    int m_counter {0};

public:
    int operator()(int i) {
        return (m_counter += i);
    }
};


double& Matrix::operator()(int row, int col) {
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const {
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

void Matrix::operator()() {
    // reset all elements
    for (int row {0}; row < 4; ++row) {
        for (int col {0}; col < 4; ++col) {
            m_data[row][col] = 0.0;
        }
    }
}

int main() {
    Matrix matrix;
    matrix(1, 2) = 4.5;
    std::cout << matrix(1, 2) << '\n';
    matrix(); // erase matrix
    std::cout << matrix(1, 2) << '\n';

    Accumulator acc {};
    std::cout << acc(10) << '\n';
    std::cout << acc(20) << '\n';

    return 0;
}
