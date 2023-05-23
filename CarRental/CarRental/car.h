#pragma once
#include <string>
#include <vector>
#include "RentedCar.h"
#include "Engine.h"
#define errorS "NO DATA"

class Car :
	public RentedCar,
	private Engine
{
	//variables
	std::string ID;
	double cost;
	std::string marka;
	std::string model;
	std::string color;
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