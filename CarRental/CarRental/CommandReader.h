#pragma once
#include <string>
#include <vector>
#include "car.h"
#include "Data.h"

using namespace std;

class CommandReader
{
private:
	/// <summary>
	/// Vector of string that stores command and arguments
	/// </summary>
	vector<string> command;

	/// <summary>
	/// Data storage
	/// </summary>
	Data data;

public:
	CommandReader();
	~CommandReader();

	/// <summary>
	/// Function scans a command from console
	/// </summary>
	/// <returns>-1 line is empty</returns>
	int ReadNextLine();

	/// <summary>
	/// Function executs scanned command
	/// </summary>
	/// <param name="isAdmin"></param>
	/// <returns></returns>
	int ExecuteCommand(bool isAdmin);

private:
	/// <summary>
	/// Function checks if command is correct and if it's arguments are valid
	/// </summary>
	/// <returns>1 add | 2 remove | 3 search | 4 rent | 5 unrent | 0 no permission | -1 invalid command | -2 invalid argument</returns>
	int CheckCommand(bool isAdmin);

	/// <summary>
	/// Adds new Car object to Data map
	/// </summary>
	/// <param name="car"></param>
	void Add(Car car);

	/// <summary>
	/// Adds new Car object created from data scanned from console
	/// </summary>
	void Add();

	void Remove();
	void Rent();
	void Unrent();

	/// <summary>
	/// Prints values from map
	/// </summary>
	void Search();

	string Hash(string line);


	/// <summary>
	/// Scans car data
	/// </summary>
	/// <returns>Returns car data in string format, separated by semicolon</returns>
	string InputCarData();


	/// <summary>
	/// Splits substrings separated by space sign into vector of string 
	/// </summary>
	/// <param name="arg"> line</param>
	/// <param name="space"> separator</param>
	/// <returns></returns>
	vector<string> Split(string arg, char space);
};

