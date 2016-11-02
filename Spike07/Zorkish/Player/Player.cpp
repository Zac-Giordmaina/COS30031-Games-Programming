#include "Player.h"

Player::Player() {
    playerInventory = new Inventory("player inventory");
}

Player::~Player() {

}

Inventory * Player::getInventory() {
    return playerInventory;
}
