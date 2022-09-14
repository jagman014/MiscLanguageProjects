#include <cassert>
#include <cstddef>
#include <iostream>


class IntArray {
private:
    int* m_array {};
    int m_length {};

public:
    IntArray(int length) { // constructor
        assert(length > 0);

        m_array = new int[static_cast<std::size_t>(length)]{};
        m_length = length;
    }

    ~IntArray() { // destructor, needed for handling dynamic data types
        delete[] m_array; // dynamically delete array
    }

    void set_value(int index, int value) {
        m_array[index] = value;
    }

    int get_value(int index) {
        return m_array[index];
    }

    int get_length() {
        return m_length;
    }
};


class Simple {
private:
    int m_nid {};

public:
    Simple(int nid)
    : m_nid {nid} {
        std::cout << "Constructing Simple " << nid << '\n';
    }
    
    ~Simple() {
        std::cout << "Destructing Simple " << m_nid << '\n';
    }

    int get_id() {
        return m_nid;
    }

};


int main() {
    IntArray ar (10); // allocate 10 integers

    for (int count {0}; count < ar.get_length(); ++count) {
        ar.set_value(count, count + 1);
    }

    std::cout << "The value of element 5 is: " << ar.get_value(5) << '\n';

    // allocate Simple onto stack
    Simple simple {1};
    std::cout << simple.get_id() << '\n';

    // allocated a Simple dynamically
    Simple* p_simple {new Simple{2}};

    std::cout << p_simple->get_id() << '\n';

    // need to delete dynamically allocated object
    delete p_simple;

    return 0;
} // ~IntArray() is called here; simple goes out of scope here
