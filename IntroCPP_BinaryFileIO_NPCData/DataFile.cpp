#include "DataFile.h"
#include <fstream>
#include <iostream>
using namespace std;

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	Clear();
}

void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	Record* r = new Record;
	r->image = i;
	r->name = name;
	r->age = age;

	recordCount++;
}

DataFile::Record* DataFile::GetRecord(int index)
{
	Load("npc_data.dat", index);
	return record;
}

void DataFile::Save(string filename)
{
	ofstream outfile(filename, ios::binary);

	outfile.write((char*)&recordCount, sizeof(int));

	for (int i = 0; i < recordCount; i++)
	{		
		Color* imgdata = GetImageData(record->image);
				
		int imageSize = sizeof(Color) * record->image.width * record->image.height;
		int nameSize = record->name.length();
		int ageSize = sizeof(int);

		outfile.write((char*)&record->image.width, sizeof(int));
		outfile.write((char*)&record->image.height, sizeof(int));
		
		outfile.write((char*)&nameSize, sizeof(int));
		outfile.write((char*)&ageSize, sizeof(int));

		outfile.write((char*)imgdata, imageSize);
		outfile.write((char*)record->name.c_str(), nameSize);
		outfile.write((char*)&record->age, ageSize);
	}

	outfile.close();
}

void DataFile::Load(string filename, int index)
{
	Clear();

	ifstream infile(filename, ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	int nameSize = 0;
	int ageSize = 0;
	int width = 0, height = 0, format = 0, imageSize = 0;

	int widthOffset = 0;
	int heightOffset = 0;
	int imageSizeOffset = 0;
	int size = sizeof(int);
	for (int i = 0; i < index; i++)
	{
		int tempWidth = 0;
		int tempHeight = 0;
		int tempNameSize = 0;
		int tempAgeSize = 0;
		infile.read((char*)&tempWidth, sizeof(int));
		infile.read((char*)&tempHeight, sizeof(int));
		infile.read((char*)&tempNameSize, sizeof(int));
		infile.read((char*)&tempAgeSize, sizeof(int));
		size = infile.tellg();
		size += sizeof(Color) * tempWidth * tempHeight;
		size += tempNameSize + tempAgeSize;
		infile.seekg(size);
	}

	std::cout << size << std::endl;

	infile.seekg(size, std::ios::beg);
	infile.read((char*)&width, sizeof(int)); // FIXED
	infile.read((char*)&height, sizeof(int)); // FIXED

	imageSize = sizeof(Color) * width * height;

	infile.read((char*)&nameSize, sizeof(int)); // FIXED
	infile.read((char*)&ageSize, sizeof(int)); // FIXED

	char* imgdata = new char[imageSize];
	infile.read(imgdata, imageSize); // VARIABLE

	Image img = LoadImageEx((Color*)imgdata, width, height);
	char* name = new char[nameSize + 1]; // Add one to the nameSize for the actual array size to make room for the null terminator
	int age = 0;

	infile.read((char*)name, nameSize); // VARIABLE
	infile.read((char*)&age, ageSize); // VARIABLE

	std::cout << infile.tellg() << std::endl;

	// Add the null terminator
	name[nameSize] = '\0';

	record = new Record();
	record->image = img;
	record->name = string(name);
	record->age = age;

	delete[] imgdata;
	delete[] name;

	infile.close();
}

void DataFile::Clear()
{
	delete record;
	recordCount = 0;
}