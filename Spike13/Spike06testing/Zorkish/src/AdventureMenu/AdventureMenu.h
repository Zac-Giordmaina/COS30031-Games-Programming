#ifndef ZORKISH_ADVENTUREMENU_H
#define ZORKISH_ADVENTUREMENU_H

#include "../State/State.h"
#include "../AdventureState/AdventureState.h"
#include <iostream>

using namespace std;

class AdventureMenu : public State {
    public:
        AdventureMenu();
        ~AdventureMenu();
        void execute();

    protected:
        void printContent();

    private:
        AdventureState * adventureStates[1];
        void executeAdventure(int adventureStateIndex);
};


#endif //ZORKISH_ADVENTUREMENU_H
