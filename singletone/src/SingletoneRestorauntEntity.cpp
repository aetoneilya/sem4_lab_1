#include "SingletoneRestorauntEntity.hpp"

bool Waiter::deliverOrders(OrderList *orderList) {
    int orderNum = orderList->findOrderNumByState(COOKED);

    while (orderNum != 0) {
        orderList->setStateOrder(orderNum, DELIVERED);
        orderNum = orderList->findOrderNumByState(COOKED);
    }

    return true;
}

bool Cook::cookOrders(OrderList *orderList) {
    int orderNum = orderList->findOrderNumByState(NEW);

    while (orderNum != 0) {
        orderList->setStateOrder(orderNum, COOKED);
        orderNum = orderList->findOrderNumByState(NEW);
    }

    return true;
}

bool Client::makeOrders(OrderList *orderList, int amount) {
    for (int i = 0; i < amount; i++) {
        orderList->addOrder();
    }

    return true;
}