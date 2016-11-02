#include <iostream>
#include <sys/timeb.h>
#include <thread>

#include "Validator/Validator.h"
#include "GameController/GameController.h"

using namespace std;

const int MS_PER_UPDATE = 16;

// Source: http://www.firstobject.com/getmillicount-milliseconds-portable-c++.htm

int getMilliCount(){
    timeb tb;
    ftime(&tb);
    int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return nCount;
}

int getMilliSpan(int nTimeStart){
    int nSpan = getMilliCount() - nTimeStart;
    if(nSpan < 0)
        nSpan += 0x100000 * 1000;
    return nSpan;
}

// End Source

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

void input(string * userInput) {
    Validator validator;
    bool getInput = true;

    while (getInput) {
        validator.input(userInput);
        if (*userInput == "q") {
            getInput = false;
        }
    }
}

int main () {
    Player player;
    Map map;
    MovementController movementController;
    GameController gameController;

    gameController.printIntroductionMessage();

    map.initialisePlayerPosition(player);
    map.drawMap();

    int previous = getMilliCount();
    int lag = 0;

    string userInput = "";
    string * ui = &userInput;

    thread inputThread = thread(input, ui);

    while (gameController.play()) {
        int current = getMilliSpan(previous);
        int elapsed = current - previous;
        previous = current;
        lag += elapsed;

        if (!gameController.forceQuit(userInput)) {

            if (userInput != "") {
                do {
                    if (userInput != "") {
                        update(userInput, player, map, movementController, gameController);
                    }
                    lag -= MS_PER_UPDATE;
                    userInput = "";
                } while (lag >= MS_PER_UPDATE);
                render(map, gameController);
            }
        } else {
             gameController.quit();
        }

    }
    inputThread.join();
    return 0;
}