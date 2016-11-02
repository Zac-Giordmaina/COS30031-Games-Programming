#include "InventoryItem.h"

InventoryItem::InventoryItem() {

}

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

InventoryItem InventoryItem::checkContainerEntities(string itemName) {
    return InventoryItem();
}

void InventoryItem::addToContainer(InventoryItem item) {

}

void InventoryItem::removeFromContainer(InventoryItem item, string key) {

}

void InventoryItem::printContainerContents() {
}
