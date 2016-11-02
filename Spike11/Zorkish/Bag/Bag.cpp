#include "Bag.h"

Bag::Bag() {

}

Bag::Bag(vector<string> details) {
    itemKey = "bag";
    itemName = details[0];
    itemDescription = details[1];
    bagOpen = details[2] == "open";

    if (!bagOpen) {
        unlockItemName = details[2];
    }

    details.erase(details.begin(), details.begin() + 3);

    setupBagEntities(details);
}

Bag::~Bag() {

}

void Bag::setupBagEntities(vector<string> entities) {
    for (int i = 0; i < entities.size(); i = i + 3) {
        if (entities[i] == "gem") {
            bagEntities.add(Gem(entities[i + 1], entities[i + 2]));
        } else {
            bagEntities.add(Sword(entities[i + 1], entities[i + 2]));
        }
    }
}

void Bag::unlockContainer(string name, string unlockName) {
    string tempName = itemName;
    transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);

    if (tempName == name) {
        if (unlockName == unlockItemName) {
            bagOpen = true;
            cout << "\nThe " + itemName + " has been opened!" << endl;
            printContainerContents();
        } else {
            cout << "\nThis " + itemName + " is opened by another item!" << endl;
        }
    } else {
        cout << "\nThe " + name + " can not be opened!" << endl;
    }
}

void Bag::printContainerContents() {
    if (bagOpen) {
        cout << "\nThe " + itemName + " contains:" << endl;
        bagEntities.printInventory();
    } else {
        cout << "\nThe " + itemName + " is closed!" << endl;
    }
}

void Bag::addToContainer(InventoryItem item) {
    if (bagOpen) {
        bagEntities.add(item);
        cout << "\nItem added to the " + itemName + "!" << endl;
    } else {
        cout << "\nThe " + itemName + " is closed!" << endl;
    }
}

void Bag::removeFromContainer(InventoryItem item, string key) {
    if (bagOpen) {
        bagEntities.remove(item, key);
    } else {
        cout << "\nThe " + itemName + " is closed!" << endl;
    }
}

InventoryItem Bag::checkContainerEntities(string itemName) {
    return bagEntities.itemIsInInventory(itemName);
}

string Bag::getKey() {
    return itemKey;
}

string Bag::getName() {
    return itemName;
}

string Bag::getDescription(){
    return itemDescription;
}

