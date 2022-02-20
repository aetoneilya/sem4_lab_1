#include "restoraunt.hpp"

void Restoraunt::workingClient(OrderList* orderList, std::string name) {
    Client client;
    if (client.getOrder() == 0) {
        client.createOrder(orderList);
        std::cout << "[" + name + "] made a new order" << std::endl;
    }
    while (!client.isOrderReady(orderList)) {
    }
    orderList->deleteOrder(client.getOrder());
    std::cout << "[" + name + "] recieve order and leave" << std::endl;
}

void Restoraunt::workingWaiter(OrderList* orderList, std::string name) {
    Waiter waiter;
    std::cout << "WAITER[" + name + "] start working" << std::endl;
    while (!orderList->isEmpty()) {
        waiter.takeOrder(orderList);
        if (waiter.getOrderNum() != 0) {
            std::cout << "WAITER[" + name + "] takes order" << std::endl;
            waiter.deliverOrder(orderList);
            std::cout << "WAITER[" + name + "] delivired order" << std::endl;
        } else {
            std::cout << "WAITER[" + name + "] have nothing to deliver" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }
}

void Restoraunt::workingCook(OrderList* orderList, std::string name) {
    Cook cook;
    cook.getOrderNum();
    std::cout << "COOK[" + name + "] start working" << std::endl;
    while (!orderList->isEmpty()) {
        cook.takeOrder(orderList);
        if (cook.getOrderNum() != 0) {
            std::cout << "COOK[" + name + "] start cooking" << std::endl;
            cook.cookOrder(orderList);
            std::cout << "COOK[" + name + "] complete cooking" << std::endl;
        } else {
            std::cout << "COOK[" + name + "] have nothing to cook" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }
}

void Restoraunt::startRestoraunt() {
    // std::vector<Client> clients(5);
    // std::vector<std::thread> clients_th(5);
    // for (int i = 0; i < 5; i++) {
    //     clients_th[i] = thread(workingClient);
    // }

    // for (auto& th : clients_th) {
    //     th.join();
    // }

    std::thread t1(workingClient, &orderList, "ava");
    std::thread t2(workingWaiter, &orderList, "biba");
    std::thread t3(workingCook, &orderList, "boba");
    t1.join();
    t2.join();
    t3.join();
}
