#ifndef ZORKISH_PLAYER_H
#define ZORKISH_PLAYER_H


#include <vector>
#include "../Inventory/Inventory.h"
#include "../HasCommand/HasCommand.h"
#include "../Elixir/Elixir.h"
#include "../HasMessaging/HasMessaging.h"
#include "../Messaging/Messaging.h"

class Player : public HasCommand, public HasMessaging {
    public:
        Player();
        ~Player();

        void execute();
        InventoryItem execute(string key, string value);
        void execute(string key, string itemKey, InventoryItem item);
        bool execute(string value);
        void executeConsume(Elixir elixir);

        void setEnergy(int value);
        int getEnergy();
        void printEnergy();
        void printPowers();

        void addMessenger(Messaging &messenger);
        void reducePlayerEnergy(int value);
        void moveAnnouncement(int value);

private:
        Inventory playerInventory = Inventory("player inventory");
        vector<Elixir> playerPowerElixirs;
        int playerEnergy;
        Messaging * playerMessenger;
};


#endif //ZORKISH_PLAYER_H
