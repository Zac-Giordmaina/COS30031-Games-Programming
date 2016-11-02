#include <iostream>
#include <vector>

using namespace std;

// Sorry, I want to prettify the console.
void insertConsoleLine() {
    cout << "" << endl;
}

const int MAP_SIZE = 8;
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
const vector <string> VALID_CHARACTERS = {"n", "e", "s", "w", "q"};
const string QUIT_GAME = "q";

const string PLAYER = "S";
const string GOAL_MARKER = "G";
const string DEATH_MARKER = "D";
const string WALL_MARKER = "#";
const string BLANK_MARKER = " ";

const string NORTH = "North";
const string EAST = "East";
const string SOUTH = "South";
const string WEST = "West";
const string WALL = "Wall";
const string GOAL = "Goal";
const string DEATH = "Death";
const string OFFMAP = "Offmap";
const vector <string> VALID_MOVEMENTS = {
        NORTH,
        EAST,
        SOUTH,
        WEST,
        DEATH,
        GOAL
};

bool gameEnd = false;
int playerPreviousPosition[2] = {0, 0};
int playerCurrentPosition[2] = {0, 0};
string message;

void quitGame () {
    gameEnd = true;
}

void drawMap () {
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++) {
            cout << map[i][j];
        }
        insertConsoleLine();
    }
    insertConsoleLine();
}

void drawMessage () {
    cout << message << endl << endl;
}

void render () {
    drawMap();
    drawMessage();
}

void updateMessage(string movementResult) {
    if ( movementResult == DEATH ) {
        message = "YOU DEAD, do not touch the D.";
    } else if ( movementResult == WALL ) {
        message = "There is a wall blocking your path.";
    } else if ( movementResult == GOAL ) {
        message = "Hooray, you have the discovered the gold.";
    } else if ( movementResult == OFFMAP ) {
        message = "You can not escape the bounds of the map!";
    } else {
        message = "You have moved " + movementResult;
    }
}

void updateMap () {
    // Get this off the player model?
    map[playerPreviousPosition[0]][playerPreviousPosition[1]] = BLANK_MARKER;
    map[playerCurrentPosition[0]][playerCurrentPosition[1]] = PLAYER;
}

void updatePlayerPosition (string input) {
    playerPreviousPosition[0] = playerCurrentPosition[0];
    playerPreviousPosition[1] = playerCurrentPosition[1];

    switch (input[0]) {
        case 'n':
            playerCurrentPosition[0] = playerCurrentPosition[0] - 1;
            break;
        case 'e':
            playerCurrentPosition[1] = playerCurrentPosition[1] + 1;
            break;
        case 's':
            playerCurrentPosition[0] = playerCurrentPosition[0] + 1;
            break;
        default:
            playerCurrentPosition[1] = playerCurrentPosition[1] - 1;
            break;
    }
}

bool validMovement (string movementResult) {
    for (int i = 0; i < VALID_MOVEMENTS.size(); i++)
    {
        if (VALID_MOVEMENTS[i] == movementResult) {
            return true;
        }
    }
    return false;
}

string performMovement (string input) {
    string mapCell;

    switch (input[0]) {
        case 'n':
            mapCell = map[playerCurrentPosition[0] - 1][playerCurrentPosition[1]];
            if (mapCell == BLANK_MARKER) {
                return NORTH;
            }
            break;
        case 'e':
            mapCell = map[playerCurrentPosition[0]][playerCurrentPosition[1] + 1];
            if (mapCell == BLANK_MARKER) {
                return EAST;
            }
            break;
        case 's':
            mapCell = map[playerCurrentPosition[0] + 1][playerCurrentPosition[1]];
            if (mapCell == BLANK_MARKER) {
                return SOUTH;
            }
            break;
        default:
            mapCell = map[playerCurrentPosition[0]][playerCurrentPosition[1] - 1];
            if (mapCell == BLANK_MARKER) {
                return WEST;
            }
            break;
    }

    if (mapCell == WALL_MARKER) {
        return WALL;
    } else if (mapCell == GOAL_MARKER) {
        return GOAL;
    } else if (mapCell == DEATH_MARKER) {
        return DEATH;
    } else {
        return OFFMAP;
    }
}

void update (string input) {
    string movementResult = performMovement(input);

    if ( validMovement(movementResult) ) {
        updatePlayerPosition(input);
        updateMap();
    }

    updateMessage(movementResult);

    if (movementResult == DEATH || movementResult == GOAL) {
        quitGame();
    }
}

bool validCharacter (string input) {
    // check if the player can move in the direction
    for (int i = 0; i < VALID_CHARACTERS.size(); i++ )
    {
        if (VALID_CHARACTERS[i] == input) {
            if (VALID_CHARACTERS[i] == QUIT_GAME) {
                quitGame();
            }
            return true;
        }
    }
    return false;
}

string formatMovements (string validMovements) {
    string formattedMovements;
    for (int i = 0; i < validMovements.length() - 1; i++) {
        formattedMovements += string(1, validMovements[i]) + ", ";
    }
    formattedMovements += validMovements[validMovements.length() - 1];
    return formattedMovements;
}

string findValidMovements () {
    string validMovements;
    string north = map[playerCurrentPosition[0] - 1][playerCurrentPosition[1]];
    string east = map[playerCurrentPosition[0]][playerCurrentPosition[1] + 1];
    string south = map[playerCurrentPosition[0] + 1][playerCurrentPosition[1]];
    string west = map[playerCurrentPosition[0]][playerCurrentPosition[1] - 1];

    if (north == BLANK_MARKER || north == GOAL_MARKER || north == DEATH_MARKER) {
        validMovements += "N";
    }
    if (east == BLANK_MARKER || east == GOAL_MARKER || east == DEATH_MARKER) {
        validMovements += "E";
    }
    if (south == BLANK_MARKER || south == GOAL_MARKER || south == DEATH_MARKER) {
        validMovements += "S";
    }
    if (west == BLANK_MARKER || west == GOAL_MARKER || west == DEATH_MARKER) {
        validMovements += "W";
    }

    return validMovements.length() > 1 ? formatMovements(validMovements) : validMovements;
}

void input (string &input) {
    bool validInput = false;

    while (!validInput) {
        cout << "You can move " + findValidMovements() + ": ";
        getline(cin, input);
        insertConsoleLine();

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input.length() == 1 && validCharacter(input)) {
            validInput = true;
        } else {
            cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl << endl;
        }
    }
}

void findPlayerPosition () {
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == PLAYER) {
                playerCurrentPosition[0] = i;
                playerCurrentPosition[1] = j;
            }
        }
    }
};

void initialisePlayer () {
    findPlayerPosition();
}

int main () {
    cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!" << endl;
    cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl << endl;

    drawMap();

    initialisePlayer();

    string userInput;

    while (!gameEnd)
    {

        input(userInput);

        if (!gameEnd) {
            update(userInput);
            render();
        }
    }
}