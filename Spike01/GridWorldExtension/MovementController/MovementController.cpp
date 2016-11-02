#include "MovementController.h"

string MovementController::performMovement (string input, Player player, Map map) {
    string mapCell;

    switch (input[0]) {
        case 'n':
            mapCell = map.getMapCell(player.getCurrentYPosition() - 1, player.getCurrentXPosition());
            if (mapCell == map.BLANK_MARKER) {
                return NORTH;
            }
            break;
        case 'e':
            mapCell = map.getMapCell(player.getCurrentYPosition(), player.getCurrentXPosition() + 1);
            if (mapCell == map.BLANK_MARKER) {
                return EAST;
            }
            break;
        case 's':
            mapCell = map.getMapCell(player.getCurrentYPosition() + 1, player.getCurrentXPosition());
            if (mapCell == map.BLANK_MARKER) {
                return SOUTH;
            }
            break;
        default:
            mapCell = map.getMapCell(player.getCurrentYPosition(), player.getCurrentXPosition() - 1);
            if (mapCell == map.BLANK_MARKER) {
                return WEST;
            }
            break;
    }

    if (mapCell == map.WALL_MARKER) {
        return WALL;
    } else if (mapCell == map.GOAL_MARKER) {
        return GOAL;
    } else if (mapCell == map.DEATH_MARKER) {
        return DEATH;
    } else {
        return OFFMAP;
    }
}

bool MovementController::validMovement (string movementResult) {
    for (int i = 0; i < VALID_MOVEMENTS.size(); i++)
    {
        if (VALID_MOVEMENTS[i] == movementResult) {
            return true;
        }
    }
    return false;
}
