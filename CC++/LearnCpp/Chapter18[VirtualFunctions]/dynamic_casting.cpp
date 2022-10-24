#include <iostream>
#include <string>

enum class ClassID {
    base,
    derived
};


class Base {
protected:
    int m_value {};

public:
    Base(int value)
    : m_value {value} {};

    virtual ~Base() = default;

    virtual ClassID get_class_id() const {
        return ClassID::base;
    }
};


class Derived: public Base {
protected:
    std::string m_name {};

public:
    Derived(int value, const std::string& name)
    : Base {value}
    , m_name {name} {}

    const std::string& get_name() const {
        return m_name;
    }

    virtual ClassID get_class_id() const {
        return ClassID::derived;
    }
};


Base* get_object(bool return_derived) {
    if (return_derived) {
        return new Derived {1, "Apple"};
    }
    else {
        return new Base {2};
    }
}

// dynamic_cast also works with references in the same principle as pointers
int main() {
    Base* b {get_object(true)};

    // access derived class properties from a base class pointer
    // use dynamic_cast to cast Base* to Derived*
    Derived* d {dynamic_cast<Derived*>(b)};

    if (d) { // need to do a nullptr check in case dynamic_cast fails
        std::cout << "The name of the Derived is: " << d->get_name() << '\n';
    }

    // can also do something simlar with static_cast
    // but can be more inefficient
    if (b->get_class_id() == ClassID::derived) {
        // already proved b points to a Derived, should always succeed
        Derived* d1 {static_cast<Derived*>(b)};
        std::cout << "The name of the Derived is: " << d1->get_name() << '\n';
    }

    delete b;

    return 0;
}
