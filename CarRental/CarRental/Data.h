#pragma once
#include <iostream>
#include <string>
#include <map>
#include "car.h"

using namespace std;

class Data {
private:
	string curentFilename;
public:
	map <string, Car> carData;

	void loadData(string filename);
	void saveData(string filename);
	void printData();
};
