#include <iostream>
#include <string_view>


class A {
public:
    virtual std::string_view get_name() {
        return "A";
    }

    virtual std::string_view get_name_1(int x) {
        return "A";
    }

    virtual std::string_view get_name_2(int x) {
        return "A";
    }

    virtual std::string_view get_name_3(int x) {
        return "A";
    }
};


// use override specifier to make sure overriden function is overriden
// using final in class prevents it being inherited further
class B: public A {
public:
    std::string_view get_name_1(short int x) override { // compile error, signiture doesn't match
        return "B";
    }

    std::string_view get_name_2(int x) const override { // compile error, signiture doesn't match
        return "B";
    }

    std::string_view get_name_3(int x) override { // fine, don't need virtual keyword in override
        return "B";
    }

    //final makes sure it is no longer overridable in further derivations
    std::string_view get_name() override final {
        return "B";
    }
};


class C: public B {
public:
    std::string_view get_name() override {
        return "C";
    }
};
