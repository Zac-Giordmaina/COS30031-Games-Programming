#include "Player.h"

Player::Player() {
}

Player::~Player() {

}

void Player::printInventory() {
    cout << "\nPlayer Inventory: " << endl;
    playerInventory.printInventory();
}

InventoryItem Player::checkInventory(string value) {
    return playerInventory.itemIsInInventory(value);
}

InventoryItem Player::removeFromInventory(string itemName) {
    InventoryItem tempItem = checkInventory(itemName);

    if (tempItem.getName() != "fail") {
        playerInventory.remove(tempItem);
        cout << "\nItem removed from the player inventory" << endl;
    } else {
        cout << "\nThis item can not be removed from the player inventory" << endl;
    }

    return tempItem;
}

void Player::addToInventory(InventoryItem item) {
    if (item.getName() != "fail") {
        playerInventory.add(item);
    }
}
