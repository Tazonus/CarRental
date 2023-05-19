#include <iostream>
#include "Interface.h"
#include "UserInterface.h"
#include "AdminInterface.h"
#include "RentedCar.h"
using namespace std;


int main()
{
	auto mainInterface = new Interface();

	/*string passwd;

	cin >> passwd;

	if (passwd.compare("qwerty"))
	{
		mainInterface = new AdminInterface();
	}
	else
	{
		mainInterface = new UserInterface();
	}

	cout<<mainInterface->Run();
	*/

	mainInterface = new AdminInterface();
	mainInterface->Run();

	return 0;
}