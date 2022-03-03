#include "restoraunt.hpp"

// TODO(machrist): add shoutaout func

void Restoraunt::workingClient(OrderList* orderList, std::string name) {
    Client client;
    if (client.getOrderNum() == 0) {
        client.createOrder(orderList);
        std::cout << "[" + name + "] made a new order" << std::endl;
    }
    while (!client.isOrderReady(orderList)) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    orderList->deleteOrder(client.getOrderNum());
    std::cout << "[" + name + "] recieve order and leave" << std::endl;
}

void Restoraunt::workingWaiter(OrderList* orderList, std::string name) {
    Waiter waiter(name);
    std::cout << "WAITER[" + name + "] start working" << std::endl;
    while (!orderList->isEmpty()) {
        if (waiter.proceedOrder(orderList)) std::cout << "WAITER[" + name + "] delivired order" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Restoraunt::workingCook(OrderList* orderList, std::string name) {
    Cook cook(name);

    std::cout << "COOK[" + name + "] start working" << std::endl;
    while (!orderList->isEmpty()) {
        if (cook.proceedOrder(orderList)) std::cout << "COOK[" + name + "] complete cooking" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Restoraunt::startRestoraunt() {

    std::thread c1(workingClient, &orderList, "client1");
    std::thread c2(workingClient, &orderList, "client2");
    std::thread c3(workingClient, &orderList, "client3");
    // std::thread c4(workingClient, &orderList, "client4");
    std::thread w1(workingWaiter, &orderList, "waiter1");
    std::thread w2(workingWaiter, &orderList, "waiter2");
    std::thread p1(workingCook, &orderList, "cook1");
    std::thread p2(workingCook, &orderList, "cook2");
    c1.join();
    c2.join();
    c3.join();
    // c4.join();
    w1.join();
    w2.join();
    p1.join();
    p2.join();
}
