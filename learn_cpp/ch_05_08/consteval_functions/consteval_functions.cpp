#include <iostream>

constexpr int greater(int x, int y)
{
	return (x > y ? x : y);
}

/*consteval int smaller(int x, int y)
EXECUTES AT COMPILE TIME OR THROWS COMPILE ERROR
Only available in C++20*/

int main()
{
	constexpr int g{ greater(5,6) }; // compile time

	std::cout << g << " is greater!\n";

	std::cout << greater(5, 6) << " is greater!\n"; // probably compile time

	int x{ 5 };
	std::cout << greater(x, 6) << " is greater!\n"; // probably runtime

	std::cin >> x;
	std::cout << greater(x, 6) << " is greater!\n"; // runtime

	return 0;
}