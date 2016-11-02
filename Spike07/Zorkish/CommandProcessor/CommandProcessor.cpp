#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(){
}

CommandProcessor::~CommandProcessor() {
}

bool CommandProcessor::validateInventoryCommand(string userInput) {
    for (int i = 0; i < inventoryCommands->length(); i++) {
        if (userInput == inventoryCommands[i]) {
            return true;
        }
    }
    return false;
}

bool CommandProcessor::validateMovementCommand(string userInput){
    for (int i = 0; i < movementCommands->length(); i++) {
        if (userInput == movementCommands[i]) {
            return true;
        }
    }
    return false;
}

vector<string> CommandProcessor::splitSentence(string userInput) {
    vector<string> words;

    stringstream ss(userInput);
    string word;

    while(getline(ss, word, ' ')) {
        words.push_back(word);
    }

    return words;
}

bool CommandProcessor::checkIfQuit(string userInput) {
    return userInput != "quit";
}

vector<string> CommandProcessor::checkIfPrefix(vector<string> words) {
    if (words[0] == "go" && words.size() == 1) {
        words[0] = "";
    } else if (words[0] == "go") {
        words.erase(words.begin());
    }
    return words;
}

string CommandProcessor::checkIfAcronym(string word) {
    if (word == "n") return "north";
    if (word == "nw") return "north west";
    if (word == "ne") return "north east";
    if (word == "e") return "east";
    if (word == "s") return "south";
    if (word == "se") return "south east";
    if (word == "sw") return "south west";
    if (word == "w") return "west";
    return word;
}
