#ifndef ZORKISH_COMMANDPROCESSOR_H
#define ZORKISH_COMMANDPROCESSOR_H

#include <vector>
#include <sstream>
#include <iostream>
#include "../LocationGraph/LocationGraph.h"
#include "../Player/Player.h"
#include "../TakeCommand/TakeCommand.h"
#include "../MoveCommand/MoveCommand.h"
#include "../ListCommand/ListCommand.h"
#include "../RemoveCommand/RemoveCommand.h"

using namespace std;

class CommandManager {
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

        bool quit(string userInput);
        vector<string> checkIfPrefix(vector<string> words);
        string checkIfAcronym(string word);
        vector<string> splitSentence(string userInput);

    public:
        CommandManager();
        CommandManager(Player &player, LocationGraph &locationGraph);
        ~CommandManager();

        bool gatherInput();

        Player * commandPlayer;
        LocationGraph * commandLocationGraph;

        TakeCommand takeCommand;
        MoveCommand moveCommand;
        ListCommand listCommand;
        RemoveCommand removeCommand;

};


#endif //ZORKISH_COMMANDPROCESSOR_H
