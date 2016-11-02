#include "TakeCommand.h"

void TakeCommand::execute(string userInput, Player * player, LocationGraph * locationGraph) {
    InventoryItem tempItem = locationGraph->removeFromLocationInventory(userInput);
    player->addToInventory(tempItem);
}