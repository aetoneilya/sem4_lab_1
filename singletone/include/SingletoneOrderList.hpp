#pragma once
#include <list>
#include <mutex>
#include <iostream>

enum State { NEW, COOKED, DELIVERED };

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
    OrderList() {}

   public:
    OrderList(OrderList const &) = delete;
    OrderList &operator=(OrderList const &) = delete;
    static OrderList &get() {
        static OrderList orderlist_instance;
        return orderlist_instance;
    }

    unsigned int addOrder();
    void setStateOrder(unsigned int orderNum, State newState);
    void deleteOrder(unsigned int orderNum);
    unsigned int findOrderNumByState(State findState);
    State findOrderStateByNum(unsigned int num);
    bool isEmpty() { return orderList.empty(); }
    void showOrderList();
};