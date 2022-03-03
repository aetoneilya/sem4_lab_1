#include "SingletoneOrderList.hpp"

class Waiter {
    Waiter() {}

   public:
    Waiter(Waiter const &) = delete;
    Waiter &operator=(Waiter const &) = delete;
    static Waiter &get() {
        static Waiter waiter_instance;
        return waiter_instance;
    }
    bool deliverOrders(OrderList *orderList);
};

class Cook {
    Cook() {}

   public:
    Cook(Cook const &) = delete;
    Cook &operator=(Cook const &) = delete;
    static Cook &get() {
        static Cook cook_instance;
        return cook_instance;
    }
    bool cookOrders(OrderList *orderList);
};

class Client {
    Client() {}

   public:
    Client(Client const &) = delete;
    Client &operator=(Client const &) = delete;
    static Client &get() {
        static Client client_instance;
        return client_instance;
    }
    bool makeOrders(OrderList *orderList, int amount);
};