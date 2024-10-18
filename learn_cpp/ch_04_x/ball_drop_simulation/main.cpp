#include <iostream>

// #define gravity = 9.8
// Preferred method is const variables over macros.

float distance_fallen(float t_height, float seconds)
{
	const float gravity = 9.8;
	float height  = (t_height - (gravity * (seconds * seconds) / 2));
	if (height <= 0)
	{
		return 0;
	}

	return height;
}


int main()
{
	std::cout << "Enter the tower height: ";
	float tower_height{};
	std::cin >> tower_height;
	
	std::cout << "At 0 seconds, the ball is at height: " << distance_fallen(tower_height, 0) << " meters\n";
	std::cout << "At 1 seconds, the ball is at height: " << distance_fallen(tower_height, 1) << " meters\n";
	std::cout << "At 2 seconds, the ball is at height: " << distance_fallen(tower_height, 2) << " meters\n";
	std::cout << "At 3 seconds, the ball is at height: " << distance_fallen(tower_height, 3) << " meters\n";
	std::cout << "At 4 seconds, the ball is at height: " << distance_fallen(tower_height, 4) << " meters\n";
	std::cout << "At 5 seconds, the ball is at height: " << distance_fallen(tower_height, 5) << " meters\n";

}