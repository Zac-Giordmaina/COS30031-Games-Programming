#ifndef ZORKISH_STATEMANAGER_H
#define ZORKISH_STATEMANAGER_H

#include "../State/State.h"

class StateManager {
    public:
        StateManager();
        ~StateManager();
        void listenForStateChanges();
        void executeState();

private:
        static const int AMOUNT_OF_STATES = 6;
        State * states[AMOUNT_OF_STATES];
        int currentState;
        int executeMenuState();
};


#endif //ZORKISH_STATEMANAGER_H
