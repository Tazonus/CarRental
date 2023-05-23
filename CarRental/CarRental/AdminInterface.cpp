#include "AdminInterface.h"
#include "CommandReader.h"


int AdminInterface::Run()
{
	system("cls");
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "Witaj w panelu zarzadu \nAby wyswietlic dostepne komendy dla administratora wpisz adminhelp" << endl;
	cout << "---------------------------------------------------------------------------" << endl;

	int result = 0;

	auto commandReader = new CommandReader();
	do
	{

		if (commandReader->ReadNextLine() < 0)
		{
			cout << "Nieprawidlowa komenda" << endl;
			continue;
		}
		result = commandReader->ExecuteCommand(true);

	} while (result >= 0);

	delete(commandReader);

	return 2;
}