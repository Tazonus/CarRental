#pragma once
#include <string>
#include <map>
#include "car.h"

class Data {
private:
	std::string curentFilename;
	std::map <std::string, Car> carData;
public:
	void loadData(std::string filename);
	void saveData(std::string filename);
	void printData();
	Car find(std::string ID);
};
