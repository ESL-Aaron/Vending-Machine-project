// item.cpp

#include "item.h"

// Implementation of the constructor
Item::Item(const std::string& name, double price, int code, int quantity)
    : name(name), price(price), code(code), quantity(quantity) {}

// Implementation of getters
std::string Item::getName() const {
    return name;
}

double Item::getPrice() const {
    return price;       
}

int Item::getCode() const {
    return code;
}

int Item::getQuantity() const {
    return quantity;
}

// Implementation of method to decrease quantity
void Item::decreaseQuantity() {
    if (quantity > 0) {
        quantity--;
    }
}