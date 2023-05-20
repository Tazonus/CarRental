#include <iostream>
#include <fstream>
#include "Interface.h"
#include "UserInterface.h"
#include "AdminInterface.h"
#include "FileHandler.h"

using namespace std;


int main()
{
	auto mainInterface = new Interface();


	string passwd;

	cout << "Haslo admina = qwerty" << endl;

	cin >> passwd;

	if (passwd.compare("qwerty") == 0)
	{
		mainInterface = new AdminInterface();
	}
	else
	{
		mainInterface = new UserInterface();
	}

	cout << mainInterface->Run();


	/*
	mainInterface = new AdminInterface();
	mainInterface->Run();
	*/

	return 0;
}