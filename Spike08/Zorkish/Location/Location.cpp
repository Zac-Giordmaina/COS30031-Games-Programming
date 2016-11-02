#include "Location.h"

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

map<string, string> Location::getLinks() {
    return locationLinks;
}

void Location::setupLocationEntities(vector<string> entities) {
    for (int i = 0; i < entities.size(); i = i + 3) {
        if (entities[i] == "gem") {
            locationEntities.add(Gem(entities[i + 1], entities[i + 2]));
        } else {
            locationEntities.add(Sword(entities[i + 1], entities[i + 2]));
        }
    }
}

void Location::addToInventory(InventoryItem item) {
    return locationEntities.add(item);
}

void Location::removeFromInventory(InventoryItem item) {
    return locationEntities.remove(item);
}

Inventory Location::getEntities() {
    return locationEntities;
}
