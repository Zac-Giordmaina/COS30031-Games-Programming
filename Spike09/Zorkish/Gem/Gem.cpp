#include "Gem.h"

Gem::Gem(string name, string description) : InventoryItem(name, description) {
    itemKey = "gem";
    InventoryItem::InventoryItem(name, description);
}

Gem::~Gem() {

}

