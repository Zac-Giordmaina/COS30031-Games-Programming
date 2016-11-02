#include "Location.h"
#include "../Bag/Bag.h"

Location::Location(vector<string> details, vector<string> links, vector<string> entities) {
    locationName = details[0];
    locationDescription = details[1];
    locationLinks = setupLocationLinks(links);

    setupLocationEntities(entities);
}

Location::Location() {
}

Location::~Location() {
}

map<string, string> Location::setupLocationLinks(vector<string> links) {
    map<string, string> tempMap;

    for (int i = 0; i < links.size(); i = i + 2) {
        tempMap.insert(pair<string, string>(links[i], links[i + 1]));
    }

    return tempMap;
}

string Location::getName() {
    return locationName;
}

string Location::getDescription(){
    return locationDescription;
}

void Location::printLinks() {
    cout << locationName + " map:" << endl;
    for(map<string, string>::iterator it = locationLinks.begin(); it != locationLinks.end(); it++) {
        cout << "To the " + it->first + " you see " + it->second << endl;
    }
}

void Location::printEntities() {
    cout << locationName + " contains:" << endl;
    locationEntities.printInventory();
}

void Location::printBag() {
    if (locationBag.getName() != "null") {
        cout << locationBag.getName() + ", (" + locationBag.getDescription() + ")" << endl;
    }
}

map<string, string> Location::getLinks() {
    return locationLinks;
}

void Location::setupLocationEntities(vector<string> entities) {
    bool hasBag = false;
    vector<string> bagDetails;

    for (int i = 0; i < entities.size(); i = i + 3) {
        if (!hasBag) {
            if (entities[i] == "gem") {
                locationEntities.add(Gem(entities[i + 1], entities[i + 2]));
            } else if (entities[i] == "key") {
                locationEntities.add(Key(entities[i + 1], entities[i + 2]));
            } else if (entities[i] == "sword") {
                locationEntities.add(Sword(entities[i + 1], entities[i + 2]));
            } else {
                i = i - 2;
                hasBag = true;
            }
        } else {
            bagDetails.push_back(entities[i]);
            bagDetails.push_back(entities[i + 1]);
            bagDetails.push_back(entities[i + 2]);
        }
    }

    if (hasBag) {
        locationBag = Bag(bagDetails);
    }
}

void Location::addToInventory(InventoryItem item) {
    locationEntities.add(item);
}

void Location::removeFromInventory(string itemKey, InventoryItem item) {
    if (itemKey == "") {
        locationEntities.remove(item, itemKey);
    } else {
        locationBag.removeFromContainer(item, itemKey);
    }
}

Inventory Location::getEntities() {
    return locationEntities;
}

Bag Location::getBag() {
    return locationBag;
}

void Location::unlockBag(string item, string itemKey) {
    locationBag.unlockContainer(item, itemKey);
}

void Location::addToBag(InventoryItem item) {
    locationBag.addToContainer(item);
}
