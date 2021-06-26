#include <iostream>
 
int add(int x, int y)
{
std::cerr << "add() called (x=" << x <<", y=" << y << ")\n";
	return x + y;
}
 
void print_result(int z)
{
	std::cout << "The answer is: " << z << '\n';
}
 
int get_user_input()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}
 
int main()
{
	int x{ get_user_input() };
// variable prinouts formated to see which function variable is init from
std::cerr << "main::x = " << x << '\n';
	int y{ get_user_input() };
std::cerr << "main::y = " << y << '\n';
 
	std::cout << x << " + " << y << '\n';
 
    // error when add function is called
	int z{ add(x, 5) };
std::cerr << "main::z = " << z << '\n';
	print_result(z);
 
	return 0;
}
