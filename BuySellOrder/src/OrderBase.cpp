#include "OrderBase.h"

void OrderBase::InsertOrder(const Order& p_Order)
{
    m_Orders[p_Order.orderId] = OrderDetail(p_Order.timestamp, p_Order.volume, p_Order.price);
    //cout << typeid(this).name() << "::" << __FUNCTION__ << "\t" << __LINE__ << endl;
}

void OrderBase::AmendOrder(const Order& p_Order)
{
    //cout << typeid(this).name() << "::" << __FUNCTION__ << "\t" << __LINE__ << endl;
    if (m_Orders.find(p_Order.orderId) == m_Orders.end())
    {
        InsertOrder(p_Order);
    }
    else
    {
        m_Orders[p_Order.orderId].SetTimestamp(p_Order.timestamp);
        m_Orders[p_Order.orderId].SetVolume(p_Order.volume);
        m_Orders[p_Order.orderId].SetPrice(p_Order.price);
    }
}

void OrderBase::CancelOrder(const Order& p_Order)
{
    m_Orders.erase(p_Order.orderId);
}

void OrderBase::Status()
{
    for (auto order : m_Orders) cout << order.first << "  ";
    cout << endl;
}
