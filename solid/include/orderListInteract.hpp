#pragma once
#include "orderList.hpp"

class Entity {
   protected:
    unsigned int orderNum = 0;
    std::string name;
    std::string job;

   public:
    Entity() {
        name = "noname";
    }
    
    std::string getName() { return name; };
    std::string getJob() { return job; };
    unsigned int getOrderNum() { return orderNum; }
};

class IEmploye {
    virtual void completeOrder(OrderList* orderList) = 0;
    virtual void takeOrder(OrderList* orderList) = 0;

   public:
    virtual bool proceedOrder(OrderList* orderList) = 0;
};