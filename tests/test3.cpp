#include <iostream>
#include "../include/catch.hpp"
#include "../code/VendingMachine.h"
#import "../code/utils.h"
using namespace std;


SCENARIO("Simulate Vending Machine") {
    GIVEN("") {
        WHEN("takeMoney") {
            THEN("") {
                istringstream input("1 1 1 .5 1 1 1 1 1 1 1 .25");
                cin.rdbuf(input.rdbuf());
                VendingMachine vendingMachine;
                int moneyReceived = vendingMachine.takeMoney(1008);
                REQUIRE(moneyReceived == 1025);
            }
        }
    }
}