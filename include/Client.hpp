#pragma once
#include <chrono>
#include <thread>

#include "orderListInteract.hpp"

class Client: public Entity {

   public:
    void createOrder(OrderList* orderList);
    bool isOrderReady(OrderList* orderList);
};
