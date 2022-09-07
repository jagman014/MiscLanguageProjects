#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert> // for assert()


// int array container class
class IntArray {
private:
    int m_length {};
    int* m_data {};

public:
    // constructors
    IntArray() = default;

    IntArray(int length)
    : m_length {length} {
        assert(length >= 0);

        if (length > 0) {
            m_data = new int[length] {};
        }
    }

    // destructors
    ~IntArray() {
        // no need to reset members, as object will be destroyed here
        delete[] m_data;
    }

    void erase() {
        delete[] m_data;

        // set m_data to nullptr, and set m_length to 0
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int get_length() const {
        return m_length;
    }

    // reallocate: delete existing, resize; fast
    void reallocate(int new_length) {
        erase();

        if (new_length <= 0) {
            return;
        }

        m_data = new int[new_length];
        m_length = new_length;
    }

    // resize: keep existing, resize; slow
    void resize(int new_length) {
        if (new_length == m_length) {
            return;
        }

        if (new_length <= 0) {
            erase();
            return;
        }

        // first new temp object of new length
        int* data {new int[new_length]};

        // workout elements to copy over
        if (m_length > 0) {
            int elements_to_copy {(new_length > m_length) ? m_length : new_length};

            // copy elements one-by-one
            for (int index {0}; index < elements_to_copy; ++index) {
                data[index] = m_data[index];
            }
        }

        // delete old array
        delete[] m_data;

        // repoint m_data to data location
        m_data = data;
        m_length = new_length;
    }

    // insert value before a given index
    void insert_before(int value, int index) {
        // sanity check
        assert(index >= 0 && index <= m_length);

        // similar algorithm to resize
        int* data {new int[m_length + 1]};

        // copy elements upto index
        for (int before {0}; before < index; ++before) {
            data[before] = m_data[before];
        }

        // insert new element
        data[index] = value;

        // copy remaining elements
        for (int after {index}; after < m_length; ++after) {
            data[after + 1] = m_data[after];
        }

        // delete old array and reassign
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    // remove value from given index
    void remove(int index) {
        // sanity check
        assert(index >= 0 && index < m_length);

        // if last element, erase and return
        if (m_length == 1) {
            erase();
            return;
        }

        // similar algorithm to resize
        int* data {new int[m_length - 1]};

        // copy old array upto index
        for (int before {0}; before < index; ++before) {
            data[before] = m_data[before];
        }

        // copy old array after index
        for (int after {index + 1}; after < m_length; ++after) {
            data[after - 1] = m_data[after];
        }

        // delete old array and reassign
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    // additional convenience functions
    void insert_at_beginning(int value) {
        insert_before(value, 0);
    }

    void insert_at_end(int value) {
        insert_before(value, m_length);
    }
};


#endif
