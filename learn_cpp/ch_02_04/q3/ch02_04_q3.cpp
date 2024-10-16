#include <iostream>

int doubleNumber(int num)
{
	return num + num;
}

int main()
{
	int x{ 5 };
	std::cout << doubleNumber(x);
}