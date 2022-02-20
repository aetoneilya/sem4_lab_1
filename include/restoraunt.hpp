#pragma once
#include <chrono>
#include <thread>
#include <vector>
#include <iostream>

#include "Client.hpp"
#include "Employers.hpp"
#include "orderListInteract.hpp"

class Restoraunt {
    OrderList orderList;
    
    static void workingClient(OrderList* orderList, std::string name);
    static void workingWaiter(OrderList* orderList, std::string name);
    static void workingCook(OrderList* orderList, std::string name);
   public:
    void startRestoraunt();
};