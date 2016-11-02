#ifndef ZORKISH_PLAYER_H
#define ZORKISH_PLAYER_H


#include "../Inventory/Inventory.h"

class Player {
    public:
        Player();
        ~Player();

        void printInventory();
        InventoryItem removeFromInventory(string item);
        void addToInventory(InventoryItem item);
        InventoryItem checkInventory(string value);

    private:
        Inventory playerInventory = Inventory("player inventory");
};


#endif //ZORKISH_PLAYER_H
