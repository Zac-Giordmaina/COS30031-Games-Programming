#include "AdventureMenu.h"
#include "../InventoryMadnessAdventure/InventoryMadnessAdventure.h"

AdventureMenu::AdventureMenu() {
    InventoryMadnessAdventure * inventoryAdventure = new InventoryMadnessAdventure();
    adventureStates[0] = inventoryAdventure;
}

AdventureMenu::~AdventureMenu() {

}

void AdventureMenu::execute() {
    int min = 1;
    int max = 1;
    int adventureStateIndex;

    do {
        printContent();
        cin >> adventureStateIndex;
        printConsoleBuffer();
    } while (!validInput(min, max, adventureStateIndex));

    executeAdventure(adventureStateIndex);
}

void AdventureMenu::printContent() {
    cout << "ZorkishApp :: Select Adventure" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Choose your adventure:" << endl;
    cout << "1. Inventory Madness" << endl;
    cout << "Select 1:> ";
}

void AdventureMenu::executeAdventure(int adventureStateIndex) {
    AdventureState * tempState = adventureStates[adventureStateIndex - 1];
    tempState->execute();
}
