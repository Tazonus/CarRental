#include "RentedCar.h"

pair <time_t, time_t> RentedCar::getTimeStamp(int id) {
	if (id < timeStamps.size()) {
		return timeStamps.at(id);
	}
	else {
		cout << "This car has only " << timeStamps.size() << " Reservations, input value: " << (id + 1);
	}
}
void RentedCar::UpdateTimeStamp() {
	sortTimeStamps();
	int i = 0;
	time_t tim = time(0);
	for (pair<time_t, time_t> var : timeStamps)
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
	timeStamps.push_back({ first,second });
}
void RentedCar::removeTimeStamp(int id)
{
	if (id < timeStamps.size()) {
		timeStamps.erase(timeStamps.begin() + id);
	}
	else {
		cout << "This car has only " << timeStamps.size() << " Reservations, input value: " << (id + 1);
	}
}
void RentedCar::sortTimeStamps() {
	int n = timeStamps.size();
	for (int iter = 0; iter < n; iter++)
	{
		for (int i = 1; i < n; i++) {
			if (timeStamps.at(i).first < timeStamps.at(i - 1).first) {
				timeStamps.at(i).swap(timeStamps.at(i - 1));
			}
		}
	}
}