#pragma once
#include "ICommand.h"
#include "MyUtils.h"

class Canvas;

class CommandCreateLine : public ICommand
{
public:
    CommandCreateLine(){}
    CommandCreateLine(const Util::Command& p_Cmd);
    ~CommandCreateLine();

    void Execute();

private:
};
