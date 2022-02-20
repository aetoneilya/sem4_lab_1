#include "Client.hpp"

void Client::createOrder(OrderList* orderList) {
    orderNum = orderList->addOrder();
}

bool Client::isOrderReady(OrderList* orderList) {
    return orderList->findOrderByNum(orderNum).getState() == DELIVERED;
}