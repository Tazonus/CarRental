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
	/// Car data storage
	/// </summary>
	Data data;

public:
	/// <summary>
	/// Default contstruct, that loads car data from .txt file
	/// </summary>
	CommandReader();

	/// <summary>
	/// Destructor, that saves car data to .txt file
	/// </summary>
	~CommandReader();

	/// <summary>
	/// Method scans a command from console
	/// </summary>
	/// <returns>
	///		<para> -1 -> empty command </para>
	///		<para> 0 -> not empty command </para>
	/// </returns>
	int ReadNextLine();

	/// <summary>
	/// Method executes other methods according to the user's command
	/// </summary>
	/// <param name="isAdmin">=1 -> gives admin privileges</param>
	/// <returns>	
	///		<para> 0 -> command exectued correctly </para>
	///		<para> 1 -> logged into admin panel correctly (need to change interface) </para>
	///		<para> 2 -> logoff from admin panel (need to change interface to userone) </para>
	///		<para> -1 -> exit from program (exit command) </para>
	/// </returns>
	int ExecuteCommand(bool isAdmin);

private:
	/// <summary>
	/// Checks if command is correct and if it's arguments are valid
	/// </summary>
	/// <returns>
	///		<para>	-2 -> invalid argument </para>
	///		<para>	-1 -> invalid command </para>
	///		<para>	0 -> no permission </para>
	///		<para>	1 -> add </para>
	///		<para>	2 -> remove </para>
	///		<para>	3 -> search </para>
	///		<para>	4 -> rent </para>
	///		<para>	5 -> unrent </para>
	///		<para>	6 -> exit </para>
	///		<para>	7 -> adminhelp </para>
	///		<para>	8 -> userhelp </para>
	///		<para>	9 -> login </para>
	///		<para>	10 -> logoff </para>
	/// </returns>
	int CheckCommand(bool isAdmin);


	/// <summary>
	/// Adds new Car object created from data scanned from console
	/// </summary>
	void Add();

	/// <summary>
	///		Gets car id from console and removes it if it exists
	/// </summary>
	void Remove();

	/// <summary>
	///		Rents a car of given id from date to date and saves user mobile number
	/// </summary>
	void Rent();

	/// <summary>
	/// Unrents a car of given id
	/// </summary>
	void Unrent();

	/// <summary>
	/// Prints values from map
	/// </summary>
	void Search();

	/// <summary>
	/// Prints possible commands for the administrator (if the administrator is logged in)
	/// </summary>
	void AdminHelp();

	/// <summary>
	/// Prints possible commands for the user
	/// </summary>
	void UserHelp();

	string Hash(string line);

	/// <summary>
	/// Logs in to admin
	/// </summary>
	/// <returns>true if logged correctly</returns>
	bool Login();

	/// <summary>
	/// Scans car data
	/// </summary>
	/// <returns>Returns car data in string format, separated by semicolon</returns>
	string InputCarData();


	/// <summary>
	/// Splits substrings separated by space sign into vector of string 
	/// </summary>
	/// <param name="arg"> ->line</param>
	/// <param name="space"> ->separator</param>
	/// <returns></returns>
	vector<string> Split(string arg, char space);


	/// <summary>
	/// Converts string value of date to time_t format
	/// </summary>
	/// <param name="str"> -> date string</param>
	/// <param name="is_dst"></param>
	/// <param name="format"> -> format of a date</param>
	/// <returns></returns>
	static std::time_t stringToTime_t(const std::string& str, bool is_dst = false, const std::string& format = "%Y-%b-%d");
};

