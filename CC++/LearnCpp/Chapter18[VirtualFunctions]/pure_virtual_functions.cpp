#include <iostream>
#include <string>


class Base {
public:
    // define pure virtual function by assigning the value of 0

    // normal non-virtual function
    const char* say_hi() const {
        return "Hi";
    }

    // normal virtual function
    virtual const char* get_name() const {
        return "Base";
    }

    // pure virtual function
    virtual int get_value() const = 0;

    // compile error
    // int do_something() = 0;
};


// defined as an abstract base class
// derived classes need to override any and all pure virtual functions
class Animal {
protected:
    std::string m_name;

    Animal(const std::string& name)
    : m_name {name} {}

public:
    std::string get_name() const {
        return m_name;
    }

    virtual const char* speak() const = 0; // pure virtual function

    virtual ~Animal() = default;
};


// can give definition to pure virtual function
// without removing abstract property from class
const char* Animal::speak() const {
    return "Buzz";
}


class Cat: public Animal {
public:
    Cat(const std::string& name)
    : Animal {name} {}

    const char* speak() const override {
        return "Meow";
    }
};


class Dog: public Animal {
public:
    Dog(const std::string& name)
    : Animal {name} {}

    const char* speak() const override {
        return "Woof";
    }
};


// cannot instantiate without defining overrides for all pure virtual functions
class Cow: public Animal {
public:
    Cow(const std::string& name)
    : Animal {name} {}

    const char* speak() const override {
        return "Moo";
    }
};


class Dragonfly: public Animal {
public:
    Dragonfly(const std::string& name)
    : Animal {name} {}

    const char* speak() const override { // defines override
        return Animal::speak(); // uses the definition from base class
    }
};


int main() {
    Cow cow {"Betsy"};
    std::cout << cow.get_name() << " says " << cow.speak() << '\n';

    Dragonfly d_fly {"Sally"};
    std::cout << d_fly.get_name() << " says " << d_fly.speak() << '\n';

    return 0;
}
