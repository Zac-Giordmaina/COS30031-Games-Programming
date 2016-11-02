#ifndef ZORKISH_INVENTORY_H
#define ZORKISH_INVENTORY_H


#include <map>
#include "../Gem/Gem.h"
#include "../Sword/Sword.h"
#include "../Key/Key.h"

class Inventory {
    public:
        Inventory(string invType);

        void add(InventoryItem item);
        void remove(InventoryItem item, string itemKey);
        InventoryItem itemIsInInventory(string itemName);
        InventoryItem * getContainer(string itemName);

        void printInventory();
        void itemCount(string key);

    private:
        multimap<string, InventoryItem> inventory;
        string inventoryType;
};


#endif //ZORKISH_INVENTORY_H
