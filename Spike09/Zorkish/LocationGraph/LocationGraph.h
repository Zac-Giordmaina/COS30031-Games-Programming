#ifndef ZORKISH_LOCATIONGRAPH_H
#define ZORKISH_LOCATIONGRAPH_H


#include "../Location/Location.h"
#include "../HasCommand/HasCommand.h"

class LocationGraph : public HasCommand {
    public:
        LocationGraph();
        ~LocationGraph();

        void addLocation(vector<string> locationDetails, vector<string> locationLinks, vector<string> locationEntities);
        Location getCurrentLocation();
        void setDefaultLocation();
        bool locationHasLink(string userInput);
        void attemptMove(string userInput);
        InventoryItem checkIfContainerHasItem(string key, string value);
        InventoryItem execute(string key, string value);
        void execute(int i, string value);
        bool execute(string value);
        void execute(string key, string itemKey, InventoryItem item);
        void execute(string key, string item, string itemKey);
    private:
        vector<Location> locations;
        Location currentLocation = Location();
        string newLocationName;
};


#endif //ZORKISH_LOCATIONGRAPH_H
