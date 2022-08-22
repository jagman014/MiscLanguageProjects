#include <iostream>


class Something {
private:
    int m_value1 {};
    double m_value2 {};
    char m_value3 {};
    const int m_array[5];

public:
    // directly initalise member values
    Something(int value1, double value2, char value3='c')
    : m_value1 {value1}
    , m_value2 {value2}
    , m_value3 {value3}
    , m_array {1, 2, 3, 4, 5} // uniform initalisation for array
    {} // no need for assignment
    
    void print() {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
};


int main() {
    Something something {1, 2.2};
    something.print();

    return 0;
}
