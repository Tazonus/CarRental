#pragma once
#include <string>
#include <map>
#include "car.h"
#include <iostream>
#include <vector>

using namespace std;

class Data {
private:
	/// <summary>
	/// Recently used file
	/// </summary>
	std::string curentFilename;
	
	/// <summary>
	/// Hashmap that stores id of a car and a Car object equivelant to this ID
	/// </summary>
	std::map <std::string, Car> carData;

public:

	/// <summary>
	/// Loads data from .txt file
	/// </summary>
	/// <param name="filename"> file path </param>
	void loadData(std::string filename);

	/// <summary>
	/// Saves data to .txt file
	/// </summary>
	/// <param name="filename"> file path </param>
	void saveData(std::string filename);

	/// <summary>
	/// Prints all data
	/// </summary>
	void printAllData();

	/// <summary>
	/// Adds car to data
	/// </summary>
	/// <param name="arg"> car object</param>
	void addCar(Car arg);

	/// <summary>
	/// Adds car to data
	/// </summary>
	/// <param name="arg"> string of car arguments</param>
	void addCar(std::string arg);

	/// <summary>
	/// removes car from data
	/// </summary>
	/// <param name="ID"> car id </param>
	void removeCar(std::string ID);

	/// <summary>
	/// Rents car (adds timestamps and contact)
	/// </summary>
	/// <param name="ID"> id of a car</param>
	/// <param name="first"> first date</param>
	/// <param name="second"> second date</param>
	/// <param name=""> contact number </param>
	void rentCar(std::string ID, time_t first, time_t second, std::string);

	/// <summary>
	/// Unrents a car (removes timestamps)
	/// </summary>
	/// <param name="ID"> id of a car</param>
	/// <param name="_id"> id of the rent</param>
	void unrent(std::string ID, int _id);

	/// <summary>
	/// Finds a car object of given ID
	/// </summary>
	/// <param name="ID"> car id</param>
	/// <returns> Car object of given id (if doesnt exist returns empty car)</returns>
	Car find(std::string ID);

	/// <summary>
	/// Prints data of cars
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
