// snack.cpp

#include "snack.h"

// Implementation of the Snack constructor
Snack::Snack(const std::string& name, double price, int code, int quantity)
    : Item(name, price, code, quantity) {}