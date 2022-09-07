#include <functional> // std::reference_wrapper
#include <iostream>
#include <vector>
#include <string>


class Teacher {
private:
    std::string m_name {};

public:
    Teacher(const std::string& name)
    : m_name {name} {}

    const std::string& get_name() const {
        return m_name;
    }
};


class Department {
private:
    // aggregate class holds other classes as part of themselves
    // not responsible for creating / destroying memebers
    // usually use pointer / reference memebers
    const Teacher& m_teacher;

public:
    Department(const Teacher& teacher)
    : m_teacher {teacher} {}
};


int main() {
    // create teacher outside scope of department
    Teacher bob {"bob"};

    {
        // create department here
        Department deptartment {bob};
    }
    // department goes out of scope here

    // bob still exists, but department doesn't
    std::cout << bob.get_name() << " still exists\n";

    // to allow for arrays of references need std::reference_wrapper
    // cannot use anonymous objects
    std::string tom {"Tom"};
    std::string berta {"Berta"};

    // storing strings by reference not value
    // can add const keyword to the reference type
    std::vector<std::reference_wrapper<std::string>> names {tom, berta};

    std::string jim {"Jim"};

    names.push_back(jim);

    for (auto name : names) {
        // use get() to get referenced string
        name.get() += " Beam";
    }

    // object has been modified
    std::cout << jim << '\n';

    return 0;
}
