#include <functional> // for std::reference_wrapper
#include <iostream>
#include <vector>


class Base {
protected:
    int m_value {};

public:
    Base(int value)
    : m_value {value} {}

    virtual const char* get_name() const {
        return "Base";
    }

    int get_value() const {
        return m_value;
    }
};


class Derived: public Base {
public:
    Derived(int value)
    : Base {value} {}

    const char* get_name() const override {
        return "Derived";
    }
};


// should be pass by ref instead of by value
// slices object by accident
void print_name(const Base base) {
    std::cout << "I am a " << base.get_name() << '\n';
}

void print_name_1(const Base& base) {
    std::cout << "I am a " << base.get_name() << '\n';
}

int main() {
    Derived derived {5};
    std::cout << "derived is a " << derived.get_name()
                << " and has a value of " << derived.get_value() << '\n';

    Base& ref {derived};
    std::cout << "ref is a " << ref.get_name()
                << " and has a value of " << ref.get_value() << '\n';

    Base* ptr {&derived};
    std::cout << "ptr is a " << ptr->get_name()
                << " and has a value of " << ptr->get_value() << '\n';

    // instead of using a pointer or a ref, downcast to Base object (slicing)
    Base base {derived};
    std::cout << "base is a " << base.get_name()
                << " and has a value of " << base.get_value() << '\n';
    
    std::cout << '\n';

    // accidental slice with pass by ref vs value
    print_name(derived);
    print_name_1(derived);

    std::cout << '\n';

    // another accidental slice with std::vector
    std::vector<Base> v {};
    v.push_back(Base{5});
    v.push_back(Derived{5});

    for (const auto& element: v) {
        std::cout << "I am a " << element.get_name()
                    << " with a value of " << element.get_value() << '\n';
    }

    std::cout << '\n';

    // correct via two methods:

    // method 1: vector of pointers
    std::vector<Base*> v1 {};
    Base b {5}; // cannot be anonymous objects
    Derived d {6};

    v1.push_back(&b);
    v1.push_back(&d);

    for (const auto& element: v1) {
        std::cout << "I am a " << element->get_name()
                    << " with a value of " << element->get_value() << '\n';
    }

    std::cout << '\n';

    // method 2: std::reference_wrapper
    std::vector<std::reference_wrapper<Base>> v2 {};
    // b and d cannot be anonymous
    v2.push_back(b);
    v2.push_back(d);

    // element has type std::reference_wrapper<Base>&
    for (const auto& element: v2) { // need to use the .get() method
        std::cout << "I am a " << element.get().get_name()
                    << " with a value of " << element.get().get_value() << '\n';
    }

    return 0;
}
