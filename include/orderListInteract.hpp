#pragma once
#include "orderList.hpp"

class IEmploye {
   protected:
    unsigned int orderNum = 0;

   public:
    virtual void takeOrder(OrderList* orderList) = 0;
    virtual void completeOrder(OrderList* orderList) = 0;
    unsigned int getOrderNum() { return orderNum; }
};

class IClient {
   public:
    virtual void createOrder(OrderList* OrderList) = 0;
};
