#include "Client.hpp"

void Client::createOrder(OrderList* orderList) {
    orderList->mutex.lock();
    orderNum = orderList->addOrder();
    orderList->mutex.unlock();
}

bool Client::isOrderReady(OrderList* orderList) {
    return orderList->findOrderStateByNum(orderNum) == DELIVERED;
}