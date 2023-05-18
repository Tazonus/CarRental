#include "Data.h"
#include <iostream>
#include <fstream>

void Data::loadData(std::string filename) {
	carData.clear();

	ifstream file;
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
	ofstream file;
	file.open(filename);
	for (std::pair<std::string, Car> x : carData) {

		file << x.second.dataToString() << endl;
	}
	file.close();
}

void Data::printData()
{
	for (std::pair<std::string, Car> x : carData){
		x.second.printData();
	}
}
Car Data::find(std::string ID) {
	return carData.find(ID)->second;
}