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
	void printAllData();
	void addCar(Car arg);
	void addCar(std::string arg);
	void removeCar(std::string ID);
	Car find(std::string ID);
};
