#include <cstdint>
#include <iostream>
 
int main()
{
	constexpr std::uint_fast32_t redBits {0xFF000000};
	constexpr std::uint_fast32_t greenBits {0x00FF0000};
	constexpr std::uint_fast32_t blueBits {0x0000FF00};
	constexpr std::uint_fast32_t alphaBits {0x000000FF};
 
	std::cout << "Enter a 32-bit RGBA color" 
                << " value in hexadecimal (e.g. FF7F3300): ";
	std::uint_fast32_t pixel{};
	std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value
 
	// use Bitwise AND to isolate red pixels,
	// then right shift the value into the lower 8 bits
	std::uint_fast8_t red 
                {static_cast<std::uint_fast8_t>((pixel & redBits) >> 24)};
	std::uint_fast8_t green 
                {static_cast<std::uint_fast8_t>((pixel & greenBits) >> 16)};
	std::uint_fast8_t blue 
                {static_cast<std::uint_fast8_t>((pixel & blueBits) >> 8)};
	std::uint_fast8_t alpha 
                {static_cast<std::uint_fast8_t>(pixel & alphaBits)};
 
	std::cout << "Your color contains:\n";
	//std::cout << std::hex; // print the following values in hex
	std::cout << static_cast<int>(red) << "\tred\n";
	std::cout << static_cast<int>(green) << "\tgreen\n";
	std::cout << static_cast<int>(blue) << "\tblue\n";
	std::cout << static_cast<int>(alpha) << "\talpha\n";
 
	return 0;
}
