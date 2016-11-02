//
// Created by Zachary Giordmaina on 12/10/2016.
//

#ifndef ZORKISH_REMOVEDIRECTORY_H
#define ZORKISH_REMOVEDIRECTORY_H


#include "../IsCommand/IsCommand.h"

class RemoveCommand : public IsCommand  {
    public:
        void execute(string userInput, Player * player, LocationGraph * locationGraph);
};


#endif //ZORKISH_REMOVEDIRECTORY_H
