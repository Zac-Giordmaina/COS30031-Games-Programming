#ifndef ZORKISH_SWORD_H
#define ZORKISH_SWORD_H


#include "../InventoryItem/InventoryItem.h"

class Sword : public InventoryItem {
    public:
        Sword(string name, string description);
        ~Sword();
};


#endif //ZORKISH_SWORD_H
