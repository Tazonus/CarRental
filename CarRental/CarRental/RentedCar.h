#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <vector>
#include <string>

class RentedCar
{
public:
	std::pair <time_t, time_t> getTimeStamp(int id);
	void UpdateTimeStamp();
	void addTimeStamp(time_t first, time_t second);
	void removeTimeStamp(int id);
	void sortTimeStamps();
	size_t countTimeStamps();
	std::string timeStampToString(int id);

private:
	std::vector<std::pair<time_t, time_t>> timeStamps;
};

