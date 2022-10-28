#include <iostream>
#include <fstream>
#include <string>

int main()
{
	//
	// TEXT FILES
	//

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

	//
	// BINARY FILES
	//
	
	std::fstream saveFile;
	saveFile.open("save.dat", std::ios::out | std::ios::binary);
	int score = 32;
	saveFile.write((const char*)&score, sizeof(int));
	saveFile.close();

	std::fstream loadFile;
	loadFile.open("save.dat", std::ios::in | std::ios::binary);
	int lastScore = 0;
	loadFile.read((char*)&lastScore, sizeof(int));
	loadFile.close();
	std::cout << "Last Score: " << lastScore << std::endl;

	return 0;
}