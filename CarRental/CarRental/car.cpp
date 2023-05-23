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
void Car::printData() {
	std::cout << "Rejestracja: "	 << ID				<< std::endl;
	std::cout << "Koszt: "			 << cost			<< std::endl;
	std::cout << "Marka: "			 << marka			<< std::endl;
	std::cout << "Model: "			 << model			<< std::endl;
	std::cout << "Kolor: "			 << color			<< std::endl;
	std::cout << "Moc: "			 << power			<< std::endl;
	std::cout << "Pojemnoœæ: "	 	 << capacity		<< std::endl;
	std::cout << "Iloœæ Cylindrów: " << cylinder_count  << std::endl;
	std::cout << "Rezerwacje: "<< std::endl;
	for (int i = 0; i < countTimeStamps(); i++){
		std::cout << timeStampToString(i);
	}
}
std::string Car::getId(){
	return ID;
}