#pragma once
#include <chrono>
#include <thread>

#include "orderListInteract.hpp"

class Waiter : public IEmploye, public Entity {
    int deliveryTime = 5;

    void takeOrder(OrderList* orderList);
    void completeOrder(OrderList* orderList);

   public:
    Waiter(std::string workerName) {
        name = workerName;
        job = "Waiter";
    }

    bool proceedOrder(OrderList* orderList);
};

class Cook : public IEmploye, public Entity {
    int cookTime = 5;

    void takeOrder(OrderList* orderList);
    void completeOrder(OrderList* orderList);

   public:
    Cook(std::string workerName) {
        name = workerName;
        job = "Cook";
    }

    bool proceedOrder(OrderList* orderList);
};
