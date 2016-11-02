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
    cout << "Enter command: take (item) [from (item)]; remove (item); list;\n"
            "               [go] north; north east; ne; south\n"
            "               put (item) in (item), open (item) [with (item)]; quit :> ";
}

