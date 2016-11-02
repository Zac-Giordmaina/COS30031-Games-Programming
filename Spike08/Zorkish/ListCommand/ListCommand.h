#ifndef ZORKISH_LISTCOMMAND_H
#define ZORKISH_LISTCOMMAND_H


#include "../IsCommand/IsCommand.h"

class ListCommand : public IsCommand {
    public:
        void execute(Player * player);
};


#endif //ZORKISH_LISTCOMMAND_H
