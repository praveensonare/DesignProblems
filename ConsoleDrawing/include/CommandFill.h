#pragma once
#include "ICommand.h"
#include "MyUtils.h"

class CommandFill : public ICommand
{
public:
    CommandFill(){}
    CommandFill(const Util::Command& p_Cmd);
    ~CommandFill();

    void Execute();

private:
};
