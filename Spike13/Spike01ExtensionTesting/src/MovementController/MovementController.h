#ifndef GRIDWORLDEXTENSION_MOVEMENTCONTROLLER_H
#define GRIDWORLDEXTENSION_MOVEMENTCONTROLLER_H

#include <iostream>
#include <vector>

#include "../Player/Player.h"
#include "../Map/Map.h"

using namespace std;

class MovementController {
    public:
        const string WALL = "Wall";
        const string GOAL = "Goal";
        const string DEATH = "Death";
        const string OFFMAP = "Offmap";

        string performMovement(string input, Player player, Map map);
        bool validMovement(string input);

    private:
        const string NORTH = "North";
        const string EAST = "East";
        const string SOUTH = "South";
        const string WEST = "West";
        const vector <string> VALID_MOVEMENTS = {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                DEATH,
                GOAL
        };
};

#endif //GRIDWORLDEXTENSION_MOVEMENTCONTROLLER_H
