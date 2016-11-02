#include "Key.h"

Key::Key(string name, string description) : InventoryItem(name, description) {
    itemKey = "key";
    InventoryItem::InventoryItem(name, description);
}

Key::~Key() {

}