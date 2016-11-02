#ifndef ZORKISH_MOVECOMMAND_H
#define ZORKISH_MOVECOMMAND_H


#include "../IsCommand/IsCommand.h"

class MoveCommand : public IsCommand {
    public:
        void execute(string userInput, LocationGraph * locationGraph);
};


#endif //ZORKISH_MOVECOMMAND_H
