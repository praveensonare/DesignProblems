#include "../include/Rock.h"

CRock::CRock()
{
    m_Type = SELECT_OPTION::SELECT_ROCK;
}

CRock::~CRock()
{
}

std::string CRock::TypeString()
{
    return "Rock";
}

RESULT CRock::FindWinner(IPlayObject* p_CompObject)
{
    if (!p_CompObject) return RESULT::RESULT_UNDEFINED;

    RESULT result = RESULT::RESULT_UNDEFINED;
    switch(p_CompObject->m_Type)
    {
        case SELECT_OPTION::SELECT_ROCK:
            result = RESULT::DRAW;
            break;
        case SELECT_OPTION::SELECT_SCISSOR:
            result = RESULT::WIN;
            break;
        case SELECT_OPTION::SELECT_PAPER:
            result = RESULT::LOST;
            break;
        default:
            result = RESULT::RESULT_UNDEFINED;
            break;
    }
    return result;
}
