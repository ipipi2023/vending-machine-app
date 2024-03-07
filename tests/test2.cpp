#include <iostream>
#include "../include/catch.hpp"
#include "../code/VendingMachine.h"
#import "../code/utils.h"
using namespace std;


SCENARIO("Simulate Vending Machine") {
    GIVEN("") {
        WHEN("getCustomerChoice") {
            THEN("") {
                istringstream input("1 2 -1");
                cin.rdbuf(input.rdbuf());
                VendingMachine vendingMachine;
                int userChoice;
                vendingMachine.showChoices(1008);
                vendingMachine.getCustomerChoice(userChoice);
                REQUIRE(userChoice == 1);
                vendingMachine.getCustomerChoice(userChoice);
                REQUIRE(userChoice == 2);
            }
        }
    }
}