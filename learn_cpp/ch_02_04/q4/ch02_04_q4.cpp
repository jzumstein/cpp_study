#include <iostream>
#include <chrono>

int doubleNumber(int x)
{
	//return x * 2; Executes 2.5x slower than + operator.
	return x + x;
}

int main()
{
	int num{5};
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << "Number = " << num << "\nDouble Number = " << doubleNumber(num);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> duration = end - start;
	std::cout << "\nExecution time: " << duration.count() << " microseconds" << "\n";
}