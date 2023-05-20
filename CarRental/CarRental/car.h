#pragma once
#include <string>
#include <vector>
#include "RentedCar.h"
#define errorS "NO DATA"

using namespace std;

class Car :
	public RentedCar
{
	//variables
	std::string ID;
	double cost;
	std::string marka;
	std::string model;
	std::string color;
	std::string capacity;
	std::string power;
	std::string cylinder_count;
	//functions
	std::string loader(std::string& arg);

public:

	//functions
	Car();
	Car(string arg);
	string dataToString();
	static void printHeadLine();
	void printData();
	string getId();
	string getBrand();
	string getColor();

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