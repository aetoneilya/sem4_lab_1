#pragma once
#include <chrono>
#include <thread>

#include "orderListInteract.hpp"

class Waiter : public IEmploye {

    int deliveryTime = 5;

    void completeOrder(OrderList* orderList);
   public:
    void deliverOrder(OrderList* orderList);
    void takeOrder(OrderList* orderList);
};

class Cook : public IEmploye {
    int cookTime = 5;

    void completeOrder(OrderList* orderList);
   public:
    void cookOrder(OrderList* orderList);
    void takeOrder(OrderList* orderList);
};
