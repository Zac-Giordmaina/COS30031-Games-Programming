#include "Validator.h"

void Validator::input (string &input, string validMoves) {
    bool validInput = false;

    while (!validInput) {
        cout << "You can move " + validMoves + ": ";
        getline(cin, input);
        cout << "" << endl;

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input.length() == 1 && validCharacter(input)) {
            validInput = true;
        } else {
            cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl << endl;
        }
    }
}

bool Validator::validCharacter (string input) {
    // check if the player can move in the direction
    for (int i = 0; i < VALID_CHARACTERS.size(); i++ )
    {
        if (VALID_CHARACTERS[i] == input) {
            return true;
        }
    }
    return false;
}