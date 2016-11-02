#include "Player.h"

Player::Player() {
}

Player::~Player() {

}

void Player::execute() {
    cout << "\nPlayer Inventory: " << endl;
    playerInventory.printInventory();
}

InventoryItem Player::execute(string key, string value) {
    return playerInventory.itemIsInInventory(value);
}

void Player::execute(string key, string itemKey, InventoryItem item) {
    if (key == "add") {
        playerInventory.add(item);
    } else {
        playerInventory.remove(item, itemKey);
    }
}
