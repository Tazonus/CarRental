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
	
	mainInterface = new UserInterface();

	int result = 1;
	do
	{
		result = mainInterface->Run();

		if (result == 1)
		{
			delete(mainInterface);
			mainInterface = new AdminInterface();
		}

	} while (result > 0);


	
	return 0;
}