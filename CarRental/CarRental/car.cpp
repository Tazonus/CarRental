#include "car.h"
#include <iostream>
#include <sstream>

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
		std::string first = loader(arg);
		std::string second = loader(arg);
		this->rent_Data.push_back({first, second});
	}
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

	for (std::pair<std::string, std::string> x : rent_Data)//Do zmiany jak dodamy klase rented car, sam zapis do pliku nie bêdzie siê wiele ró¿ni³
	{
		temp += x.first + ';';
		temp += x.second + ';';
	}
	return temp;
}
void Car::printData() {
	std::cout << "Rejestracja: "<< ID << endl;
	std::cout << "Koszt: " << cost << endl;
	std::cout << "Marka: " << marka <<endl;
	std::cout << "Model: " << model << endl;
	std::cout << "Kolor: " << color << endl;
	std::cout << "Moc: " << power << endl;
	std::cout << "Pojemnoœæ: " << capacity << endl;
	std::cout << "Iloœæ Cylindrów: " << cylinder_count << endl;
}
std::string Car::getId(){
	return ID;
}