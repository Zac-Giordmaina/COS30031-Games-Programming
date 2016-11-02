#include "Inventory.h"

Inventory::Inventory(string invType) {
    inventoryType = invType;
}

void Inventory::add(InventoryItem item) {
    inventory.insert(pair<string, InventoryItem>(item.getKey(), item));
}

void Inventory::remove(InventoryItem item, string itemKey) {
    for (multimap<string, InventoryItem>::iterator it = inventory.begin(); it != inventory.end(); ++it)
    {
        if ((*it).second.getName() == item.getName()) {
            inventory.erase(it);
            break;
        }
    }
}

InventoryItem Inventory::itemIsInInventory(string itemName) {
    if (inventory.size() > 0) {
        for (multimap<string, InventoryItem>::iterator it = inventory.begin(); it != inventory.end(); ++it)
        {
            string tempName = (*it).second.getName();
            transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);\
            if (tempName == itemName) {
                return (*it).second;
            }
        }
    }
    return InventoryItem("fail", "fail");
}

InventoryItem * Inventory::getContainer(string itemName) {
    InventoryItem * tempItem;
    if (inventory.size() > 0) {
        for (multimap<string, InventoryItem>::iterator it = inventory.begin(); it != inventory.end(); ++it)
        {
            string tempName = (*it).second.getName();
            transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
            if (tempName == itemName) {
                tempItem = &(*it).second;
            }
        }
    }
    return tempItem;
}

void Inventory::printInventory() {
    if (inventory.size() > 0) {
        for (multimap<string, InventoryItem>::iterator it = inventory.begin(); it != inventory.end(); ++it)
        {
            cout << (*it).second.getName() + ", (" + (*it).second.getDescription() + ")" << endl;
        }
    } else {
        cout << "\nThe " + inventoryType + " is empty!" << endl;
    }
}

void Inventory::itemCount(string key) {
    int count;

    count = inventory.count(key);

    if (count == 1) {
        cout << "The " + inventoryType + " contains " + to_string(count) + " " + key + ":" << endl;
    } else if (count > 1) {
        cout << "The " + inventoryType + " contains " + to_string(count) + " " + key + "s:" << endl;
    } else {
        cout << "There are no " + key + "s in the " + inventoryType + "!" << endl;
    }

}
