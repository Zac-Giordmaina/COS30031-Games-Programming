#include "StateManager.h"
#include "../MainMenu/MainMenu.h"
#include "../AdventureMenu/AdventureMenu.h"
#include "../About/About.h"
#include "../FameHall/FameHall.h"
#include "../Help/Help.h"

StateManager::StateManager() {
    AdventureMenu * adventureMenu = new AdventureMenu();
    states[0] = adventureMenu;

    FameHall * fameHall = new FameHall();
    states[1] = fameHall;

    Help * help = new Help();
    states[2] = help;

    About * about = new About();
    states[3] = about;

    MainMenu * mainMenu = new MainMenu();
    states[AMOUNT_OF_STATES - 1] = mainMenu;

    // Defaults to the Main Menu state
    currentState = AMOUNT_OF_STATES - 1;
}

StateManager::~StateManager() {
}

void StateManager::listenForStateChanges() {
    // While the user has not selected to quit
    while (currentState != AMOUNT_OF_STATES - 2) {
        currentState = executeMenuState() - 1;
        if (currentState != AMOUNT_OF_STATES - 2) {
            executeState();
        }
    }
}

void StateManager::executeState() {
    State * tempState = states[currentState];
    tempState->execute();
}

int StateManager::executeMenuState() {
    State * menu = states[AMOUNT_OF_STATES - 1];
    return menu->executeMenu();
}
