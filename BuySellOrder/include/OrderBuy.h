#ifndef ORDERBUY_H
#define ORDERBUY_H

#include "OrderBase.h"
#include <vector>

class OrderBuy : public OrderBase
{
public:
    OrderBuy(){}
    virtual ~OrderBuy(){}
    void InsertOrder(const Order& p_Order);
    void AmendOrder(const Order& p_Order);
    void CancelOrder(const Order& p_Order);

    vector<pair<double, long long>> BiggestBuyOrders(int p_TopK = 3);

private:
    map<double/*volume*/, unordered_set<long long>/*Ids*/> m_VolumeIdsMap;
};

#endif
