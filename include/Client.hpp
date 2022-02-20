#pragma once
#include <chrono>
#include <thread>

#include "orderListInteract.hpp"

class Client : IClient {
    unsigned int orderNum = 0;

   public:
    void createOrder(OrderList* orderList);
    unsigned int getOrder() { return orderNum; }
    bool isOrderReady(OrderList* orderList);
};
