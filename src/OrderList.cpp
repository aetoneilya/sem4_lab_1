#include "restoraunt.hpp"

unsigned int OrderList::addOrder() {
    Order newOrder(orderCount);
    orderList.emplace_back(newOrder);
    return orderCount++;
}

void OrderList::setStateOrder(unsigned int orderNum, State newState) {
    for (std::list<Order>::iterator order = orderList.begin(); order != orderList.end(); order++) {
        if (order->getNum() == orderNum) order->setState(newState);
    }
}

void OrderList::deleteOrder(unsigned int orderNum) {
    for (std::list<Order>::iterator order = orderList.begin(); order != orderList.end(); order++) {
        if (order->getNum() == orderNum) order = orderList.erase(order);
    }
}

Order OrderList::findOrderByState(State findState) {
    Order res(0);
    for (std::list<Order>::iterator order = orderList.begin(); order != orderList.end(); order++) {
        if (order->getState() == findState) {
            res = *order;
            break;
        }
    }
    return res;
}

Order OrderList::findOrderByNum(unsigned int num) {
    Order res(0);
    for (std::list<Order>::iterator order = orderList.begin(); order != orderList.end(); order++) {
        if (order->getNum() == num) {
            res = *order;
            break;
        }
    }
    return res;
}