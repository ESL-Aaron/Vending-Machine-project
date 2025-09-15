// item.h

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
    protected:
    std::string name;
    double price;
    int code;
    int quantity;
    public:
    // Constructor
    Item(const std::string& name, double price, int code, int quantity);

    // Getters to access private attributes
    std::string getName() const;
    double getPrice() const;
    int getCode() const;
    int getQuantity() const;

    // Method to decrease quantity as items are sold
    void decreaseQuantity();

};
#endif // ITEM_H