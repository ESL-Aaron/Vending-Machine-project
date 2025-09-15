// snack.h

#ifndef SNACK_H
#define SNACK_H

#include "item.h"

class Snack : public Item {
public:
// Constructor
    Snack(const std::string& name, double price, int code, int quantity);     
};

#endif // SNACK_H