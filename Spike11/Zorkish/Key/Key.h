#ifndef ZORKISH_KEY_H
#define ZORKISH_KEY_H


#include "../InventoryItem/InventoryItem.h"

class Key : public InventoryItem {
public:
    Key(string name, string description);
    ~Key();
};


#endif //ZORKISH_KEY_H
