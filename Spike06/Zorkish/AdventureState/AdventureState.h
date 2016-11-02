#ifndef ZORKISH_ADVENTURESTATE_H
#define ZORKISH_ADVENTURESTATE_H

#include <iostream>
#include "../FameHall/FameHall.h"

using namespace std;


class AdventureState {
    public:
        AdventureState();
        ~AdventureState();
        virtual void execute();

    protected:
        string adventureName;
        int adventureScore, adventureMoves;

        virtual void initialiseAdventure();
        void displayHiscore(string adventureName, int adventureScore, int adventureMoves);
        void printLine();
        void printBuffer();

};


#endif //ZORKISH_ADVENTURESTATE_H
