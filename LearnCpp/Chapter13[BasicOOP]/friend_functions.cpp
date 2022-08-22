#include <iostream>

// needed prototype, as function prototype uses both classes
class Humidity;


class Temperature {
private:
    int m_temp {};

public:
    Temperature(int temp=0)
    : m_temp {temp} {}

    friend void print_weather(const Temperature& temperature, const Humidity& humidity);
};


class Humidity {
private:
    int m_humidity {};

public:
    Humidity(int humidity=0)
    : m_humidity {humidity} {}

    friend void print_weather(const Temperature& temperature, const Humidity& humidity);
};


// allowed access to private members as it's declared a friend function
// within the class declarations
void print_weather(const Temperature& temperature, const Humidity& humidity) {
    std::cout << "The temperature is " << temperature.m_temp
            << "C, and the humidity is " << humidity.m_humidity << "%\n";
}


// can have friend classes and memeber functions
// friend methods need full class definitions however
class Storage; // forward declaration


class Display {
private:
    bool m_display_int_first {};

public:
    Display(bool display_int_first)
    : m_display_int_first {display_int_first} {}

    void display_item(const Storage& storage); // forward declaration
};


class Storage { // full definition
private:
    int m_n_value {};
    double m_d_value {};

public:
    Storage(int n_value, double d_value)
    : m_n_value {n_value}
    , m_d_value {d_value} {}

    // requires full class declaration of Display
    friend void Display::display_item(const Storage& storage);
};

// requires full class declaration of Storage
void Display::display_item(const Storage& storage) {
    if (m_display_int_first) {
        std::cout << storage.m_n_value << ' ' << storage.m_d_value << '\n';
    }
    else {
        std::cout << storage.m_d_value << ' ' << storage.m_n_value << '\n';
    }
}

int main() {
    Humidity hum {50};
    Temperature temp {27};

    print_weather(temp, hum);

    Storage storage(5, 6.7);
    Display display(false);

    display.display_item(storage);

    return 0;
}
