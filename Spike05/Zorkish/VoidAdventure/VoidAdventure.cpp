#include "VoidAdventure.h"

VoidAdventure::VoidAdventure() {
    adventureName = "Void";
    adventureScore = 6000;
    adventureMoves = 34;
}

VoidAdventure::~VoidAdventure() {

}

void VoidAdventure::execute() {
    initialiseAdventure();
}

void VoidAdventure::initialiseAdventure() {
    bool continueAdventure = true;
    string userInput;

    cout << "Welcome to Zorkish: Void World\n"
            "This world is simple and pointless. Used it to test Zorkish phase 1 spec." << endl;

    while (continueAdventure) {
        getline(cin, userInput);

        if (userInput == "quit") {
            cout << "Your adventure has ended without fame or fortune." << endl;
            continueAdventure = false;
        } else if (userInput == "hiscore") {
            cout << "You have entered the magic word and will now see the “New High Score” screen." << endl;
            continueAdventure = false;
            displayHiscore(adventureName, adventureScore, adventureMoves);
        } else {
            cout << "Enter \"quit\" or \"hiscore\"" << endl;
        }
    }
}
