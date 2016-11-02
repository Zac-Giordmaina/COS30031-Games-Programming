#include "Location.h"

Location::Location(vector<string> details, vector<string> links) {
    locationName = details[0];
    locationDescription = details[1];
    locationLinks = setupLocationLinks(links);
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
    for(map<string, string>::iterator it = locationLinks.begin(); it != locationLinks.end(); it++) {
        cout << "To the " + it->first + " you see " + it->second << endl;
    }
}

map<string, string> Location::getLinks() {
    return locationLinks;
}
