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

	/// <summary>
	/// Wyswietla dane o samochodach
	/// </summary>
	/// <param name="sortBy">1 - sorts by ID | 2 - sorts by brand | 3 - sorts by color</param>
	void printData(int sortBy);

private:
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
