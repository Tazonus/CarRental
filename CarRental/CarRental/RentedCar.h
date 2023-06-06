#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <vector>
#include <string>

class RentedCar
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="id"></param>
	/// <returns></returns>
	std::pair <time_t, time_t> getTimeStamp(int id);

	/// <summary>
	/// 
	/// </summary>
	void UpdateTimeStamp();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="first"></param>
	/// <param name="second"></param>
	/// <param name=""></param>
	void addTimeStamp(time_t first, time_t second, std::string);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="id"></param>
	void removeTimeStamp(int id);

	/// <summary>
	/// 
	/// </summary>
	void sortTimeStamps();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	size_t countTimeStamps();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="id"></param>
	/// <returns></returns>
	std::string timeStampToString(int id);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="id"> car ID number </param>
	/// <returns></returns>
	std::string getContact(int id);

private:
	std::vector<std::pair<time_t, time_t>> timeStamps;
	std::vector<std::string> contacts;
};

