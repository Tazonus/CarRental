#include "AdminInterface.h"
#include "CommandReader.h"

int AdminInterface::Run()
{
	cout << "Witaj w panelu zarzadu" << endl;

	auto commandReader = new CommandReader();
	do
	{

		if (commandReader->ReadNextLine() < 0)
		{
			cout << "Nieprawidlowa komenda" << endl;
			continue;
		}
		commandReader->ExecuteCommand(true);

	} while (true);

	delete(commandReader);

	return 2;
}