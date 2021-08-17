#ifndef ORDER_H
#define ORDER_H

#include "Utility.h"


using namespace std;

struct OrderTimestamp
{
    string hhmmss;
    string ns;

    OrderTimestamp() : hhmmss(""), ns("") {};
    OrderTimestamp(const string& p_Time, const string& p_NanoSecs) : hhmmss(p_Time), ns(p_NanoSecs) {};
    OrderTimestamp(const string& p_Time)
    {
        size_t pos = p_Time.find_first_of('.');
        hhmmss = p_Time.substr(0, pos);
        ns = p_Time.substr(pos + 1);
    };

    string GetTime() { return hhmmss; }
    string GetExactTime() { return hhmmss + "." + ns; }
};

struct OrderDetail
{
    OrderTimestamp timestamp;
    double volume;
    double price;

    OrderDetail() : timestamp(OrderTimestamp()), volume(DEFAULT_VOLUME), price(DEFAULT_PRICE) {};
    OrderDetail(const OrderTimestamp& p_Timestamp, double p_Volume, double p_Price) :
        timestamp(p_Timestamp), volume(p_Volume), price(p_Price) {};
    OrderDetail(const string& p_Timestamp, double p_Volume, double p_Price) :
        timestamp(OrderTimestamp(p_Timestamp)), volume(p_Volume), price(p_Price) {};

    void SetTimestamp(const string& p_Time) { timestamp = OrderTimestamp(p_Time); }
    void SetTimestamp(const OrderTimestamp& p_Time) { timestamp = p_Time; }
    void SetPrice(double p_Price) { price = p_Price; }
    void SetVolume(double p_Volume) { volume = p_Volume; }
};



struct Order
{
    //timestamp;symbol;order-id;operation;side;volume;price
    string timestamp;
    string symbol;
    long long orderId;
    Utility::Operation op;
    Utility::Side side;
    double volume;
    double price;

    Order(){};

    Order(const string& p_Timestamp, const string& p_Symbol, long long p_OrderId, Utility::Operation p_Op, Utility::Side p_Side, double p_Volume, double p_Price)
        : timestamp(p_Timestamp), symbol(p_Symbol), orderId(p_OrderId), op(p_Op), side(p_Side), volume(p_Volume), price(p_Price)
    {

    };

    void Display()
    {
        cout << timestamp << "\t" << symbol << "\t" << orderId << "\t" << Utility::GetStringFromOperation(op) << "\t" << Utility::GetStringFromSide(side) << "\t" << volume << "\t"<< price << endl;
    }
};

#endif
