#include "RentedCar.h"
#include <iostream>

std::pair <time_t, time_t> RentedCar::getTimeStamp(int id) {
	if (id < timeStamps.size()) {
		return timeStamps.at(id);
	}
	else {
		std::cout << "This car has only " << timeStamps.size() << " Reservations, input value: " << (id + 1);
	}
}
void RentedCar::UpdateTimeStamp() {
	sortTimeStamps();
	int i = 0;
	time_t tim = time(0);
	for (std::pair<time_t, time_t> var : timeStamps)
	{
		if (var.second < tim) {
			i++;
			continue;
		}
		else break;
	}
	if (i != 0) {
		if (i == 1) timeStamps.erase(timeStamps.begin());
		else timeStamps.erase(timeStamps.begin(), timeStamps.begin() + i);
	}
}
void RentedCar::addTimeStamp(time_t first, time_t second) {
	if (first < second){
		timeStamps.push_back({second, first});
	}
	else {
		timeStamps.push_back({first, second});
	}
}
void RentedCar::removeTimeStamp(int id)
{
	if (id < timeStamps.size()) {
		timeStamps.erase(timeStamps.begin() + id);
	}
	else {
		std::cout << "This car has only " << timeStamps.size() << " Reservations, input value: " << (id + 1);
	}
}
void RentedCar::sortTimeStamps() {
	size_t n = timeStamps.size();
	for (size_t iter = 0; iter < n; iter++)
	{
		for (size_t i = 1; i < n; i++) {
			if (timeStamps.at(i).first < timeStamps.at(i - 1).first) {
				timeStamps.at(i).swap(timeStamps.at(i - 1));
			}
		}
	}
}

size_t RentedCar::countTimeStamps() {
	return timeStamps.size();
}

std::string RentedCar::timeStampToString(int id) {
	time_t first = timeStamps.at(id).first;
	time_t second = timeStamps.at(id).second;
	
	struct tm* ti;
	ti = localtime(&first);

	std::string output = "";
	output += std::to_string(ti->tm_year + 1900);
	output += ".";
	output += std::to_string(ti->tm_mon + 1);
	output += ".";
	output += std::to_string(ti->tm_mday);

	if (first != second) {
		ti = localtime(&second);

		output += " - ";
		output += std::to_string(ti->tm_year + 1900);
		output += ".";
		output += std::to_string(ti->tm_mon + 1);
		output += ".";
		output += std::to_string(ti->tm_mday);
	}
	return output;
}