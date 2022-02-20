#include "Employers.hpp"

void Waiter::deliverOrder(OrderList* orderList) {
    if (orderNum != 0) {
        std::this_thread::sleep_for(std::chrono::seconds(deliveryTime));
        completeOrder(orderList);
    }
}

void Waiter::takeOrder(OrderList* orderList) {
    orderList->mutex.lock();

    orderNum = orderList->findOrderByState(COOKED).getNum();
    if (orderNum != 0) orderList->setStateOrder(orderNum, DELIVERING);

    orderList->mutex.unlock();
}

void Waiter::completeOrder(OrderList* orderList) {
    orderList->setStateOrder(orderNum, DELIVERED);
    orderNum = 0;
}

void Cook::cookOrder(OrderList* orderList) {
    if (orderNum != 0) {
        std::this_thread::sleep_for(std::chrono::seconds(cookTime));
        completeOrder(orderList);
    }
}

void Cook::takeOrder(OrderList* orderList) {
    orderList->mutex.lock();

    orderNum = orderList->findOrderByState(NEW).getNum();
    if (orderNum != 0) orderList->setStateOrder(orderNum, COOKING);

    orderList->mutex.unlock();
}

void Cook::completeOrder(OrderList* orderList) {
    orderList->setStateOrder(orderNum, COOKED);
    orderNum = 0;
}
