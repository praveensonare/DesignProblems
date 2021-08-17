#pragma once
#include "../include/PlayObject.h"

class CRock : public IPlayObject
{
public:
    CRock();
    ~CRock();
    
    virtual string TypeString();
    virtual RESULT FindWinner(IPlayObject* p_CompObject);

};
