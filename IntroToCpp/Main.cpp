#include <iostream> // std::cout

int Sum(int a, int b); // Declaring a sum function

void main()
{
	std::cout << "Hello World!" << std::endl;

	int total = Sum(2, 3);

	std::cout << total << std::endl;

	return;
}

int Sum(int a, int b)
{
	return a + b;
}