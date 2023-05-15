#include "UserInterface.h"
#include "CommandReader.h"

int UserInterface::Run()
{
	auto commandReader = new CommandReader();

	delete(commandReader);
	return 1;
}