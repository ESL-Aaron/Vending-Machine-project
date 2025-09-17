// vendingmachine.cpp

#include "vendingmachine.h"
#include "snack.h"
#include "drink.h"
#include <iostream>
#include <iomanip> // For formatting output
#include <limits> // For input validation


// Constructor: Initializes the vending machine with some default items
VendingMachine::VendingMachine() : currentMoney(0.0) {
    // We dynamically allocate new items and store them as pointers in the map
    items[101] = new Snack("Chocalate Bar", 1.50, 101, 5);
    items[102] = new Snack("Pottato Chips", 1.25, 102, 3);
    items[201] = new Drink("Soda", 2.00, 201, 4);
    items[202] = new Drink("Water Bottle", 1.00, 202, 10);
}

// Destructor: Cleans up dynamically allocated items
VendingMachine::~VendingMachine() {
    for (auto const& [code, item] : items) {
        delete item;        
    }
}

// Displays the menu of available items
void VendingMachine::displayMenu() {
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "        Vending Machine Menu         " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "Item"
              << std::left << std::setw(10) << "Code"
              << std::left << std::setw(10) << "Price ($)"
              << std::left << std::setw(10) << "Stock" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    
    for (auto const& [code, item] : items) {
        std::cout << std::left << std::setw(15) << item->getName()
                  << std::left << std::setw(10) << item->getCode()
                  << std::left << std::setw(10) << std::fixed << std::setprecision(2) << item->getPrice()
                  << std::left << std::setw(10) << item->getQuantity() << std::endl;

    }
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << currentMoney << std::endl;
    std::cout << "---------------------------------------" << std::endl;
}               

// Helper function to find an item by its code
Item* VendingMachine::findItemByCode(int code) {
    auto it = items.find(code);
        if (it != items.end()) {
            return it->second;        
        }
        return nullptr;
}

// Handles the entire selection process, grom input to dispensing
bool VendingMachine::processSelection() {
    int selectionCode;
    std::cout << "Please enter the code of the item you want to buy: ";
    std::cin >> selectionCode;

    // Input validation
    while (std::cin.fail() || findItemByCode(selectionCode) == nullptr) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid code. Please enter a valid item code: ";
        std::cin >> selectionCode;
    }
    Item* selectedItem = findItemByCode(selectionCode);

    // Check if item is in stock
    if (selectedItem->getQuantity() == 0) {
        std::cout << "Sorry, this item is oout of stock. Please choose another item." << std::endl;
        return;
    }
    // Check if user has enough money
    std::cout << "You selected: " << selectedItem->getName() << " for $" << selectedItem->getPrice() << std::endl;
    std::cout << "Your current balance is: $" << currentMoney << std::endl;
    
    if (currentMoney >= selectedItem->getPrice()) {
        dispenseItem(selectedItem);
    } else {
        std::cout << "Insufficient funds. Please add more money." << std::endl;
    }
}

// Adds money to the current balance

void VendingMachine::addMoney(double amount) {
    if (amount > 0) {
        currentMoney += amount;
        std::cout << "You inserted $" << std::fixed << std::setprecision(2) << amount << ". Current balance: $" << currentMoney << std::endl;
    } else {
        std::cout << "Invalid amount. Please insert a positive value." << std::endl;
       
    }
}

// "Dispenses" the item and calculates change
void VendingMachine::dispenseItem(Item* item) {
    if (item == nullptr) {
        std::cout << "Error: Invalid item." << std::endl;
        return;
    }

    double change = currentMoney - item->getPrice();
    currentMoney = 0.0; // Reset balance after purchase
    item->decreaseQuantity(); // Decrease the stock of the item

    std::cout << "Dispensing " << item->getName() << "..." << std::endl;
    std::cout << "Please take your item." << std::endl;

    if (change > 0) {
        std::cout << "Your change is: $" << std::fixed << std::setprecision(2) << change << std::endl;
    } else {
        std::cout << "No change due." << std::endl;
    }
}