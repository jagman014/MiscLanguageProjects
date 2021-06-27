#include <iostream>

// values may differ
int main() {
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n"; // 1 B
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n"; // 1 B
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n"; // 2 B
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n"; // 2 B
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n"; // 4 B
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n"; // 2 B
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n"; // 4 B
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n"; // 4 B
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n"; // 8 B
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n"; // 4 B
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n"; // 8 B
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n"; // 12 B

    return 0;
}
