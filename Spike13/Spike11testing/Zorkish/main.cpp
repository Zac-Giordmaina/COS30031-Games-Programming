using namespace std;

#include <iostream>
#include "StateManager/StateManager.h"

#include "GameManager/GameManager.h"

int main() {
    GameManager gameManager = GameManager();
    StateManager stateManager = StateManager();

    while (gameManager.playGame()) {
        stateManager.listenForStateChanges();
        gameManager.quitGame();
    }
}