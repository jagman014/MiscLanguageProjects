#include <array>
#include <iostream>
#include <string>
#include <string_view>


class Animal {
protected:
    std::string m_name;

    // protected constructor, can't be made publicly
    // but can be made from derived classes
    Animal(std::string_view name)
    : m_name {name} {}

    // prevent slicing
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    std::string_view get_name() const {
        return m_name;
    }

    std::string_view speak() const {
        return "???";
    }
};


class Cat: public Animal {
public:
    Cat(std::string_view name)
    : Animal {name} {}

    std::string_view speak() const {
        return "Meow";
    }
};


class Dog: public Animal {
public:
    Dog(std::string_view name)
    : Animal {name} {}

    std::string_view speak() const {
        return "Woof";
    }
};


int main() {
    const Cat cat {"Fred"};
    std::cout << "cat is named " << cat.get_name()
                << ", they say " << cat.speak() << '\n';

    const Dog dog {"George"};
    std::cout << "dog is named " << dog.get_name()
                << ", they say " << dog.speak() << '\n';

    // base class pointers call the base class function instead of the overloaded derived class
    const Animal* animal_ptr {&cat};
    std::cout << "animal_ptr is named " << animal_ptr->get_name()
                << ", they say " << animal_ptr->speak() << '\n';

    animal_ptr = &dog;
    std::cout << "animal_ptr is named " << animal_ptr->get_name()
                << ", they say " << animal_ptr->speak() << '\n';

    // can write individual functions to solve but can be long winded for multiple classes
    const Cat misty {"Misty"};
    const Cat zeke {"Zeke"};

    const Dog patch {"Patch"};
    const Dog truffle {"Truffle"};

    // before c++20; const std::array<const Animal*, 6> animals {...}
    const auto animals {
        std::to_array<const Animal*> ({
            &cat,
            &dog,
            &misty,
            &patch,
            &zeke,
            &truffle
        })
    };

    for (const auto animal: animals) {
        std::cout << animal->get_name() << " says " << animal->speak() << '\n';
    }

    return 0;
}
