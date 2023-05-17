#include "UserInterface.h"
#include "CommandReader.h"

int UserInterface::Run()
{
	auto commandReader = new CommandReader();
	do
	{

		if (commandReader->ReadNextLine() < 0)
		{
			cout << "Nieprawidlowa komenda" << endl;
			continue;
		}
		commandReader->ExecuteCommand(false);

	} while (true);

	delete(commandReader);
	return 1;
}