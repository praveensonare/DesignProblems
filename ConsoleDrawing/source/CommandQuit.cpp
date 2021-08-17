#include "ICommand.h"

#include "CommandQuit.h"

CommandQuit::CommandQuit()
{

}

CommandQuit::~CommandQuit()
{

}

void CommandQuit::Execute()
{
    exit(0);
}


