#include "../include/Player.h"
#include <stdlib.h> 

#include "../include/Rock.h"
#include "../include/Scissor.h"
#include "../include/Paper.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
    if (m_Object)
    {
        delete m_Object;
        m_Object = nullptr;
    }
}

void CPlayer::SetSelectedObject(SELECT_OPTION p_Type)
{
    switch(p_Type)
    {
        case SELECT_OPTION::SELECT_ROCK:
            m_Object = new CRock();
            break;

        case SELECT_OPTION::SELECT_SCISSOR:
            m_Object = new CScissor();
            break;

        case SELECT_OPTION::SELECT_PAPER:
            m_Object = new CPaper();
            break;

        default:
            m_Object = nullptr;
    }
}

RESULT CPlayer::PlayMatch(IPlayer* p_Player)
{
    if (!m_Object || !p_Player) return RESULT::RESULT_UNDEFINED;

    return m_Object->FindWinner(p_Player->m_Object);
}

std::string CPlayer::GetSelection()
{
    if (!m_Object) return std::string("INVALID OBJECT");
    return m_Object->TypeString();
}
