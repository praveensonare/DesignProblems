#pragma once

#include <vector>

using namespace std;

class IDisplay
{
public:
    virtual void Display(const vector<vector<char>>& p_Canvas) = 0;
};
