#include "InventoryItem.h"

InventoryItem::InventoryItem(string name, string description) {
    itemName = name;
    itemDescription = description;
}

InventoryItem::~InventoryItem() {

}

string InventoryItem::getKey() {
    return itemKey;
}

string InventoryItem::getName() {
    return itemName;
}

string InventoryItem::getDescription(){
    return itemDescription;
}
