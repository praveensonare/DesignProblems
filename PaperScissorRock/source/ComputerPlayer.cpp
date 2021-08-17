#include "../include/ComputerPlayer.h"

#include <stdlib.h> 

#include "../include/Rock.h"
#include "../include/Scissor.h"
#include "../include/Paper.h"

CComputerPlayer::CComputerPlayer()
{
}

CComputerPlayer::~CComputerPlayer()
{
    if (m_Object)
    {
        delete m_Object;
        m_Object = nullptr;
    }
}

void CComputerPlayer::SetSelectedObject(SELECT_OPTION p_Type)
{
    unsigned randomSelection = (rand() % 3) + 1;
    CPlayer::SetSelectedObject(static_cast<SELECT_OPTION>(randomSelection));
}

