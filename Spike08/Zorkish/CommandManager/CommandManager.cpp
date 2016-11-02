#include "CommandManager.h"

CommandManager::CommandManager() {

}

CommandManager::CommandManager(Player &player, LocationGraph &locationGraph){
    commandPlayer = &player;
    commandLocationGraph = &locationGraph;

    takeCommand = TakeCommand();
    moveCommand = MoveCommand();
    listCommand = ListCommand();
    removeCommand = RemoveCommand();
}

CommandManager::~CommandManager() {
}

vector<string> CommandManager::splitSentence(string userInput) {
    vector<string> words;

    stringstream ss(userInput);
    string word;

    while(getline(ss, word, ' ')) {
        words.push_back(word);
    }

    return words;
}

bool CommandManager::quit(string userInput) {
    return userInput == "quit";
}

vector<string> CommandManager::checkIfPrefix(vector<string> words) {
    if (words[0] == "go" && words.size() == 1) {
        words[0] = "";
    } else if (words[0] == "go") {
        words.erase(words.begin());
    }
    return words;
}

string CommandManager::checkIfAcronym(string word) {
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

bool CommandManager::gatherInput(){
    string userInput;
    getline(cin, userInput);
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    vector<string> words = splitSentence(userInput);

    if (words.size() > 0) {

        if (quit(words[0])) {
            return false;
        }

        words = checkIfPrefix(words);

        if (words[0] != "" && words.size() == 1) {
            if (words[0] == "list") {
                listCommand.execute(commandPlayer);
            } else {
                words[0] = checkIfAcronym(words[0]);
                moveCommand.execute(words[0], commandLocationGraph);
            }
        } else if (words.size() > 1) {
            int wordsSize = words.size();

            string sentence;
            for (int i = 0; i < wordsSize; i++) {
                if (words[i] == "add" || words[i] == "remove") {
                } else if (i == wordsSize - 1) {
                    sentence += words[i];
                } else {
                    sentence += words[i] + " ";
                }
            }

            if (words[0] == "add") {
                takeCommand.execute(sentence, commandPlayer, commandLocationGraph);
            } else if (words[0] == "remove") {
                removeCommand.execute(sentence, commandPlayer, commandLocationGraph);
            } else {
                moveCommand.execute(sentence, commandLocationGraph);
            }
        }
    }

    return true;
}