#include "Employers.hpp"

bool Waiter::proceedOrder(OrderList* orderList) {
    bool res = false;
    takeOrder(orderList);

    if (orderNum != 0) {
        res = true;
        std::this_thread::sleep_for(std::chrono::seconds(deliveryTime));
        completeOrder(orderList);
    }
    return res;
}

void Waiter::takeOrder(OrderList* orderList) {
    orderList->mutex.lock();

    orderNum = orderList->findOrderNumByState(COOKED);
    if (orderNum != 0) orderList->setStateOrder(orderNum, DELIVERING); 

    orderList->mutex.unlock();
}

void Waiter::completeOrder(OrderList* orderList) {
    orderList->setStateOrder(orderNum, DELIVERED);
    orderNum = 0;
}

bool Cook::proceedOrder(OrderList* orderList) {
    bool res = false;
    takeOrder(orderList); 

    if (orderNum != 0) {
        res = true;
        std::this_thread::sleep_for(std::chrono::seconds(cookTime));
        completeOrder(orderList);
    }
    return res;
}

void Cook::takeOrder(OrderList* orderList) {
    orderList->mutex.lock();

    orderNum = orderList->findOrderNumByState(NEW);
    if (orderNum != 0) orderList->setStateOrder(orderNum, COOKING);

    orderList->mutex.unlock();
}

void Cook::completeOrder(OrderList* orderList) {
    orderList->setStateOrder(orderNum, COOKED);
    orderNum = 0;
}
