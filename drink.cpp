// drink.cpp

#include "drink.h"

// Implementation of the Drink constructor
Drink::Drink(const std::string& name, double price, int code, int quantity)
    : Item(name, price, code, quantity) {}