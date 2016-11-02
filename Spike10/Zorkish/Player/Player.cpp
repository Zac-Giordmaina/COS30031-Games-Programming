#include "Player.h"

Player::Player() {
    playerEnergy = 100;
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
        if (item.getKey() != "power") {
            playerInventory.add(item);
        }
    } else {
        playerInventory.remove(item, itemKey);
    }
}

void Player::setEnergy(int value) {
    playerEnergy += value;
}

void Player::printEnergy() {
    cout << "You have " + to_string(playerEnergy) + " energy" << endl;
}

void Player::printPowers() {
    for (int i = 0; i < playerPowerElixirs.size(); i++) {
        playerPowerElixirs.at(i).printPower();
    }
}

void Player::executeConsume(Elixir elixir) {
    if (elixir.getType() == "destroy") {
        playerPowerElixirs.push_back(elixir);
        cout << "\nElixir consumed: power gained!" << endl;
    } else {
        setEnergy(elixir.consumePower());
        cout << "\nElixir consumed: energy increased" << endl;
    }
}

bool Player::execute(string value) {
    for (int i = 0; i < playerPowerElixirs.size(); i++) {
        if (playerPowerElixirs.at(i).getType() == value) {
            return true;
        };
    }
    return false;
}
