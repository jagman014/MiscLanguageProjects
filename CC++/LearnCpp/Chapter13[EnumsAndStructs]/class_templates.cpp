#include <iostream>

// can write class templates in a similar fashion to function templates
template <typename T>
struct Pair {
    T first {};
    T second {};
};

// multiple types
// commonly used -> found in <utility> at std::pair
template <typename T, typename U>
struct Pair1 {
    T first {};
    U second {};
};

// type argument deduction added in C++17, need to define deduction
// not necessarily needed in C++20
template <typename T, typename U>
Pair1(T, U) -> Pair1<T, U>;
// can now define object "Pair1 p {1, 2};" for implicit type casts

// can combine with template functions
template <typename T>
constexpr T max(Pair<T> p) {
    return (p.first > p.second ? p.first : p.second);
}

template <typename T, typename U>
void print(Pair1<T, U> p) {
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main() {
    Pair<int> p1 {5, 6}; // int Pair struct
    std::cout << p1.first << ' ' << p1.second << '\n';
    std::cout << max<int>(p1) << " is larger\n"; // explicit type call

    Pair<double> p2 {1.2, 3.4}; // double Pair struct
    std::cout << p2.first << ' ' << p2.second << '\n';
    std::cout << max(p2) << " is larger\n"; // implicit type call, template argument deduction

    Pair1<int, double> p3 {1, 2.3};
    print(p3);

    return 0;
}
