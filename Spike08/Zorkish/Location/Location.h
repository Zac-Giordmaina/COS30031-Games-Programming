#ifndef ZORKISH_LOCATION_H
#define ZORKISH_LOCATION_H

#include <iostream>
#include <vector>
#include <map>
#include "../Inventory/Inventory.h"

using namespace std;

class Location {
    private:
        string locationName, locationDescription;
        map<string, string> locationLinks;
        Inventory locationEntities = Inventory("location");

        map<string, string> setupLocationLinks(vector<string> links);
        void setupLocationEntities(vector<string> entities);
    public:
        Location(vector<string> details, vector<string> links, vector<string> entities);
        Location();

        ~Location();
        string getName();
        string getDescription();
        map<string, string> getLinks();
        void printLinks();
        void printEntities();
        void addToInventory(InventoryItem item);
        void removeFromInventory(InventoryItem item);
        Inventory getEntities();
};


#endif //ZORKISH_LOCATION_H
