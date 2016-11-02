#ifndef ZORKISH_LOCATIONGRAPH_H
#define ZORKISH_LOCATIONGRAPH_H


#include "../Location/Location.h"

class LocationGraph {
    public:
        LocationGraph();
        ~LocationGraph();

        void addLocation(vector<string> locationDetails, vector<string> locationLinks);
        Location getCurrentLocation();
        void setDefaultLocation();
        bool locationHasLink(string userInput);
        void attemptMove(string userInput);
    private:
        vector<Location> locations;
        Location currentLocation = Location();
        string newLocationName;
};


#endif //ZORKISH_LOCATIONGRAPH_H
