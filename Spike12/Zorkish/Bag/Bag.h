#ifndef ZORKISH_BAG_H
#define ZORKISH_BAG_H


#include <vector>
#include "../InventoryItem/InventoryItem.h"
#include "../Inventory/Inventory.h"

class Bag {
private:
    Inventory bagEntities = Inventory("bag");
    bool bagOpen;
    string unlockItemName;
    string itemKey;
    string itemName = "null";
    string itemDescription;

    void setupBagEntities(vector<string> entities);

public:
    Bag(vector<string> details);
    Bag();
    ~Bag();

    void unlockContainer(string itemName, string unlockName);
    void printContainerContents();
    void addToContainer(InventoryItem item);
    void removeFromContainer(InventoryItem item, string key);
    InventoryItem checkContainerEntities(string itemName);
    string getKey();
    string getName();
    string getDescription();
};


#endif //ZORKISH_BAG_H
