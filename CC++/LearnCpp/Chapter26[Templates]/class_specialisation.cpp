#include <iostream>


template<typename T>
class Storage8 {
private:
    T m_array[8];

public:
    void set(int index, const T& value) {
        m_array[index] = value;
    }

    const T& get(int index) const {
        return m_array[index];
    }
};

// can specialise the enitre class for a specific type
// treated as a separate class
template<>
class Storage8<bool> {
private:
    unsigned char m_data {};

public:
    void set(int index, bool value) {
        // figure out which bit is being set
        // put a 1 at the bit to be turned on / off
        auto mask {1 << index};

        if (value) { // if setting a bit on
            m_data |= mask; // use bitwise or to turn on
        }
        else { // if setting a bit off
            m_data &= ~mask; // use bitwise and with inverse mask to turn off
        }
    }

    bool get(int index) {
        // figure out which bit
        auto mask {1 << index};

        // bitwise and to get value, implicit cast to bool
        return (m_data & mask);
    }
};


int main() {
    // define Storage8 for ints, instance of Storage8<T> with T=int
    Storage8<int> int_storage;

    for (int count {0}; count < 8; ++count) {
        int_storage.set(count, count);
    }

    for (int count {0}; count < 8; ++count) {
        std::cout << int_storage.get(count) << '\n';
    }

    // define Storage8 for bools, instance of specialised Storage8<bool>
    Storage8<bool> bool_storage;

    for (int count {0}; count < 8; ++count) {
        bool_storage.set(count, count & 3);
    }

    std::cout << std::boolalpha;

    for (int count {0}; count < 8; ++count) {
        std::cout << bool_storage.get(count) << '\n';
    }

    return 0;
}
