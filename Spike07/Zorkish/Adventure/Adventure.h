#ifndef ZORKISH_INVENTORYMADNESSADVENTURE_H
#define ZORKISH_INVENTORYMADNESSADVENTURE_H

#include <vector>
#include <sstream>

#include "../AdventureState/AdventureState.h"

class Adventure : public AdventureState {
    public:
        Adventure(string adventureDetails, vector<string> adventureLocations);
        ~Adventure();
        void execute();

    protected:
        void initialiseAdventure();
        void listenForInput();
        void printCommands();

};


#endif //ZORKISH_INVENTORYMADNESSADVENTURE_H
