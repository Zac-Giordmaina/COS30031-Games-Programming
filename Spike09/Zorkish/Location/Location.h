#ifndef ZORKISH_LOCATION_H
#define ZORKISH_LOCATION_H

#include <iostream>
#include <vector>
#include <map>
#include "../Inventory/Inventory.h"
#include "../Bag/Bag.h"

using namespace std;

class Location {
    private:
        string locationName, locationDescription;
        map<string, string> locationLinks;
        Inventory locationEntities = Inventory("location");
        Bag locationBag = Bag();

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
        void printBag();
        void addToInventory(InventoryItem item);
        void addToBag(InventoryItem item);
        void removeFromInventory(string itemKey, InventoryItem item);
        Inventory getEntities();
        Bag getBag();
        void unlockBag(string item, string itemKey);
};


#endif //ZORKISH_LOCATION_H
