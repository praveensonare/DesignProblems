#pragma once
#include "ICommand.h"
#include "MyUtils.h"

class CommandCreateRectangle : public ICommand
{
public:
    CommandCreateRectangle(){}
    CommandCreateRectangle(const Util::Command& p_Cmd);
    ~CommandCreateRectangle();

    void Execute();

private:
};
