#include <iostream>
#include "../include/catch.hpp"
#include "../code/VendingMachine.h"
#import "../code/utils.h"
using namespace std;


SCENARIO("Simulate Vending Machine") {
    GIVEN("") {
        WHEN("showChoices") {
            THEN("") {
                const string fileName = "scenario1.txt";
                freopen (fileName.c_str(),"w",stdout);
                istringstream input("-1");
                cin.rdbuf(input.rdbuf());
                VendingMachine vendingMachine;
                vendingMachine.showChoices(1008);
                fflush( stdout );
                ::fclose(stdout);
                auto output = readFile(fileName);
                REQUIRE(output.contains("$10.08"));
                REQUIRE(output.contains("Checkout"));

            }
        }
    }
}