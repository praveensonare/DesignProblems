#pragma once
#include <string>
#include "ICommand.h"
#include "MyUtils.h"

using namespace std;

class CommandFactory
{
public:
    CommandFactory();
    ICommand* CreateCommandObj(const Util::Command& p_Cmd);
};
