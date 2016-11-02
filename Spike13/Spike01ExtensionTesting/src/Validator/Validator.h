#ifndef GRIDWORLDEXTENSION_VALIDATOR_H
#define GRIDWORLDEXTENSION_VALIDATOR_H

#include <iostream>
#include <vector>

using namespace std;

class Validator {
    public:
        void input (string &input, string validMoves);

        bool validCharacter(string input);
    private:
        const vector <string> VALID_CHARACTERS = {"n", "e", "s", "w", "q"};

        const string QUIT_GAME = "q";
};

#endif //GRIDWORLDEXTENSION_VALIDATOR_H
