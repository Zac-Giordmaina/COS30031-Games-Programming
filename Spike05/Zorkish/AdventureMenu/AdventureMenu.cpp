#include "AdventureMenu.h"
#include "../VoidAdventure/VoidAdventure.h"

AdventureMenu::AdventureMenu() {
    VoidAdventure * voidAdventure = new VoidAdventure();
    adventureStates[0] = voidAdventure;
}

AdventureMenu::~AdventureMenu() {

}

void AdventureMenu::execute() {
    int min = 1;
    int max = 1;
    int adventureStateIndex;

    do {
        printConsoleBuffer();
        printContent();
        cin >> adventureStateIndex;
        printConsoleBuffer();
    } while (!validInput(min, max, adventureStateIndex));

    executeAdventure(adventureStateIndex);
}

void AdventureMenu::printContent() {
    cout << "Zorkish :: Select Adventure" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Choose your adventure:" << endl;
    cout << "1. Void World" << endl;
    cout << "Select 1:> ";
}

void AdventureMenu::executeAdventure(int adventureStateIndex) {
    AdventureState * tempState = adventureStates[adventureStateIndex - 1];
    tempState->execute();
}
