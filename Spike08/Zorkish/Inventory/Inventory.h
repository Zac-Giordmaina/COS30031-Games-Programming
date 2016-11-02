#ifndef ZORKISH_INVENTORY_H
#define ZORKISH_INVENTORY_H


#include <map>
#include "../Gem/Gem.h"
#include "../Sword/Sword.h"

class Inventory {
    public:
        Inventory(string invType);

        void add(InventoryItem item);
        void remove(InventoryItem item);
        InventoryItem itemIsInInventory(string itemName);

        void printInventory();
        void itemCount(string key);

    private:
        multimap<string, InventoryItem> inventory;
        string inventoryType;
};


#endif //ZORKISH_INVENTORY_H
