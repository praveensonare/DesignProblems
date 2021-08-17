#include "Utility.h"

using namespace Utility;

static map<string, Operation> StringToOperationMap({{"I", INSERT}, {"A", AMEND}, {"C", CANCEL}});
static map<Operation, string> OperationToStringMap({{INSERT, "I"}, {AMEND, "A"}, {CANCEL, "C"}});

static map<Side, string> SideToStringMap({{BUY, "BUY"}, {SELL, "SELL"}});
static map<string, Side> StringToSideMap({{"BUY", BUY}, {"SELL", SELL}});

Operation Utility::GetOperationFromString(const string& p_OpStr)
{
    return StringToOperationMap[p_OpStr];
}

string Utility::GetStringFromOperation(const Operation& p_Op)
{
    return OperationToStringMap[p_Op];
}

Side Utility::GetSideFromString(const string& p_Side)
{
    return StringToSideMap[p_Side];
}

string Utility::GetStringFromSide(const Side& p_Side)
{
    return SideToStringMap[p_Side];
}
