#include "../include/Scissor.h"

CScissor::CScissor()
{
    m_Type = SELECT_OPTION::SELECT_SCISSOR;
}

CScissor::~CScissor()
{

}

std::string CScissor::TypeString()
{
    return "Scissor";
}

RESULT CScissor::FindWinner(IPlayObject* p_CompObject)
{
    if (!p_CompObject) return RESULT::RESULT_UNDEFINED;

    RESULT result = RESULT::RESULT_UNDEFINED;
    switch(p_CompObject->m_Type)
    {
        case SELECT_OPTION::SELECT_ROCK:
            result = RESULT::LOST;
            break;
        case SELECT_OPTION::SELECT_SCISSOR:
            result = RESULT::DRAW;
            break;
        case SELECT_OPTION::SELECT_PAPER:
            result = RESULT::WIN;
            break;
        default:
            result = RESULT::RESULT_UNDEFINED;
            break;
    }
    return result;
}
