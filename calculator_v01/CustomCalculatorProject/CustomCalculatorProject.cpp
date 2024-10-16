// CustomCalculatorProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double add(double x = { 0 }, double y = { 0 })
{
    double sum = x + y;
    return sum;
}

double sub(double x = { 0 }, double y = { 0 })
{
    double sub = x - y;
    return sub;
}

double mult(double x = { 0 }, double y = { 0 })
{
    double total = x * y;
    return total;
}

double div(double x = { 0 }, double y = { 0 })
{
    double remainder = x / y;
    return remainder;
}

void main()
{
    double num_one;
    double num_two;
    std::cout << "Enter two numbers: \n";
    std::cin >> num_one;
    std::cin >> num_two;
    double sum_to_print = add(num_one, num_two);
    std::cout << "Sum = " << sum_to_print << "\n";
    double total_to_print = mult(num_one, num_two);
    std::cout << "Total = " << total_to_print << "\n";
    double remainder_to_print = div(num_one, num_two);
    std::cout << "Remainder = " << remainder_to_print << "\n";
    double sub_to_print = sub(num_one, num_two);
    std::cout << "Sub = " << sub_to_print << "\n";
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
