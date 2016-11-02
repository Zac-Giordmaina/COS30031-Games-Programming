#ifndef ZORKISH_ADVENTUREMENU_H
#define ZORKISH_ADVENTUREMENU_H

#include "../State/State.h"
#include "../AdventureState/AdventureState.h"
#include "../Adventure/Adventure.h"
#include <iostream>
#include <fstream>

using namespace std;

class AdventureMenu : public State {
    public:
        AdventureMenu();
        ~AdventureMenu();
        void execute();

    protected:
        void printContent(int max);

    private:
        vector<AdventureState *> adventureStates;
        vector<string> adventureNames;
        void loadAdventures();
        void executeAdventure(int adventureStateIndex);
        void printAdventureNames();
};


#endif //ZORKISH_ADVENTUREMENU_H
