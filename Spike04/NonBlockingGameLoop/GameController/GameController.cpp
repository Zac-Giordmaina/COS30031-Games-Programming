#include "GameController.h"

GameController::GameController () {
    playGame = true;
}

bool GameController::play () {
    return playGame;
}

bool GameController::forceQuit (string &input) {
    return (input == QUIT_GAME);
}

void GameController::quit () {
    playGame = false;
}

string GameController::formatMovements (string validMovements) {
    string formattedMovements;
    for (int i = 0; i < validMovements.length() - 1; i++) {
        formattedMovements += string(1, validMovements[i]) + ", ";
    }
    formattedMovements += validMovements[validMovements.length() - 1];
    return formattedMovements;
}

void GameController::findValidMovements (Player player, Map map) {
    string validMovements;
    string north = map.getMapCell(player.getCurrentYPosition() - 1, player.getCurrentXPosition());
    string east = map.getMapCell(player.getCurrentYPosition(), player.getCurrentXPosition() + 1);
    string south = map.getMapCell(player.getCurrentYPosition() + 1, player.getCurrentXPosition());
    string west = map.getMapCell(player.getCurrentYPosition(), player.getCurrentXPosition() - 1);

    if (north == map.BLANK_MARKER || north == map.GOAL_MARKER || north == map.DEATH_MARKER) {
        validMovements += "N";
    }
    if (east == map.BLANK_MARKER || east == map.GOAL_MARKER || east == map.DEATH_MARKER) {
        validMovements += "E";
    }
    if (south == map.BLANK_MARKER || south == map.GOAL_MARKER || south == map.DEATH_MARKER) {
        validMovements += "S";
    }
    if (west == map.BLANK_MARKER || west == map.GOAL_MARKER || west == map.DEATH_MARKER) {
        validMovements += "W";
    }

    validMovements = validMovements.length() > 1 ? formatMovements(validMovements) : validMovements;

    cout << "You can move " + validMovements + ": ";
}

void GameController::checkIfDeathOrGoalReached (string movementResult, MovementController movementController) {
    if (movementResult == movementController.DEATH || movementResult == movementController.GOAL) {
        quit();
    }
};

void GameController::updateMessage (string movementResult, MovementController movementController) {
    if ( movementResult == movementController.DEATH ) {
        message = "YOU DEAD, do not touch the D.";
    } else if ( movementResult == movementController.WALL ) {
        message = "There is a wall blocking your path.";
    } else if ( movementResult == movementController.GOAL ) {
        message = "Hooray, you have the discovered the gold.";
    } else if ( movementResult == movementController.OFFMAP ) {
        message = "You can not escape the bounds of the map!";
    } else {
        message = "You have moved " + movementResult;
    }
}

void GameController::printIntroductionMessage () {
    cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!" << endl;
    cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl << endl;
}

void GameController::drawMessage () {
    cout << message << endl << endl;
}