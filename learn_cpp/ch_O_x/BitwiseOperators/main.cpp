#include <iostream>
#include <string>
#include <string_view>
#include <bitset>
#include "math.h"

/*
Bitwise Rotator Function
std::bitset<4> rotl(std::bitset<4> bits)
{
	// bits << 1 does the left shift
	// bits >> 3 handle the rotation of the leftmost bit
	return (bits << 1) | (bits >> 3);
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}*/

int main() {
	std::bitset<8> mybitset{ 0b0000'0101};
	std::bitset<16> bs_sixteen{ 0b0101'0101'0101'0101 };
	mybitset.set(3);
	mybitset.flip(4);
	mybitset.reset(4);
	/*std::cout << "All the bits: " << mybitset << '\n';
	std::cout << "Bit 3 has value: " << mybitset.test(3) << '\n';
	std::cout << "Bit 4 has value: " << mybitset.test(4) << '\n';
	std::cout << mybitset.size() << " bits are in the bitset\n";
	std::cout << mybitset.count() << " bits are set to true\n";
	std::cout << std::boolalpha;
	std::cout << "All bits are true: " << mybitset.all() << '\n';
	std::cout << "Some bits are true: " << mybitset.any() << '\n';
	std::cout << "No bits are true: " << mybitset.none() << '\n';*/


	std::cout << "bs_sixteen: " << bs_sixteen << '\n';
	std::cout << "Bits in set: " << bs_sixteen.size() << '\n';
	std::cout << "True bits in set: " << bs_sixteen.count() << '\n';

	std::cout << "Bits shifted left 1: " << (bs_sixteen << 1) << '\n';
	std::cout << "Bits shifted right 2: " << (bs_sixteen >> 2) << '\n';
	std::cout << "Not bits: " << (~bs_sixteen) << '\n'; //Not unary so you can use x = ~x to flip.
	std::cout << "OR operator: " << (std::bitset<4>{0b1000} | std::bitset<4>{0b0011}) << '\n';
	std::cout << "AND operator: " << (std::bitset<4>{0b1111} & std::bitset<4>{0b0011}) << '\n';
	std::cout << "XOR operator: " << (std::bitset<4>{0b1110} ^ std::bitset<4>{0b0011}) << '\n';
	return 0;
}