#include <iostream>

bool isPrime(int x)
{
	switch (x)
	{
		case 2:
		case 3:
		case 5:
		case 7:
			return true;
	}

	return false;
}

int main()
{
	
	std::cout << "Enter an integer 0 - 9: ";
	int input{};
	std::cin >> input;
	if (isPrime(input))
	{
		std::cout << "\nInput is prime.\n";
	}
	else
	{
		std::cout << "\nInput is not prime.\n";
	}

}