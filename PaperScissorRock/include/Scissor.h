#pragma once
#include "../include/PlayObject.h"

class CScissor : public IPlayObject
{
public:
    CScissor();
    ~CScissor();
    
    virtual string TypeString();
    virtual RESULT FindWinner(IPlayObject* p_CompObject);

};
