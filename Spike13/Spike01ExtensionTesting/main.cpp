#include <iostream>

#include "Validator/Validator.h"
#include "GameController/GameController.h"

using namespace std;

void render (Map map, GameController gameController) {
    map.drawMap();
    gameController.drawMessage();
}

void update (string input, Player &player, Map &map, MovementController movementController, GameController &gameController) {
    string movementResult = movementController.performMovement(input, player, map);

    if (movementController.validMovement(movementResult)) {
        map.updatePlayerPosition(input, player);
        map.updateMap(player);
    }

    gameController.updateMessage(movementResult, movementController);

    gameController.checkIfDeathOrGoalReached(movementResult, movementController);
}

int main () {
    Validator validator;
    Player player;
    Map map;
    MovementController movementController;
    GameController gameController;

    string userInput;
    string validMoves;

    gameController.printIntroductionMessage();
    map.initialisePlayerPosition(player);
    map.drawMap();

    while (gameController.play()) {
        validMoves = gameController.findValidMovements(player, map);

        validator.input(userInput, validMoves);

        if (!gameController.forceQuit(userInput)) {
            update(userInput, player, map, movementController, gameController);
            render(map, gameController);
        } else {
             gameController.quit();
        }
    }

    return 0;
}