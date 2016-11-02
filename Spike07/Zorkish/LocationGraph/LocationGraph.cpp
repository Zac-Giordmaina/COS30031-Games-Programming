#include "LocationGraph.h"

LocationGraph::LocationGraph() {
}

LocationGraph::~LocationGraph() {
}

void LocationGraph::addLocation(vector<string> locationDetails, vector<string> locationLinks) {
    locations.push_back(Location(locationDetails, locationLinks));
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
