#include <iostream>
#include <vector>

void print_stack(const std::vector<int>& stack) {
    for (auto element : stack) {
        std::cout << element << ' ';
    }
    std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main() {
    std::vector<int> stack {};

    // stack behaviour resizes vector automatically
    // resizing is expensive, reserve size upfront
    stack.reserve(5);

    print_stack(stack);

    stack.push_back(5); // pushes element onto stack
    print_stack(stack);

    stack.push_back(3);
    print_stack(stack);

    stack.push_back(2);
    print_stack(stack);

    std::cout << "top: " << stack.back() << '\n'; // returns the last element

    stack.pop_back(); // pops element off stack
    print_stack(stack);

    stack.pop_back();
    print_stack(stack);

    stack.pop_back();
    print_stack(stack);

    // vectors may allocate more capacity for breathing room

    return 0;
}
