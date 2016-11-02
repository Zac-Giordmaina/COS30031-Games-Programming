#include "AdventureState.h"

AdventureState::AdventureState(string adventureDetails, vector<string> adventureLocations){
    player = Player();
    locationGraph = LocationGraph();
    commandManager = CommandManager(player, locationGraph);

    details = adventureDetails;
    locations = adventureLocations;
}

AdventureState::~AdventureState() {
}

void AdventureState::execute() {
    initialiseAdventure();
}

void AdventureState::initialiseAdventure(){
    setupAdventureDetails();
    setupLocations();
    printContent();
}

void AdventureState::setupAdventureDetails(){
    stringstream ss(details);
    string tempDetail;
    int count = 0;

    while(getline(ss, tempDetail, ',')) {
        if (count == 0) {
            adventureName = tempDetail;
        } else {
            adventureDescription = tempDetail;
        }
        count++;
    }
}

void AdventureState::setupLocations() {
    for (int i = 0; i != locations.size(); ++i)
    {
        string locationDetails = locations.at(i);
        stringstream ss(locationDetails);

        string tempDetail;
        int count = 0;
        bool locationData = true;
        vector<string> tempLocationDetails;
        vector<string> tempLocationLinks;
        vector<string> tempLocationEntities;

        while (getline(ss, tempDetail, ','))
        {
            if (count < 2) {
            tempLocationDetails.push_back(tempDetail);
            } else if (tempDetail == "ENT") {
                locationData = false;
            } else if (locationData) {
                tempLocationLinks.push_back(tempDetail);
            } else {
                tempLocationEntities.push_back(tempDetail);
            }

            count++;
        }

        locationGraph.addLocation(tempLocationDetails, tempLocationLinks, tempLocationEntities);
        tempLocationDetails.clear();
        tempLocationLinks.clear();
    }

    locationGraph.setDefaultLocation();
}

void AdventureState::printContent() {
    printBuffer();
    cout << "Zorkish :: " + adventureName << endl;
    cout << adventureDescription << endl;
    cout << "--------------------------------------------------------" << endl;
}

void AdventureState::printAdventureLocationDetails() {
    printLine();
    cout << "You are currently in " + locationGraph.getCurrentLocation().getName() + ", " + locationGraph.getCurrentLocation().getDescription() << endl;
    printLine();
    locationGraph.getCurrentLocation().printEntities();
    locationGraph.getCurrentLocation().printBag();
    locationGraph.getCurrentLocation().printElixir();
    printLine();
    locationGraph.getCurrentLocation().printLinks();
    printLine();
    player.printEnergy();
    player.printPowers();
}

void AdventureState::displayHiscore(string adventureName, int adventureScore, int adventureMoves) {
    printBuffer();
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

    printBuffer();
    FameHall * fameHall = new FameHall();
    fameHall->execute();
}

void AdventureState::printBuffer() {
    cout << "" << endl;
    cout << "" << endl;
}

void AdventureState::printLine() {
    cout << "" << endl;
}
