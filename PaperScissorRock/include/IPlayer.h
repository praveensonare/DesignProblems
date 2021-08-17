#pragma once

#include "../include/UserDefined.h"
#include "../include/PlayObject.h"

class IPlayer
{
public:
    IPlayObject* m_Object;

public:
    virtual ~IPlayer() {}

    virtual void SetSelectedObject(SELECT_OPTION p_Type = SELECT_OPTION::SELECT_MAX) = 0;
    virtual RESULT PlayMatch(IPlayer* p_Computer) = 0;
    virtual std::string GetSelection() = 0;
};
