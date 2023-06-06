#pragma once
#include <string>
#include <vector>
#include "RentedCar.h"
#include "Engine.h"

#define errorS "NO DATA"

using namespace std;

class Car :
	public RentedCar,
	public Engine
{
	//variables
	std::string ID;
	double cost;
	std::string marka;
	std::string model;
	std::string color;
	
	/// <summary>
	/// Loads a car from string arguments
	/// </summary>
	/// <param name="arg"> string arguments containging car data</param>
	/// <returns> string without semicolon</returns>
	std::string loader(std::string& arg);

public:

	/// <summary>
	/// Default constructor creates empty Car object
	/// </summary>
	Car();

	/// <summary>
	/// Constructor that creates Car object using arguments in string format
	/// </summary>
	/// <param name="arg"> string containing car arguments</param>
	Car(string arg);

	/// <summary>
	/// Converts Car data to string
	/// </summary>
	/// <returns>string containing Car arguments</returns>
	string dataToString();

	/// <summary>
	/// Prints headline in console
	/// </summary>
	static void printHeadLine();

	/// <summary>
	/// Prints data of a car
	/// </summary>
	void printData();

	/// <summary>
	/// Returns ID
	/// </summary>
	string getId();

	/// <summary>
	/// Returns Brand
	/// </summary>
	string getBrand();

	/// <summary>
	/// Returns Color
	/// </summary>
	string getColor();

	/// <summary>
	/// Operator to compare two Cars if they are equal
	/// </summary>
	/// <param name="d">object to compare to</param>
	/// <returns>true if two object are the same</returns>
	bool operator == (const Car& d) const {
		if (d.ID == this->ID
			&& d.cost == this->cost
			&& d.marka == this->marka
			&& d.model == this->model
			&& d.color == this->color
			&& d.capacity == this->capacity
			&& d.power == this->power
			&& d.cylinder_count == this->cylinder_count)
		{
			return true;
		}
		else
			return false;
	}

	/// <summary>
	/// Operator to compare two Cars if they are not equal
	/// </summary>
	/// <param name="d">object to compare to</param>
	/// <returns>true if two object are not the same</returns>
	bool operator != (const Car& d) const {
		if (d.ID == this->ID
			&& d.cost == this->cost
			&& d.marka == this->marka
			&& d.model == this->model
			&& d.color == this->color
			&& d.capacity == this->capacity
			&& d.power == this->power
			&& d.cylinder_count == this->cylinder_count)
		{
			return false;
		}
		else
			return true;
	}

};