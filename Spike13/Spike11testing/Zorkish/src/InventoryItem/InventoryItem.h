#ifndef ZORKISH_INVENTORYITEM_H
#define ZORKISH_INVENTORYITEM_H

#include <iostream>

using namespace std;

class InventoryItem {
    public:
        InventoryItem();
        InventoryItem(string name, string description);
        ~InventoryItem();

        string getKey();
        string getName();
        string getDescription();

    protected:
        string itemKey;
        string itemName;
        string itemDescription;
};


#endif //ZORKISH_INVENTORYITEM_H
