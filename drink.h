// drink.h

#ifndef DRINK_H
#define DRINK_H

#include "item.h"

class Drink : public Item {
public:
    // Constructor
    Drink(const std::string& name, double price, int code, int quantity);
};

#endif // DRINK_H