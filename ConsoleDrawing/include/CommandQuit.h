#pragma once
#include "ICommand.h"
#include "MyUtils.h"

class CommandQuit : public ICommand
{
public:
    CommandQuit();
    ~CommandQuit();

    void Execute();
};
