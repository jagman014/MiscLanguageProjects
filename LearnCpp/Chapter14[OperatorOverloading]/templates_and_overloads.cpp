#include <iostream>

template <typename T>
const T& max(T x, T y) {
    return (x < y) ? y : x;
}

template <typename T>
T average(const T* array, int num_values) {
    T sum {0};

    for (int count {0}; count < num_values; ++count) {
        sum += array[count];
    }

    sum /= num_values;

    return sum;
}


class Cents {
private:
    int m_cents {};

public:
    Cents(int cents)
    : m_cents {cents} {}

    friend bool operator<(const Cents& c1, const Cents c2) {
        return (c1.m_cents < c2.m_cents);
    }

    friend std::ostream& operator<<(std::ostream& out, const Cents& c) {
        out << c.m_cents << " cents";
        return out;
    }

    Cents& operator+=(const Cents& cents) {
        m_cents += cents.m_cents;
        return *this;
    }

    Cents& operator/=(int x) {
        m_cents /= x;
        return *this;
    }
};


int main() {
    Cents nickel {5};
    Cents dime {10};

    Cents bigger = max(nickel, dime);
    std::cout << bigger << " is bigger\n";

    int int_array[] {5, 3, 2, 1, 4};
    std::cout << average(int_array, 5) << '\n';

    double double_array[] {3.12, 3.45, 9.23, 6.34};
    std::cout << average(double_array, 4) << '\n';

    Cents cents_array[] {Cents{5}, Cents{10}, Cents{15}, Cents{14}};
    std::cout << average(cents_array, 4) << '\n';

    return 0;
}
