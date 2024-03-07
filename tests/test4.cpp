#include <iostream>
#include "../include/catch.hpp"
#include "../code/VendingMachine.h"
#import "../code/utils.h"
using namespace std;


SCENARIO("Simulate Vending Machine") {
    GIVEN("") {
        WHEN("computeChange") {
            THEN("") {
                const string fileName = "scenario4.txt";
                freopen (fileName.c_str(),"w",stdout);
                VendingMachine vendingMachine;
                vendingMachine.computeChange(1008, 1025);
                fflush( stdout );
                ::fclose(stdout);
                auto output = readFile(fileName);
                REQUIRE(output.contains("Dimes: 1"));
                REQUIRE(output.contains("Nickels: 1"));
                REQUIRE(output.contains("Pennies: 2"));
            }
        }
    }
}