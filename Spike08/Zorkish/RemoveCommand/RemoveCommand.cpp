#include "RemoveCommand.h"

void RemoveCommand::execute(string userInput, Player * player, LocationGraph * locationGraph) {
    InventoryItem tempItem = player->removeFromInventory(userInput);
    locationGraph->addToLocationInventory(tempItem);
}
