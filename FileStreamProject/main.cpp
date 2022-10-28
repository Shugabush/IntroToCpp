#include <iostream>
#include <fstream>
#include <string>

int main()
{
	// Writing to a File
	std::fstream bioFile;
	bioFile.open("bio.txt", std::ios::out);

	if (bioFile.is_open())
	{
		bioFile << "My name is John Madden.\n" << std::endl;
		bioFile << "I like football!\n" << std::endl;
	}
	else
	{
		std::cout << "Failed to open file!" << std::endl;
	}

	bioFile.close();

	// Reading from a File
	std::fstream readFile;
	readFile.open("bio.txt", std::ios::in);

	while (readFile.is_open() && !readFile.eof())
	{
		std::string temp;
		std::getline(readFile, temp);

		// DEBUG: print the line to the screen
		std::cout << temp << std::endl;
	}
	readFile.close();

	return 0;
}