#ifndef ZORKISH_HASCOMMAND_H
#define ZORKISH_HASCOMMAND_H

#include <iostream>
#include "../InventoryItem/InventoryItem.h"
#include "../Player/Player.h"
#include "../LocationGraph/LocationGraph.h"

using namespace std;

class IsCommand {
    public:
        virtual void execute(string userInput, Player * player, LocationGraph * locationGraph);
        virtual void execute(Player * player);
        virtual void execute(string userInput, LocationGraph * locationGraph);
};


#endif //ZORKISH_HASCOMMAND_H
