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
	int separator = arg.find_first_of(';');
	if (separator == -1) return errorS;
	string temp = arg.substr(0, separator);
	arg.erase(0, separator + 1);

	return temp;
}
string Car::dataToString()
{
	string temp = "";
	temp += ID + ';';
	temp += cost + ';';
	temp += marka + ';';
	temp += model + ';';
	temp += color + ';';
	temp += power + ';';
	temp += capacity + ';';
	temp += cylinder_count + ';';

	for (pair<string,string> x : rent_Data)//Do zmiany jak dodamy klase rented car, sam zapis do pliku nie bêdzie siê wiele ró¿ni³
	{
		temp += x.first + ';';
		temp += x.second + ';';
	}
	return temp;
}
void Car::printData() {
	cout << "Rejestracja: "<< ID << endl;
	cout << "Koszt: " << cost << endl;
	cout << "Marka: " << marka <<endl;
	cout << "Model: " << model << endl;
	cout << "Kolor: " << color << endl;
	cout << "Moc: " << power << endl;
	cout << "Pojemnoœæ: " << capacity << endl;
	cout << "Iloœæ Cylindrów: " << cylinder_count << endl;
}
string Car::getId(){
	return ID;
}