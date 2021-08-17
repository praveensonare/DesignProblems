#pragma once

#include <string>

#include "../include/UserDefined.h"

using namespace std;

class IPlayObject
{
public:
    SELECT_OPTION m_Type;

public:
    virtual ~IPlayObject() {}
    
    virtual std::string TypeString() = 0;
    virtual RESULT FindWinner(IPlayObject* p_CompObject) = 0;
};
