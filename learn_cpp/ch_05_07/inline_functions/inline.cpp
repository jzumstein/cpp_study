#include <iostream>
#include <string>

int main()
{
	std::cout << ((5 < 6) ? 5 : 6) << "\n";
	std::cout << ((12 > 56) ? 12 : 56) << "\n";

	std::string modTwo{ "NO WAYYYY!" };
	std::string modThree{ "Yes WAYYY!" };
	int res = ((5 % 2) < (18 % 3) ? 0 : 1);
	std::string oString{};

	if (res > 0) {
		oString += modTwo;
	}
	else
	{
		oString += modThree;
	}

	std::cout << oString;
	return 0;
}