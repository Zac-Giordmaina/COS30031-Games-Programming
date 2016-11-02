#ifndef ZORKISH_COMMANDPROCESSOR_H
#define ZORKISH_COMMANDPROCESSOR_H

#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class CommandProcessor {
    private:

        string inventoryCommands[3] = {
                "add",
                "remove",
                "list",
        };


        string movementCommands[8] = {
            "north",
            "east",
            "south",
            "west",
            "north east",
            "north west",
            "south east",
            "south west"
        };

    public:
        CommandProcessor();
        ~CommandProcessor();
        void execute();

        bool validateInventoryCommand(string userInput);
        bool validateMovementCommand(string userInput);
        bool checkIfQuit(string userInput);
        vector<string> checkIfPrefix(vector<string> words);
        string checkIfAcronym(string word);
        vector<string> splitSentence(string userInput);

};


#endif //ZORKISH_COMMANDPROCESSOR_H
