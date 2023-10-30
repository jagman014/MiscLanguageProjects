#include <iostream>

// user defined aggregate data type

// size of a struct is at least the sum of its members
// size can be padded to be larger for faster memory access
struct Employee { // declaration, no memeory assigned
    int id {};
    int age {};
    double wage {};
};

// can assign default values to non-static members
struct Rectangle {
    double lenght {1.0};
    double width {1.0};
};

// can pass structs to functions
void print_information(Employee employee) {
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

// can also return structs
struct Point3d {
    double x {};
    double y {};
    double z {};
};

// one method to return multiple values
Point3d get_zero_point() {
    // three methods to return all zeros Point3d

    // Point3d temp {0.0, 0.0, 0.0}
    // return temp;

    return {0.0, 0.0, 0.0};

    // return {};
}

// can also nest structs, require double member selection for access
struct Company {
    Employee CEO;
    int number_of_employees;
};

int main() {
    Employee joe; // create Employee object
    joe.id = 14; // assignment of value to object member
    joe.age = 32;
    joe.wage = 24.15;

    Employee frank;
    frank.id = 15;
    frank.age = 28;
    frank.wage = 18.27;

    // member variables act like normal variables
    int total_age = (joe.id + frank.id);

    if (joe.wage > frank.wage) {
        std::cout << "Joe makes more than Frank\n";
    }
    else if (joe.wage < frank.wage) {
        std::cout << "Joe makes less than Frank\n";
    }
    else {
        std::cout << "Joe and Frank make the same amount\n";
    }

    frank.wage += 2.50;

    ++joe.age;

    // faster assignment method, assigns members in struct definition order
    Employee alice {1, 28, 28.30};

    Employee bob {2, 24}; // non-initialised values use default

    // can overwrite default values as before
    Rectangle x {2.0, 2.0};

    // can copy all members
    Employee charlie {bob};

    // print joe's information
    print_information(joe);

    // use struct return type function
    Point3d zero{ get_zero_point() };
 
    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    // nested initialiser
    Company my_company {{1, 42, 60000.0}, 5};

    std::cout << my_company.CEO.wage;

    return 0;
}
