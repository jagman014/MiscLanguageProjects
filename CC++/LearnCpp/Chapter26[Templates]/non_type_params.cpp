#include <iostream>

template <typename T, int size> // size is an integral non-type parameter
class StaticArray {
private:
    // non-type param controls size of array
    T m_array[size] {};

public:
    T* get_array();

    T& operator[](int index) {
        return m_array[index];
    }
};

template <typename T, int size>
T* StaticArray<T, size>::get_array() {
    return m_array;
}

int main() {
    StaticArray<int, 12> int_array;

    for (int count {0}; count < 12; ++count) {
        int_array[count] = count;
    }

    for (int count {11}; count >= 0; --count) {
        std::cout << int_array[count] << ' ';
    }

    std::cout << '\n';

    StaticArray<double, 4> double_array;

    for (int count {0}; count < 4; ++count) {
        double_array[count] = 4.4 + 0.1 * count;
    }

    for (int count {0}; count < 4; ++count) {
        std::cout << double_array[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}
