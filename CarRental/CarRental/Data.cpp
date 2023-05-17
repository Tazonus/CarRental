#include "Data.h"
#include <fstream>
#include "car.h"
#include <string>

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

void Data::SortByID(vector<Car>& cars, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (cars[j].getId().compare(cars[j+1].getId()) > 0)
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