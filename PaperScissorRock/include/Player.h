#pragma once

#include "../include/IPlayer.h"

class CPlayer : public IPlayer
{

public:
    CPlayer();
    virtual ~CPlayer();

    virtual void SetSelectedObject(SELECT_OPTION p_Type = SELECT_OPTION::SELECT_MAX);
    virtual RESULT PlayMatch(IPlayer* p_Computer);
    virtual std::string GetSelection();
};
