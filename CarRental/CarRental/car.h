#pragma once
#include <string>
#include <vector>
#include "RentedCar.h"
#define errorS "NO DATA"

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
	std::vector <std::pair<std::string, std::string>> rent_Data;
	//functions
	std::string loader(std::string& arg);

public:

	//functions
	Car();
	Car(std::string arg);
	std::string dataToString();
	void printData();
	std::string getId();

};