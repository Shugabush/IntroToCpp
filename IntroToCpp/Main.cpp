#include <iostream> // std::cout
#include <string> // include the <string> system header

using std::string;

int Sum(int a, int b); // Declaring a sum function

int main()
{
	std::cout << "Hello World!" << std::endl;

	int total = Sum(2, 3);

	std::cout << total << std::endl;

	// std::string and Copying
	string firstName = "Alex";
	string lastName = "Wood";

	string fullName = firstName + ' ' + lastName;

	std::cout << fullName << std::endl;

	return 0;
}

int Sum(int a, int b)
{
	return a + b;
}