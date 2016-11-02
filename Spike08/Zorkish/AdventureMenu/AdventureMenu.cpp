#include "AdventureMenu.h"

AdventureMenu::AdventureMenu() {
    loadAdventures();
}

AdventureMenu::~AdventureMenu() {

}

void AdventureMenu::loadAdventures(){
    ifstream file("./AdventureMenu/adventures.txt");
    string fileLine;
    int lineCount = 0;

    string tempAdventureDetails;
    vector<string> tempAdventureLocations;

    while (getline(file, fileLine))
    {
        if (lineCount == 0) {
            tempAdventureDetails = fileLine;

            stringstream ss(fileLine);
            int count = 0;
            string title;

            while(count == 0) {
                getline(ss, title, ',');
                adventureNames.push_back(title);
                count++;
            }
        }

        lineCount++;

        if (fileLine == "break") {
            adventureStates.push_back(new Adventure(tempAdventureDetails, tempAdventureLocations));

            lineCount = 0;
            tempAdventureLocations.clear();
        } else if (lineCount > 1){
            tempAdventureLocations.push_back(fileLine);
        }
    }
}

void AdventureMenu::execute() {
    int min = 1;
    int max = adventureNames.size();
    int adventureStateIndex;

    do {
        printContent(max);
        cin >> adventureStateIndex;
        printConsoleBuffer();
    } while (!validInput(min, max, adventureStateIndex));

    executeAdventure(adventureStateIndex);
}

void AdventureMenu::printContent(int max) {
    cout << "Zorkish :: Select Adventure" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Choose your adventure:" << endl;

    printAdventureNames();

    cout << "Select 1 - " + to_string(max) + ":> ";
}

void AdventureMenu::executeAdventure(int adventureStateIndex) {
    AdventureState * tempState = adventureStates[adventureStateIndex - 1];
    tempState->execute();
}

void AdventureMenu::printAdventureNames() {
    for (int i = 0; i != adventureNames.size(); ++i)
    {
        cout << to_string(i + 1) + ". " + adventureNames[i] << endl;
    }
}
