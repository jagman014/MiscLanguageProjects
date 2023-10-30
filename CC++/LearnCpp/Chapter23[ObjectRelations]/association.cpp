#include <functional>
#include <iostream>
#include <string>
#include <vector>

// circular dependency, both assosiated (uses-a), forward declaration
class Patient;


class Doctor {
private:
    std::string m_name {};
    std::vector<std::reference_wrapper<const Patient>> m_patient {};

public:
    Doctor(const std::string& name)
    : m_name {name} {}

    void add_patient(Patient& patient);

    friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

    const std::string& get_name() const {
        return m_name;
    }
};


class Patient {
private:
    std::string m_name {};
    std::vector<std::reference_wrapper<const Doctor>> m_doctor {};

    void add_doctor(const Doctor& doctor) {
        m_doctor.push_back(doctor);
    }

public:
    Patient(const std::string& name)
    : m_name {name} {}

    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

    const std::string& get_name() const {
        return m_name;
    }

    friend void Doctor::add_patient(Patient& patient);
};


void Doctor::add_patient(Patient& patient) {
    // doctor adds patient
    m_patient.push_back(patient);

    // patient adds doctor
    patient.add_doctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor) {
    if (doctor.m_patient.empty()) {
        out << doctor.m_name << " has no patients right now";
        return out;
    }

    out << doctor.m_name << " is seeing patients: ";
    for (const auto& patient : doctor.m_patient) {
        out << patient.get().get_name() << ' ';
    }

    return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
    if (patient.m_doctor.empty()) {
        out << patient.m_name << " has no doctors right now";
        return out;
    }

    out << patient.m_name << " is seeing doctors: ";
    for (const auto& doctor : patient.m_doctor) {
        out << doctor.get().get_name() << ' ';
    }

    return out;
}


// can have indirect associations
class Car {
private:
    std::string m_name {};
    int m_id {};

public:
    Car(const std::string& name, int id)
    : m_name {name}
    , m_id {id} {}

    const std::string& get_name() const {
        return m_name;
    }

    int get_id() const {
        return m_id;
    }
};


// static array of cars and a lookup function
class CarLot {
private:
    static Car s_car_lot[4];

public:
    // prevent creation of object
    CarLot() = delete;

    static Car* get_car(int id) {
        for (int count {0}; count < 4; ++count) {
            if (s_car_lot[count].get_id() == id) {
                return &(s_car_lot[count]);
            }
        }

        return nullptr;
    }
};


Car CarLot::s_car_lot[4] {
    {"Prius", 4},
    {"Corolla", 17},
    {"Accord", 84},
    {"Matrix", 62}
};


class Driver {
private:
    std::string m_name {};
    int m_car_id; // associated with car id instead of pointer

public:
    Driver(const std::string& name, int car_id)
    : m_name {name}
    , m_car_id {car_id} {}

    const std::string& get_name() const {
        return m_name;
    }

    int get_car_id() const {
        return m_car_id;
    }
};


int main() {
    // create patients outside scope of doctors
    Patient dave {"Dave"};
    Patient frank {"Frank"};
    Patient betsy {"Betsy"};

    Doctor james {"James"};
    Doctor scott {"Scott"};

    james.add_patient(dave);

    scott.add_patient(frank);
    scott.add_patient(betsy);

    std::cout << james << '\n';
    std::cout << scott << '\n';
    std::cout << dave << '\n';
    std::cout << frank << '\n';
    std::cout << betsy << "\n\n";

    Driver d {"Franz", 17}; // driving car with id = 17

    Car* car {CarLot::get_car(d.get_car_id())}; // get car from car lot

    if (car) {
        std::cout << d.get_name() << " is driving a " << car->get_name() << '\n';
    }
    else {
        std::cout << d.get_name() << " couldn't find his car\n";
    }

    return 0;
}
