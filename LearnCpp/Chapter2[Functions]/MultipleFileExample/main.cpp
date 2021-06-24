// compile with "g++ -Wall -Werror -o main main.cpp add.cpp"
#include <iostream>

//require forward declaration
int add(int x, int y);

int main() {
    std::cout << "Sum of 3 and 4 is " << add(3, 4) << '\n';

    return 0;
}
