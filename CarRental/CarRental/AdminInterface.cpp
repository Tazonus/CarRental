#include "AdminInterface.h"
#include "CommandReader.h"

int AdminInterface::Run()
{
	auto commandReader = new CommandReader();
	do
	{
		
		if (commandReader->ReadNextLine() < 0)
		{
			continue;
		}
		commandReader->ExecuteCommand(1);

	} while (true);

	delete(commandReader);

	return 2;
}