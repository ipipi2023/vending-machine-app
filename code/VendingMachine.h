#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H
#include "iostream"
#include "VendingMachine.h"

class VendingMachine {
private:
    // US Currency Constants, todo fill out the rest
    enum US_DOLLAR_DENOMINATION {
        PENNY = 1,
        DIME = 10,
        NICKEL = 5,
        QUARTER = 25,
        DOLLAR = 100,
    };

public:
    /**
     * Shows the available choices to the user with the cost of each item\n
     * 1. Twinkies - $2.50\n
     * 2. Snickers Bar - $1.50\n
     * 3. Pop -Tarts - $1.75\n
     * 4. Granola Bars - $3.25\n
     * 5. Pretzels - $4.10\n
     * 0. Checkout - Show total cost (with Combined Brevard Country Sales Tax, upto two decimal places)\n
     * @param totalCost The totalCost of selected choices. This can be used when using printf to show the user total cost.
     * This value will be in cents
     */
    void showChoices(int totalCost);


    /**
     * Ask user to make a choice and update userChoice variable
     * good idea to make sure the number user input is valid
     * @param userChoice represents userChoice, input will be saved here
     */
    void getCustomerChoice(int& userChoice);


    /**
     * Allow user to enter money
     * Money can only be entered in denominations of $1 and $0.25 (User will enter decimals without $ sign)
     * @param totalCost the current running totalCost in cents
     * @return the money that the user entered in cents
     */
    int takeMoney(int totalCost);

    /**
     * Calculate the change to give back to the user. Change is (moneyReceived - totalCost)\n
     * Example: Dispensing Change: $0.59, Quarters: 2, Dimes: 0, Nickels: 1, Pennies: 4
     * @param totalCost the totalCost represented in cents
     * @param moneyReceived the money user entered in cents
     */
    void computeChange(int totalCost, int moneyReceived);
};


#endif //VENDING_MACHINE_H
