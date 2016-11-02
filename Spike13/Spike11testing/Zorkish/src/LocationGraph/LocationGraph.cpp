#include "LocationGraph.h"
#include "../Bag/Bag.h"

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
                locationMessenger->reducePlayerEnergy(-20);
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

InventoryItem LocationGraph::checkIfContainerHasItem(string key, string value) {
    Bag tempBag = currentLocation.getBag();
    string tempName = tempBag.getName();
    transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);

    if (tempName == value) {
        InventoryItem tempItem = tempBag.checkContainerEntities(key);

        if (tempItem.getName() != "fail") {
            return tempItem;
        } else {
            cout << "\nThe " + value + " does not contain the " + key << endl;
        }
    } else {
        cout << "\nInvalid item to be taken from" << endl;
    }
    return InventoryItem("fail", "fail");
}

InventoryItem LocationGraph::execute(string key, string value) {
    if (key == "take") {
        return currentLocation.getEntities().itemIsInInventory(value);
    } else {
        return checkIfContainerHasItem(key, value);
    }
}

void LocationGraph::execute(int i, string value) {
    if (i == 0) {
        attemptMove(value);
    } else {
        Bag tempItem = currentLocation.getBag();
        string tempName = tempItem.getName();
        transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
        if (tempName == value) {
            tempItem.printContainerContents();
        } else {
            cout << "\nThis item can not be opened" << endl;
        }
    }
}

bool LocationGraph::execute(string value) {
    string tempName = currentLocation.getBag().getName();
    transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
    return tempName == value;
}

void LocationGraph::execute(string key, string itemKey, InventoryItem item) {
    if (key == "add") {
        currentLocation.addToInventory(item);
    } else if (key == "addToContainer") {
        currentLocation.addToBag(item);
    } else {
        currentLocation.removeFromInventory(itemKey, item);
    }
}

void LocationGraph::execute(string key, string item, string itemKey) {
    currentLocation.unlockBag(item, itemKey);
}

Elixir LocationGraph::executeConsume(string value) {
    Elixir tempElixir = Elixir();
    string tempName = currentLocation.getElixir().getName();
    transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);

    if (tempName == value) {
        tempElixir = currentLocation.getElixir();
    }

    return tempElixir;
}

void LocationGraph::executeConsume(Elixir value) {
    currentLocation.removeElixir();
}

void LocationGraph::addMessenger(Messaging &messaging) {
    locationMessenger = &messaging;
}
