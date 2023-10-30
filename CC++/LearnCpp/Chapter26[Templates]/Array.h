#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

template <typename T> // templating type
class Array {
private:
    int m_length {};
    T* m_data {};

public:
    Array(int length) {
        assert(length > 0);
        m_data = new T[length] {}; // allocate array of type T
        m_length = length;
    }

    // disallow coping of array
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array() {
        delete[] m_data;
    }

    void erase() {
        delete[] m_data;
        // need to set m_data to 0 otherwise it's left pointing to dealocated memory
        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index) { // returns template type pointer
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // templated get_length() function
    int get_length() const;
};

// must include .inl file after class definition
// then compile main .cpp on it's own
#include "Array.inl"

#endif
