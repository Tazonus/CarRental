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
	/// Vector of strings that stores command and its arguments
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
	/// <returns>1 add | 2 remove | 3 search | 4 rent | 5 unrent | 0 invalid argument | -1 invalid command </returns>
	int CheckCommand();

	/// <summary>
	/// Adds new Car object to Data map
	/// </summary>
	/// <param name="car"></param>
	void Add(Car car);

	/// <summary>
	/// Adds new Car object created from data scanned from console
	/// </summary>
	void Add();

	void Remove(string id);
	void Rent(string id);
	void Unrent(Car car);

	/// <summary>
	/// Prints values from map
	/// </summary>
	/// <param name="id">"-all" -> prints every value</param>
	void Search(string id);
	string Hash(string line);

	/// <summary>
	/// Splits substrings separated by space sign into vector of string 
	/// </summary>
	/// <param name="arg"> line</param>
	/// <param name="space"> separator</param>
	/// <returns></returns>
	vector<string> Split(string arg, char space);

	/// <summary>
	/// Scans car data
	/// </summary>
	/// <returns>Returns car data in string format, separated by semicolon</returns>
	string InputCarData();
};

