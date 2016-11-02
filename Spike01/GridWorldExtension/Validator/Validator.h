#ifndef GRIDWORLDEXTENSION_VALIDATOR_H
#define GRIDWORLDEXTENSION_VALIDATOR_H

#include <iostream>
#include <vector>

using namespace std;

class Validator {
    public:
        void input (string &input, string validMoves);

    private:
        const vector <string> VALID_CHARACTERS = {"n", "e", "s", "w", "q"};
        const string QUIT_GAME = "q";

        bool validCharacter(string input);
};

#endif //GRIDWORLDEXTENSION_VALIDATOR_H
