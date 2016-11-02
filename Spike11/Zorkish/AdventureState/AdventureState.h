#ifndef ZORKISH_ADVENTURESTATE_H
#define ZORKISH_ADVENTURESTATE_H

#include <iostream>
#include "../FameHall/FameHall.h"
#include "../Player/Player.h"
#include "../LocationGraph/LocationGraph.h"
#include "../CommandManager/CommandManager.h"
#include "../Messaging/Messaging.h"

using namespace std;


class AdventureState {
    public:
        AdventureState(string adventureDetails, vector<string> adventureLocations);
        ~AdventureState();
        virtual void execute();

    protected:
        string adventureName;
        string adventureDescription;
        int adventureScore, adventureMoves;

        Player player;
        CommandManager commandManager;
        Messaging messaging;
        string details;

        vector<string> locations;
        LocationGraph locationGraph;


        virtual void initialiseAdventure();
        void setupAdventureDetails();
        void setupLocations();
        void printContent();
        void printAdventureLocationDetails();
        void displayHiscore(string adventureName, int adventureScore, int adventureMoves);
        void printLine();
        void printBuffer();

};


#endif //ZORKISH_ADVENTURESTATE_H
