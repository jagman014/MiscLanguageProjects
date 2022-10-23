#include <iostream>
#include <string>
#include <string_view>


class Base {
public:
    // virtual resolve to the most derived version of the function
    virtual std::string_view get_name() const {
        return "Base";
    }
};


class Derived: public Base {
public:
    // overrirdes base function, the override must match the original signiture
    virtual std::string_view get_name() const {
        return "Derived";
    }
};


class Animal {
protected:
    std::string m_name;

    Animal(const std::string_view name)
    : m_name {name} {}

public:
    const std::string& get_name() const {
        return m_name;
    }

    virtual std::string_view speak() const {
        return "???";
    }
};


class Cat: public Animal {
public:
    Cat(const std::string& name)
    : Animal {name} {}

    virtual std::string_view speak() const {
        return "Meow";
    }
};


class Dog: public Animal {
public:
    Dog(const std::string& name)
    : Animal {name} {}

    virtual std::string_view speak() const {
        return "Woof";
    }
};


void report(const Animal& animal) {
    std::cout << animal.get_name() << " says " << animal.speak() << '\n';
}

int main() {
    Derived derived;
    Base& base_ref {derived};
    std::cout << "base_ref is a " << base_ref.get_name() << '\n';

    Cat cat {"Fred"};
    Dog dog {"George"};

    report(cat);
    report(dog);

    Cat misty {"Misty"};
    Cat zeke {"Zeke"};

    Dog patch {"Patch"};
    Dog truffle {"Truffle"};

    Animal* animals[] {&cat, &dog, &misty, &patch, &zeke, &truffle};

    for (const auto* animal: animals) {
        std::cout << animal->get_name() << " says " << animal->speak() << '\n';
    }

    return 0;
}
