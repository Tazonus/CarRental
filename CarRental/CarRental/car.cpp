#include "car.h"

Car::Car()
{
	this->ID = errorS;
	this->cost = -1;
	this->marka = errorS;
	this->model = errorS;
	this->color = errorS;
	this->power = errorS;
	this->capacity = errorS;
	this->cylinder_count = errorS;
}

Car::Car(string arg)
{
	this->ID = loader(arg);
	{
		string temp = loader(arg);
		if (temp != "NO DATA" || temp != "") istringstream(temp) >> this->cost;
		else cost = -1;
	}
	this->marka = loader(arg);
	this->model = loader(arg);
	this->color = loader(arg);
	this->power = loader(arg);
	this->capacity = loader(arg);
	this->cylinder_count = loader(arg);
	while (arg.find_first_of(';') != -1){
		string first = loader(arg);
		string second = loader(arg);
		this->rent_Data.push_back({ first,second });
	}
}

string Car::loader(string& arg)
{
	int sep = arg.find_first_of(';');

	if (sep == -1) return errorS;

	string temp = arg.substr(0, sep);
	arg.erase(0, sep + 1);

	cout << temp << endl;
	return temp;
}