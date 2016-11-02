#ifndef GRIDWORLDEXTENSION_GAMECONTROLLER_H
#define GRIDWORLDEXTENSION_GAMECONTROLLER_H

#include <iostream>

#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../MovementController/MovementController.h"

using namespace std;

class GameController {
    public:
        GameController();
        bool play();
        bool forceQuit(string &input);
        void quit();
        void checkIfDeathOrGoalReached(string movementResult, MovementController movementController);
        void updateMessage(string movementResult, MovementController movementController);
        void printIntroductionMessage();
        void drawMessage();
        string formatMovements(string validMovements);
        void findValidMovements(Player player, Map map);

    private:
        const string QUIT_GAME = "q";
        bool playGame;
        string message;
};


#endif //GRIDWORLDEXTENSION_GAMECONTROLLER_H
