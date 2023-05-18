#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <vector>
using namespace std;

class RentedCar
{
public:
	pair <time_t, time_t> getTimeStamp(int id);
	void UpdateTimeStamp();
	void addTimeStamp(time_t first, time_t second);
	void removeTimeStamp(int id);
	void sortTimeStamps();
	
private:
	vector < pair < time_t, time_t >> timeStamps;
};

