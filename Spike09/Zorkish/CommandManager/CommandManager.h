#ifndef ZORKISH_COMMANDPROCESSOR_H
#define ZORKISH_COMMANDPROCESSOR_H

#include <vector>
#include <sstream>
#include <iostream>
#include "../LocationGraph/LocationGraph.h"
#include "../Player/Player.h"

using namespace std;

class CommandManager {
    private:
        vector<string> validCommands = {
            "north",
            "n",
            "east",
            "e",
            "south",
            "s",
            "west",
            "w",
            "ne",
            "nw",
            "se",
            "sw",
            "take",
            "remove",
            "list",
            "put",
            "open",
            "quit"
        };

        bool quit(string userInput);
        vector<string> checkIfPrefix(vector<string> words);
        string checkIfAcronym(string word);
        bool validCommand(string word);
        vector<string> splitSentence(string userInput);
        void addItem(string item);
        void addItem(string itemToTake, string itemToTakeFrom);
        void removeItem(string item);
        void removeItem(string item, string itemContainer);
        int indexOf(vector<string> words, string word);
        string stripFirstWord(vector<string> words, int index);
        string stripSecondWord(vector<string> words, int index);

    public:
        CommandManager();
        CommandManager(Player &player, LocationGraph &locationGraph);
        ~CommandManager();

        bool gatherInput();

        vector<HasCommand*> commands;

};


#endif //ZORKISH_COMMANDPROCESSOR_H
