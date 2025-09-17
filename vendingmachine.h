// vendingmachine.h

#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <vector>
#include "item.h"
#include <map>

class VendingMachine {
private:
    std::map<int, Item*> items; // Map of item code to Item pointer for
    double currentMoney; // Current money inserted into the machine
    public: 
    // Constructor and Destructor
    VendingMachine();
    ~VendingMachine();

    // Core functionalities
    void displayMenu();
    bool processSelection();
    void addMoney(double amount);
    void dispenseItem(Item* item);

    // Restock feature
    void restockItems();

private:
    // Helper methods
    Item* findItemByCode(int code);

};

#endif // VENDINGMACHINE_H