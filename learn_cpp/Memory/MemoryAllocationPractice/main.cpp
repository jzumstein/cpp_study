#include <iostream>
#include <cstdint>

int main()
{
	std::uint8_t small { 24 };
	std::uint64_t big { 154132153 };

	std::cout << "\nShould print small: " << small << "\n" << big;
}