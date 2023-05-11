#ifndef CAR_H
#define CAR_H

#define errorS "NO DATA"

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Car {

	string ID;
	double cost;
	string marka;
	string model;
	string color;
	string power;
	string capacity;
	string cylinder_count;
	vector <pair<string, string>> rent_Data;

public:

	Car();
	string loader(string& arg);
	Car(string arg);

};
#endif