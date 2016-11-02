#include "Sword.h"

Sword::Sword(string name, string description) : InventoryItem(name, description) {
    itemKey = "gem";
    InventoryItem::InventoryItem(name, description);
}

Sword::~Sword() {

}
