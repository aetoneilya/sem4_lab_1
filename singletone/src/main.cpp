#include "SingletoneRestorauntEntity.hpp"

int main() {
    Client::get().makeOrders(&OrderList::get(), 5);
    OrderList::get().showOrderList();
    Cook::get().cookOrders(&OrderList::get());
    OrderList::get().showOrderList();
    Waiter::get().deliverOrders(&OrderList::get());
    OrderList::get().showOrderList();
    return 0;
}