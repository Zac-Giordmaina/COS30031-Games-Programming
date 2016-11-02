#ifndef ZORKISH_PLAYER_H
#define ZORKISH_PLAYER_H


#include "../Inventory/Inventory.h"
#include "../HasCommand/HasCommand.h"

class Player : public HasCommand {
    public:
        Player();
        ~Player();

        void execute();
        InventoryItem execute(string key, string value);
        void execute(string key, string itemKey, InventoryItem item);

    private:
        Inventory playerInventory = Inventory("player inventory");
};


#endif //ZORKISH_PLAYER_H
