#include <cassert> // for assert()
#include <iostream>
#include <iterator> // for std::size()


class IntList {
private:
    int m_list[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

public:
    int& operator[](int index);
    int operator[](int index) const;
};

// for non-const objects, can be used for assignment
int& IntList::operator[](int index) {
    assert(index >= 0 && (std::size_t)index < std::size(m_list)); // error checking

    return m_list[index];
}

// for const objects, can only be used for access
int IntList::operator[](int index) const {
    assert(index >= 0 && static_cast<std::size_t>(index) < std::size(m_list)); // error checking

    return m_list[index];
}

int main() {
    IntList list {};
    list[2] = 3; // calls non-const IntList::operator[]
    std::cout << list[2] << '\n';

    const IntList clist {};
    // clist[2] = 3; // compile error, assignment of const object
    std::cout << clist[2] << '\n';

    return 0;
}
