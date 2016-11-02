#ifndef ZORKISH_LOCATION_H
#define ZORKISH_LOCATION_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Location {
    public:
        Location(vector<string> details, vector<string> links);
        Location();
        ~Location();

        string getName();
        string getDescription();
        map<string, string> getLinks();
        void printLinks();
    private:
        string locationName, locationDescription;
        map<string, string> locationLinks;

        map<string, string> setupLocationLinks(vector<string> links);
};


#endif //ZORKISH_LOCATION_H
