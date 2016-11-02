#ifndef ZORKISH_PLAYER_H
#define ZORKISH_PLAYER_H


#include <vector>
#include "../Inventory/Inventory.h"
#include "../HasCommand/HasCommand.h"
#include "../Elixir/Elixir.h"

class Player : public HasCommand {
    public:
        Player();
        ~Player();

        void execute();
        InventoryItem execute(string key, string value);
        void execute(string key, string itemKey, InventoryItem item);
        bool execute(string value);
        void executeConsume(Elixir elixir);

        void setEnergy(int value);
        void printEnergy();
        void printPowers();

    private:
        Inventory playerInventory = Inventory("player inventory");
        vector<Elixir> playerPowerElixirs;
        int playerEnergy;
};


#endif //ZORKISH_PLAYER_H
