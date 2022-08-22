#include <iostream>
#include <iterator> // for std::size


class IntArray {
private:
    int m_array[10];

public:
    // revoke access to array, prevent indexing errors via encapsulation
    void set_value(int index, int value) {
        if (index < 0 || index >= std::size(m_array)) {
            return;
        }

        m_array[index] = value;
    }
};


class Something {
private:
    int m_value[3];

public:
    // getters and setters hide implementation
    void set_value_1(int value) {
        m_value[0] = value;
    }
    // getters should only return values / const references
    // non-const references give access to private variables
    int get_value_1() { 
        return m_value[0];
    }
};


int main() {
    // user interaction is simple, and will still work if the implementation is changed
    Something something;
    something.set_value_1(5);
    std::cout << something.get_value_1() << '\n';
}
