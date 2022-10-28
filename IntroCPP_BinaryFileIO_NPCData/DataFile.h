#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
public:
	struct Record {
		Image image;
		string name;
		int age;
	};

private:
	int recordCount;
	Record* record;
	//std::vector<Record*> records;	// delete this vector. Load only the required record 



public:
	DataFile();
	~DataFile();

	void AddRecord(string imageFilename, string name, int age);
	Record* GetRecord(int index);

	// Subtract 1 from the record count so that when you press the right arrow
	// You'll never get a crash when you're on the last record
	int GetRecordCount() { return recordCount - 1; };

	void Save(string filename);
	void Load(string filename, int index);

private:
	void Clear();

};

