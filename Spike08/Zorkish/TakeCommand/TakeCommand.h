#ifndef ZORKISH_TAKECOMMAND_H
#define ZORKISH_TAKECOMMAND_H


#include "../IsCommand/IsCommand.h"

class TakeCommand : public IsCommand {
    public:
     void execute(string userInput, Player * player, LocationGraph * locationGraph);
};


#endif //ZORKISH_TAKECOMMAND_H
