#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#define errorS "NO DATA"

using namespace std;

class Car {
	//variables
	string ID;
	double cost;
	string marka;
	string model;
	string color;
	string power;
	string capacity;
	string cylinder_count;
	vector <pair<string, string>> rent_Data;
	//functions
	string loader(string& arg);

public:

	//functions
	Car();
	Car(string arg);
	string dataToString();
	void printData();
	string getId();

};