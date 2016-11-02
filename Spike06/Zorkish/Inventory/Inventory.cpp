#include "Inventory.h"

Inventory::Inventory(string invType) {
    inventoryType = invType;
}

void Inventory::add(InventoryItem *item) {
    inventory.insert(pair<string, InventoryItem>(item->getKey(), *item));
}

void Inventory::remove(InventoryItem *item, string itemKey) {
    if (inventory.size() > 0) {
        auto range = inventory.equal_range(itemKey);

        for (multimap<string, InventoryItem>::iterator it = range.first; it != range.second; ++it)
        {
            if ((*it).second.getName() == item->getName()) {
                inventory.erase(it);
                break;
            }
        }
    } else {
        cout << "\nThe " + inventoryType + " is empty!" << endl;
    }
}

bool Inventory::itemIsInInventory(InventoryItem *item, string itemKey) {
    if (inventory.size() > 0) {
        auto range = inventory.equal_range(itemKey);

        for (multimap<string, InventoryItem>::iterator it = range.first; it != range.second; ++it)
        {
            if ((*it).second.getName() == item->getName()) {
                return true;
            }
        }
    }

    return false;
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
