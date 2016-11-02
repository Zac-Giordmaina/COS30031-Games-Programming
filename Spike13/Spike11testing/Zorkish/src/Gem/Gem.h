#ifndef ZORKISH_GEM_H
#define ZORKISH_GEM_H


#include "../InventoryItem/InventoryItem.h"

class Gem : public InventoryItem {
    public:
        Gem(string name, string description);
        ~Gem();
};


#endif //ZORKISH_GEM_H
