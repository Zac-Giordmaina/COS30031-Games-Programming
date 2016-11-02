#include "LocationGraph.h"

LocationGraph::LocationGraph() {
}

LocationGraph::~LocationGraph() {
}

void LocationGraph::addLocation(vector<string> locationDetails, vector<string> locationLinks, vector<string> locationEntities) {
    locations.push_back(Location(locationDetails, locationLinks, locationEntities));
}

Location LocationGraph::getCurrentLocation() {
    return currentLocation;
}

void LocationGraph::setDefaultLocation() {
    currentLocation = locations[0];
}

void LocationGraph::attemptMove(string userInput) {
    if (locationHasLink(userInput)) {
        for (int i = 0; i < locations.size(); i++) {
            if (newLocationName == locations[i].getName()) {
                currentLocation = locations[i];
            }
        }
    } else {
        cout << "\nInvalid direction entered!" << endl;
    }
}

bool LocationGraph::locationHasLink(string userInput) {
    map<string, string> locationLinks = currentLocation.getLinks();

    for (map<string, string>::iterator it = locationLinks.begin(); it != locationLinks.end(); ++it)
    {
        if ((*it).first == userInput) {
            newLocationName = (*it).second;
            return true;
        }
    }
    return false;
}

void LocationGraph::addToLocationInventory(InventoryItem item) {
    if (item.getName() != "fail") {
        currentLocation.addToInventory(item);
    }
}

InventoryItem LocationGraph::removeFromLocationInventory(string itemName) {
    InventoryItem tempItem = currentLocation.getEntities().itemIsInInventory(itemName);

    if (tempItem.getName() != "fail") {
        currentLocation.removeFromInventory(tempItem);
        cout << "\nItem removed from the player inventory" << endl;
    } else {
        cout << "\nThis item can not be removed from the player inventory" << endl;
    }

    return tempItem;
}
