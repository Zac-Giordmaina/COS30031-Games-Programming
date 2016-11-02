#include "Map.h"

void Map::drawMap () {
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++) {
            cout << map[i][j];
        }
        cout << "" << endl;
    }
    cout << "" << endl;
}


void Map::updateMap (Player player) {
    map[player.getPreviousYPosition()][player.getPreviousXPosition()] = BLANK_MARKER;
    map[player.getCurrentYPosition()][player.getCurrentXPosition()] = PLAYER_MARKER;
}

void Map::initialisePlayerPosition (Player &player) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == PLAYER_MARKER) {
                player.setPlayerCurrentPosition(i, j);
            }
        }
    }
}

void Map::updatePlayerPosition (string input, Player &player) {
    player.setPlayerPreviousPosition();

    switch (input[0]) {
        case 'n':
            player.setCurrentYPosition(-1);
            break;
        case 'e':
            player.setCurrentXPosition(1);
            break;
        case 's':
            player.setCurrentYPosition(1);
            break;
        default:
            player.setCurrentXPosition(-1);
            break;
    }
}

string Map::getMapCell(int y, int x) {
    return map[y][x];
}
