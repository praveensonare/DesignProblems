#pragma once

#include "PlayObject.h"

class CPaper : public IPlayObject
{
public:
    CPaper();
    ~CPaper();
    
    virtual std::string TypeString() { return "Paper"; }
    virtual RESULT FindWinner(IPlayObject* p_CompObject);

};
