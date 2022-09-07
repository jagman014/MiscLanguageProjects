#include <cassert> // for assert()
#include <initializer_list> // for std::initializer_list
#include <iostream>


class IntArray {
private:
    int m_length {};
    int* m_data {};

public:
    IntArray() = default;

    IntArray(int length)
    : m_length {length}
    , m_data {new int[length]} {}

    // allow IntArray to be initalised using a list
    IntArray(std::initializer_list<int> list)
    : IntArray(static_cast<int>(list.size())) { // delegate constructor
        int count {0};

        for (auto element : list) {
            m_data[count] = element;
            ++count;
        }
    }

    ~IntArray() {
        delete[] m_data;
    }

    // to avoid shallow copies
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray& list) = delete;

    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int get_length() const {
        return m_length;
    }
};


int main() {
    IntArray array {5, 4, 3, 2, 1}; // initaliser list

    for (int count {0}; count < array.get_length(); ++count) {
        std::cout << array[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}
