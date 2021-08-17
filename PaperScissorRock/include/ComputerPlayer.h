#pragma once

#include "../include/Player.h"

class CComputerPlayer : public CPlayer
{
public:
    CComputerPlayer();
    virtual ~CComputerPlayer();

    virtual void SetSelectedObject(SELECT_OPTION p_Type = SELECT_MAX);
};
