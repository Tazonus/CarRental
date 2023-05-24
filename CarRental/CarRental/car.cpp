#include "car.h"
#include <iostream>
#include <sstream>
#define errorS "NO DATA"

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

Car::Car(std::string arg)
{
	this->ID = loader(arg);
	{
		std::string temp = loader(arg);
		if (temp != "NO DATA" || temp != "") std::istringstream(temp) >> this->cost;
		else cost = -1;
	}

	this->marka = loader(arg);
	this->model = loader(arg);
	this->color = loader(arg);
	this->power = loader(arg);
	this->capacity = loader(arg);
	this->cylinder_count = loader(arg);

	while (arg.find_first_of(';') != -1){
		time_t first = 0, second = 0;
		std::string temp = loader(arg);
		if (temp != "NO DATA" || temp != "") {
			
			std::istringstream(temp) >> first;
			temp = loader(arg);

			if (temp != "NO DATA" || temp != "") {
				std::istringstream(temp) >> second;
			}
			else second = first;

			this->addTimeStamp(first, second);
		}
	}

	sortTimeStamps();
}

std::string Car::loader(std::string& arg)
{
	size_t separator = arg.find_first_of(';');
	if (separator == -1) return errorS;
	std::string temp = arg.substr(0, separator);
	arg.erase(0, separator + 1);

	return temp;
}
std::string Car::dataToString()
{
	std::string temp = "";
	temp += ID + ';';
	temp += std::to_string(cost) + ';';
	temp += marka + ';';
	temp += model + ';';
	temp += color + ';';
	temp += power + ';';
	temp += capacity + ';';
	temp += cylinder_count + ';';

	for (int i = 0; i < countTimeStamps(); i++)
	{
		std::pair<time_t, time_t> temp_ts = getTimeStamp(i);
		temp += std::to_string(temp_ts.first) + ';';
		temp += std::to_string(temp_ts.second) + ';';
	}
	return temp;
}

void Car::printData()
{
	cout.width(20);
	cout << this->ID;
	cout.width(20);
	cout << this->cost;
	cout.width(20);
	cout << this->marka;
	cout.width(20);
	cout << this->model;
	cout.width(20);
	cout << this->color;
	cout.width(20);
	cout << this->power;
	cout.width(20);
	cout << this->capacity;
	cout.width(20);
	cout << this->cylinder_count;

	for (int i = 0; i < countTimeStamps(); i++)
	{
		std::pair<time_t, time_t> temp_ts = getTimeStamp(i);
		cout.width(15);
		cout << timeStampToString(temp_ts.first);
		cout.width(15);
		cout << timeStampToString(temp_ts.second);
	}
	cout << "\n\n";
}

void Car::printHeadLine()
{
	cout.width(20);
	cout << "ID";
	cout.width(20);
	cout << "Koszt";
	cout.width(20);
	cout << "Marka";
	cout.width(20);
	cout << "Model";
	cout.width(20);
	cout << "Kolor";
	cout.width(20);
	cout << "Moc silnka";
	cout.width(20);
	cout << "Pojemnosc";
	cout.width(20);
	cout << "Ilosc cylindrow" << endl;

	for (int i = 0; i < 8 * 20; i++)
		cout << "-";
	cout << endl;
}


std::string Car::getId(){
	return ID;
}

string Car::getBrand()
{
	return this->marka;
}

string Car::getColor()
{
	return this->color;
}
