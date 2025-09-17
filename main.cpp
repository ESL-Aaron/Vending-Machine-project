// main.cpp

#include <iostream>
#include <limits>
#include "vendingmachine.h"

void clearScreen() {
    for (int i = 0; i < 50; ++i) {
        std::cout << std::endl;
    }
}

int main() {
    VendingMachine machine;
    int choice;
    double amount;
    char continueShopping; // To control the shopping loop

    do {
        clearScreen();
        machine.displayMenu();

        std::cout << "\nWhat would you like to do?" << std::endl;
        std::cout << "1. Buy an item" << std::endl;
        std::cout << "2. Insert money" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        
        while (!(std::cin >> choice) || (choice < 1 || choice > 3)) {
            std::cout << "Invalid choice. Please enter 1, 2, or 3: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                do {
                    bool purchaseSucess = machine.processSelection(); // Call the updated method
                    if (purchaseSucess) {
                    std::cout << "\nDo you want to buy another item? (y/n): ";
                    std::cin >> continueShopping;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        continueShopping = 'n'; // Exit if purchase was not successful
                    }
                } while (continueShopping == 'y' || continueShopping == 'Y');
                break;
            case 2:
                std::cout << "Enter the amount you want to insert: $";
                while (!(std::cin >> amount) || amount <= 0) {
                    std::cout << "Invalid amount. Please enter a positive number: $";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                machine.addMoney(amount);
                break;
            case 3:
                std::cout << "Thank you for using our Vending Machine. Goodbye!" << std::endl;
                break;
        }

        if (choice != 3) {
            std::cout << "\nPress Enter to continue..." << std::endl;
            std::cin.get();
        }

    } while (choice != 3);

    return 0;
}