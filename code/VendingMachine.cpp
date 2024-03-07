#include "VendingMachine.h"
#include "iostream"
using namespace std;

void VendingMachine::showChoices(int totalCost){
    printf("1. Twinkies - $2.50\n"
           "2. Snickers Bar - $1.50\n"
           "3. Pop-Tarts - $1.75\n"
           "4. Granola Bars - $3.75\n"
           "5. Pretzels - $4.10\n"
           "0. Checkout - $%.2f\n", static_cast<float>(totalCost) / 100.0f);

}

void VendingMachine::getCustomerChoice(int &userChoice){
    printf("Make a choice: ");
    cin >> userChoice;

}

int VendingMachine::takeMoney(int totalCost) {
    //convert to totalcost to dollars
    double totalCostInDollars = static_cast<double>(totalCost) / 100.0;
    //cout << totalCostInDollars << endl; debugging purposes
    double totalMoneyEntered = 0;
    double moneyEntered = 0;

    cout << "Money Entered: $0.00" << endl;

    while (totalMoneyEntered < totalCostInDollars) {
        cout << "Enter money in the following denominations (1, 0.25): ";
        cin >> moneyEntered;

        if (moneyEntered != 1 && moneyEntered != 0.25) {
            cout << "Invalid denomination. Please enter either 1 or 0.25." << endl;
            continue; // Skip the rest of the loop and start from the beginning
        }


        totalMoneyEntered += moneyEntered;
        printf("Money Entered: $%.2f \n", totalMoneyEntered);

    }

    return totalMoneyEntered;
}

void VendingMachine::computeChange(int totalCost, int moneyReceived){
    int moneyChange = moneyReceived - totalCost;
    printf("Dispensing Change: $%.2f \n", moneyChange/100.0);


    int quarters = moneyChange / QUARTER;
    moneyChange %= QUARTER;
    int dimes = moneyChange / DIME;
    moneyChange %= DIME;
    int nickels = moneyChange / NICKEL;
    moneyChange %= NICKEL;
    int pennies = moneyChange;


    cout << "Quarters: " << quarters << " ";
    cout << "Dimes: " << dimes << " ";
    cout << "Nickels: " << nickels << " ";
    cout << "Pennies: " << pennies << " ";
}


