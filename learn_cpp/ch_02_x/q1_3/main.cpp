#include "io.h"
#include <iostream>

int main()
{
	int u_num_x{readNumber()};
	int u_num_y{readNumber()};
	writeAnswer(u_num_x + u_num_y);
}