#include <iostream>

int doubleNumber(int x)
{
	return x + x;
}

int main()
{
	int num{};
	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << doubleNumber(num);
}