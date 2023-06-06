#pragma once
#include <string>
#include <map>
#include "car.h"
#include <iostream>
#include <vector>

using namespace std;

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
	void rentCar(std::string ID, time_t first, time_t second, std::string);
	void unrent(std::string ID, int _id);
	Car find(std::string ID);

	/// <summary>
	/// Wyswietla dane o samochodach
	/// </summary>
	/// <param name="sortBy">1 - sorts by ID | 2 - sorts by brand | 3 - sorts by color</param>
	void printData(int sortBy);

	/// <summary>
	/// Sorts vector of Car objects by their ID attribute
	/// </summary>
	/// <param name="cars"> vactor of Car objects</param>
	/// <param name="n"> size of the vecot</param>
	void SortByID(vector<Car>& cars, int n);

	/// <summary>
	/// Sorts vector of Car object by their Marka attribute
	/// </summary>
	/// <param name="cars"> Vector of Car objects</param>
	/// <param name="n"> Size of the vector</param>
	void SortByBrand(vector<Car>& cars, int n);

	/// <summary>
	/// Sorts vector of Car objects by their Kolor attribute
	/// </summary>
	/// <param name="cars"> Vector of Car objects</param>
	/// <param name="n"> Size of the vector</param>
	void SortByColor(vector<Car>& cars, int n);
};
