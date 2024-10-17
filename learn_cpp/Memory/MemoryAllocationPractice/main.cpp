#include <iostream>
#include <cstdint>

int main()
{
	// To optimize performance, use std::int_least64_t for memory processing, and std::intfast64_t for CPU processing.
	// std::uint8_t doesn't work on this architecture.
	std::uint16_t small { 24 };
	std::uint64_t big { 154132153 };

	std::cout << "\nShould print small: " << small << "\n" << big << "\n";
	// Formatted to IEEE 754 format.
	std::cout << std::numeric_limits<float>::is_iec559 << '\n';
	std::cout << std::numeric_limits<double>::is_iec559 << '\n';
	std::cout << std::numeric_limits<long double>::is_iec559 << '\n';
}