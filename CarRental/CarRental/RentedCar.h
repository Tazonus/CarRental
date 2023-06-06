#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <vector>
#include <string>

class RentedCar
{
private:
	/// <summary>
	/// Vector of pairs of time_t variables that cointains all timestamps of renting the car
	/// </summary>
	std::vector<std::pair<time_t, time_t>> timeStamps;

	/// <summary>
	/// Vector of strings containing contact numbers corresponding to each timestamp from vector timeStamp
	/// </summary>
	std::vector<std::string> contacts;

public:
	/// <summary>
	/// Returns pair of time_t (timeStamp of rent) by give ID number
	/// </summary>
	/// <param name="id"> id of the rent </param>
	/// <returns> timestamp in pair of time_t format</returns>
	std::pair <time_t, time_t> getTimeStamp(int id);

	/// <summary>
	/// Removes outdated timestamps and checks if they contradict they get remove
	/// </summary>
	void UpdateTimeStamp();

	/// <summary>
	/// Adds time stamp and contact number
	/// </summary>
	/// <param name="first"> first date</param>
	/// <param name="second"> second date</param>
	/// <param name=""> mobile number</param>
	void addTimeStamp(time_t first, time_t second, std::string);

	/// <summary>
	/// Removes timestamp and contact of given id
	/// </summary>
	/// <param name="id"> -> id of a timestamp</param>
	void removeTimeStamp(int id);

	/// <summary>
	/// Sorts timestamps using bubblesort from earliest to latest
	/// </summary>
	void sortTimeStamps();

	/// <summary>
	/// Returns size of timeStamp vector
	/// </summary>
	size_t countTimeStamps();

	/// <summary>
	/// Converts timeStamp of given ID to string
	/// </summary>
	/// <param name="id"> -> id of a timestamp</param>
	/// <returns>string value of a timestamp</returns>
	std::string timeStampToString(int id);

	/// <summary>
	/// Returns contact of given id
	/// </summary>
	/// <param name="id"> -> contact id number </param>
	/// <returns>string containing the contact</returns>
	std::string getContact(int id);

};

