#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <algorithm>

#define DEFAULT_VOLUME 0.0
#define DEFAULT_PRICE 0.0

using namespace std;

namespace Utility {

    enum Operation {
        INSERT = 0,
        AMEND,
        CANCEL,
        UNKNOWN
    };

    enum Side {
        BUY = 0,
        SELL,
        ALL
    };

    Operation GetOperationFromString(const string& p_OpStr);
    string GetStringFromOperation(const Operation& p_Op);
    Side GetSideFromString(const string& p_Side);
    string GetStringFromSide(const Side& p_Side);
}

#endif
