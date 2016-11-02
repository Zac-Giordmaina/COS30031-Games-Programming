#ifndef GRIDWORLDEXTENSION_MAP_H
#define GRIDWORLDEXTENSION_MAP_H

#include <iostream>
#include "../Player/Player.h"

using namespace std;

class Map {
    public:
        const string PLAYER_MARKER = "S";
        const string GOAL_MARKER = "G";
        const string DEATH_MARKER = "D";
        const string WALL_MARKER = "#";
        const string BLANK_MARKER = " ";

        void drawMap();
        void updateMap(Player player);
        void updatePlayerPosition(string input, Player &player);
        void initialisePlayerPosition(Player &player);
        string getMapCell(int y, int x);

    private:
        static const int MAP_SIZE = 8;

        string map[MAP_SIZE][MAP_SIZE] = {
                "#", "#",  "#",  "#",  "#",  "#",  "#",  "#",
                "#", "G",  " ",  "D",  "#",  "D",  " ",  "#",
                "#", " ",  " ",  " ",  "#",  " ",  " ",  "#",
                "#", "#",  "#",  " ",  "#",  " ",  "D",  "#",
                "#", " ",  " ",  " ",  "#",  " ",  " ",  "#",
                "#", " ",  "#",  "#",  "#",  "#",  " ",  "#",
                "#", " ",  " ",  " ",  " ",  " ",  " ",  "#",
                "#", "#",  "S",  "#",  "#",  "#",  "#",  "#"
        };
};


#endif //GRIDWORLDEXTENSION_MAP_H
