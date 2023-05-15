#include "Data.h"
#include <fstream>
#include "car.h"

using namespace std;

void Data::loadData(string filename) {
	carData.clear();

	ifstream file;
	file.open(filename);
	string tempString;
	while (!file.eof()) {
		getline(file, tempString);
		Car tempCar(tempString);
		carData.insert({ tempCar.getId(),tempCar });
	}

	file.close();
}

void Data::saveData(string filename) {
	if (filename == "") filename = curentFilename;
	ofstream file;
	file.open(filename);
	for (pair<string, Car> x : carData) {
		file << x.second.dataToString() << endl;
	}
	file.close();
}

void Data::printData()
{
	for (auto const& pair : this->carData) 
	{
		auto car = (Car)pair.second;
		cout << car.dataToString() << endl;
	}
}