#include "Data.h"
#include <iostream>
#include <fstream>

void Data::loadData(std::string filename) {
	carData.clear();

	std::ifstream file;
	file.open(filename);
	std::string temp;
	while (!file.eof()) {
		getline(file, temp);
		Car tempCar(temp);
		carData.insert({ tempCar.getId(),tempCar });
	}

	file.close();
}

void Data::saveData(std::string filename) {
	if (filename == "") filename = curentFilename;
	std::ofstream file;
	file.open(filename);
	for (std::pair<std::string, Car> x : carData) {

		file << x.second.dataToString() << std::endl;
	}
	file.close();
}

void Data::printAllData()
{
	for (std::pair<std::string, Car> x : carData){
		x.second.printData();
	}
}

void Data::addCar(Car arg) {
	carData.insert({ arg.getId(), arg });
}
void Data::addCar(std::string arg) {
	Car temp(arg);
	carData.insert({ temp.getId(), temp });
}
void Data::removeCar(std::string ID) {
	carData.erase(carData.find(ID));
}

Car Data::find(std::string ID) {
	if (carData.find(ID) != carData.end()) {
		return carData.find(ID)->second;
	}
	else
	{
		return Car();
	}
}