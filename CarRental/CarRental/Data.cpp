#include "Data.h"
#include <iostream>
#include <fstream>
#include "FileHandler.h"

void Data::loadData(std::string filename) {
	carData.clear();

	std::ifstream file;
	file.open(filename);
	std::string temp;

	auto fileHandler = new FileHandler();
	while (!file.eof()) {		
		getline(file, temp);

		if (temp == "")
			continue;
		Car tempCar(fileHandler->Encrypt(temp));
		carData.insert({ tempCar.getId(),tempCar });
	}

	delete(fileHandler);
	file.close();
}

void Data::saveData(std::string filename) {
	if (filename == "") filename = curentFilename;
	std::ofstream file;
	file.open(filename);

	auto fileHandler = new FileHandler();

	for (std::pair<std::string, Car> x : carData) {

		file << fileHandler->Encrypt(x.second.dataToString())<< std::endl;
	}

	delete(fileHandler);
	file.close();
}

void Data::printAllData()
{
	for (std::pair<std::string, Car> x : carData){
		x.second.printData();
	}
}

void Data::printData(int sortBy)
{
	auto t_cars = *new vector<Car>();
	for (auto const& pair : this->carData)
	{
		t_cars.push_back((Car)pair.second);
	}

	switch (sortBy)
	{
	case 1:	// sort by id
		this->SortByID(t_cars, t_cars.size());
		break;
	case 2:
		this->SortByBrand(t_cars, t_cars.size());
		break;
	case 3:
		this->SortByColor(t_cars, t_cars.size());
		break;
	default:
		this->SortByID(t_cars, t_cars.size());
	}

	Car::printHeadLine();
	for (Car t_car : t_cars)
	{
		t_car.printData();
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

void Data::SortByID(vector<Car>& cars, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (cars[j].getId().compare(cars[j + 1].getId()) > 0)
			{
				swap(cars[j], cars[j + 1]);
			}
		}
	}
}

void Data::SortByBrand(vector<Car>& cars, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (cars[j].getBrand().compare(cars[j + 1].getBrand()) > 0)
			{
				swap(cars[j], cars[j + 1]);
			}
		}
	}
}

void Data::SortByColor(vector<Car>& cars, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (cars[j].getColor().compare(cars[j + 1].getColor()) > 0)
			{
				swap(cars[j], cars[j + 1]);
			}
		}
	}
}