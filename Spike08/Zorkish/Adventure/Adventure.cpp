#include "Adventure.h"

Adventure::Adventure(string adventureDetails, vector<string> adventureLocations) :
        AdventureState(adventureDetails, adventureLocations) {
    AdventureState::AdventureState(adventureDetails, adventureLocations);
}

Adventure::~Adventure() {
}

void Adventure::execute() {
    initialiseAdventure();
}

void Adventure::initialiseAdventure() {
    AdventureState::initialiseAdventure();

    listenForInput();
}

void Adventure::listenForInput() {
    bool continueAdventure = true;

    while (continueAdventure) {

        continueAdventure = commandManager.gatherInput();

        if (continueAdventure) {
            printAdventureLocationDetails();
            printCommands();
        }
    }
}

void Adventure::printCommands() {
    printLine();
    cout << "Enter command: add (item); remove (item); list;\n"
            "               go north; north east; ne; quit :> ";
}

