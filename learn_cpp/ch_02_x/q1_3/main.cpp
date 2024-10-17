#include "io.h"
#include <iomanip>
#include <iostream>

int main()
{
	//int u_num_x{readNumber()};
	//int u_num_y{readNumber()};
	//writeAnswer(u_num_x + u_num_y);
	std::cout << std::left;
	std::cout << std::setw(16) << "Fruits:" << "Apples, Bananas, Cherries\n";
	std::cout << std::setw(16) << "Vegetables:" << "Asperagus, Blumen Onion, Cauliflower\n";
}
