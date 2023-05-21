#include "AdminInterface.h"
#include "CommandReader.h"

int AdminInterface::Run()
{
	cout << "Witaj w panelu zarzadu" << endl;

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