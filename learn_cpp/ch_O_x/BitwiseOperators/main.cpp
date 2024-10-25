#include <iostream>
#include <string>
#include <string_view>
#include <bitset>
#include "math.h"


int main() {
	std::bitset<8> mybitset{ 0b0000'0101};
	mybitset.set(3);
	mybitset.flip(4);
	mybitset.reset(4);

	std::cout << "All the bits: " << mybitset << '\n';
	std::cout << "Bit 3 has value: " << mybitset.test(3) << '\n';
	std::cout << "Bit 4 has value: " << mybitset.test(4) << '\n';
	std::cout << mybitset.size() << " bits are in the bitset\n";
	std::cout << mybitset.count() << " bits are set to true\n";
	std::cout << std::boolalpha;
	std::cout << "All bits are true: " << mybitset.all() << '\n';
	std::cout << "Some bits are true: " << mybitset.any() << '\n';
	std::cout << "No bits are true: " << mybitset.none() << '\n';

	return 0;
}