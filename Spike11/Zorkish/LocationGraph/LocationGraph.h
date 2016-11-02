#ifndef ZORKISH_LOCATIONGRAPH_H
#define ZORKISH_LOCATIONGRAPH_H


#include "../Location/Location.h"
#include "../HasCommand/HasCommand.h"
#include "../HasMessaging/HasMessaging.h"
#include "../Messaging/Messaging.h"

class LocationGraph : public HasCommand, public HasMessaging {
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
        Elixir executeConsume(string value);
        void executeConsume(Elixir value);
        void execute(string key, string itemKey, InventoryItem item);
        void execute(string key, string item, string itemKey);

        void addMessenger(Messaging &messaging);

private:
        vector<Location> locations;
        Location currentLocation = Location();
        string newLocationName;
        Messaging * locationMessenger;
};


#endif //ZORKISH_LOCATIONGRAPH_H
