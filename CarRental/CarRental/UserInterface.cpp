#include "UserInterface.h"
#include "CommandReader.h"

int UserInterface::Run()
{
	system("cls");
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "Witaj w panelu uzytkownika \nAby wyswietlic dostepne komendy wpisz userhelp" << endl;
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
		result = commandReader->ExecuteCommand(false);

		if (result == 1)	// zalogowano do admina
		{
			return 1;
		}

		if (result == 2)
		{
			return 2;	// wylogowano
		}

	} while (result >= 0);

	delete(commandReader);
	return 0;
}