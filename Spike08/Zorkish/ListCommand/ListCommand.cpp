#include "ListCommand.h"

void ListCommand::execute(Player * player) {
    player->printInventory();
}
