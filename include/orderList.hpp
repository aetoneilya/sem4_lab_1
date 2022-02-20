#pragma once
#include <list>
#include <mutex>

enum State { NEW, COOKING, COOKED, DELIVERING, DELIVERED };

class Order {
    unsigned int orderNum;
    State orderState;

   public:
    Order(int num) {
        orderState = NEW;
        orderNum = num;
    }

    unsigned int getNum() { return orderNum; }
    void setState(State newState) { orderState = newState; }
    State getState() { return orderState; }
};

class OrderList {
    unsigned int orderCount = 1;
    std::list<Order> orderList;

   public:
    std::mutex mutex;
    OrderList() {}
    unsigned int addOrder();
    void setStateOrder(unsigned int orderNum, State newState);
    void deleteOrder(unsigned int orderNum);
    Order findOrderByState(State findState);
    Order findOrderByNum(unsigned int num);
    bool isEmpty() { return orderList.empty(); }
};