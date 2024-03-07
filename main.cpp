#include "code/VendingMachine.h"
#include <iostream>
using namespace std;

int main() {
    VendingMachine vendingMachine;
    const int numOfItems = 5;
    const double salesTax = 0.06;
    int totalCost = 0;
    int input;
    // Storing price and quantity-Extra credit
    int inventory[numOfItems][2] = {
            {250,5}, // Item 1: Price 250, Quantity 5
            {150,5}, // Item 2: Price 150, Quantity 5
            {325,5}, // Item 3: Price 325, Quantity 5
            {175,5}, // Item 4: Price 175, Quantity 5
            {410,5}  // Item 5: Price 410, Quantity 5
    };
    int moneyReceived;
    bool check = true;
    char anotherOrder;

    while (check) {
        cout << "Total Cost: " << totalCost << endl;
        vendingMachine.showChoices(totalCost);

        // Get user's choice
        vendingMachine.getCustomerChoice(input);

        // Calculating the total and input validation
        if (input == 0) {
            // Apply sales tax to the total cost just once
            totalCost += static_cast<int>(totalCost * salesTax);

            // Take money from user
            moneyReceived = vendingMachine.takeMoney(totalCost) * 100;
            cout << "Money Received: " << moneyReceived << endl;

            // Compute change
            vendingMachine.computeChange(totalCost, moneyReceived);

            // Ask user for another order
            cout << "Do you want to start another order? Y/N: ";
            cin >> anotherOrder;
            anotherOrder = toupper(anotherOrder); // Make it case insensitive
            if (anotherOrder == 'N') {
                break; // Break the loop
            } else if (anotherOrder == 'Y') {
                totalCost = 0;
            }
        } else if (input >= 1 && input <= numOfItems) {
            if (inventory[input-1][1] > 0) { // Check if item is in stock
                totalCost += inventory[input-1][0]; // Add item price to total cost
                inventory[input-1][1]--; // Decrement item stock
            } else {
                cout << "Item is out of stock, please select another item." << endl;
            }
        } else {
            cout << "Invalid Choice, please try again." << endl;
        }
    }

    return 0;
}
