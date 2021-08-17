#ifndef ORDERBASE_H
#define ORDERBASE_H
#include "Order.h"

class OrderBase
{
public:
    OrderBase(){};
    virtual ~OrderBase(){}
    virtual void InsertOrder(const Order& p_Order);
    virtual void AmendOrder(const Order& p_Order);
    virtual void CancelOrder(const Order& p_Order);

    virtual int GetTotalOrders() { return m_Orders.size();}
    void Status();
protected:
    unordered_map<long long, OrderDetail> m_Orders;
};

#endif
