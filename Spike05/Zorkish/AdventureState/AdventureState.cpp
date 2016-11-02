#include "AdventureState.h"

AdventureState::AdventureState() {
}

AdventureState::~AdventureState() {
}

void AdventureState::execute() {
}

void AdventureState::initialiseAdventure(){
}

void AdventureState::displayHiscore(string adventureName, int adventureScore, int adventureMoves) {
    cout << "Zorkish :: New High Score" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Congratulations!" << endl;
    cout << "You have made it to the Zorkish Hall Of Fame" << endl;
    cout << "Adventure: " + adventureName << endl;
    cout << "Score: " + to_string(adventureScore) << endl;
    cout << "Moves: " + to_string(adventureMoves) << endl;
    cout << "Please type your name and press enter:> ";

    string playerName;
    cin >> playerName;

    FameHall * fameHall = new FameHall();
    fameHall->execute();
}

void AdventureState::printLine() {
    cout << "" << endl;
}
