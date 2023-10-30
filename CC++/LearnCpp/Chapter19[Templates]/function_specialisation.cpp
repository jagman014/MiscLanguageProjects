#include <iostream>


template <typename T>
class Storage {
private:
    T m_value {};

public:
    Storage(T value)
    : m_value {value} {}

    ~Storage() {} // need explicit destructor to specialise it

    void print() {
        std::cout << m_value << '\n';
    }
};


// can specialise functions for a specific type
template<>
void Storage<double>::print() {
    std::cout << std::scientific << m_value << '\n';
}

// can specialise initialisers as well
template<>
Storage<char*>::Storage(char* const value) {
    if (!value) {
        return;
    }

    // figure out string length
    int length {0};
    while (value[length] != '\0') {
        ++length;
    }
    ++length; // account for null terminator

    // allocate memory to hold value string
    m_value = new char[length];

    // copy actual value string into m_value
    for (int count = 0; count < length; ++count) {
        m_value[count] = value[count];
    }
}

// require specialised deconstructor else there is a memory leek
// needs to be defined in class before it can be specialised
template<>
Storage<char*>::~Storage() {
    delete[] m_value;
}

int main() {
    // define storage units
    Storage<int> n_value {5};
    Storage<double> d_value {6.7};

    // print values
    n_value.print();
    d_value.print();

    // dynamically allocate temp string
    std::string s;

    std::cout << "Enter your name: ";
    std::cin >> s;

    // store name
    Storage<char*> storage(s.data());

    storage.print(); // prints name

    s.clear(); // clear temp string

    storage.print(); // prints nothing, without the specialised initialiser

    return 0;
}
