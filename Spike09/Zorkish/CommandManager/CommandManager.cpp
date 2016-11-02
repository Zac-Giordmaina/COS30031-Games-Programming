#include "CommandManager.h"

CommandManager::CommandManager() {

}

CommandManager::CommandManager(Player &player, LocationGraph &locationGraph){
    commands.push_back(&player);
    commands.push_back(&locationGraph);
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



bool CommandManager::validCommand(string word) {
    for (int i = 0; i < validCommands.size(); i++) {
        if (validCommands[i] == word) {
            return true;
        }
    }
    return false;
}


bool CommandManager::gatherInput(){
    string userInput;
    getline(cin, userInput);
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    vector<string> words = splitSentence(userInput);

    if (words.size() > 0) {

        if (validCommand(words[0])) {

            if (quit(words[0])) {
                return false;
            }

            words = checkIfPrefix(words);

            if (words[0] != "" && words.size() == 1) {
                if (words[0] == "list") {
                    commands.at(0)->execute();
                } else {
                    words[0] = checkIfAcronym(words[0]);
                    commands.at(1)->execute(0, words[0]);
                }
            } else if (words.size() > 1) {
                int wordsSize = words.size();

                string sentence;
                for (int i = 0; i < wordsSize; i++) {
                    if (words[i] == "take" || words[i] == "remove"
                        || words[i] == "put" || words[i] == "open"){
                    } else if (i == wordsSize - 1) {
                        sentence += words[i];
                    } else {
                        sentence += words[i] + " ";
                    }
                }

                if (words[0] == "take") {
                    int fromIndex = indexOf(words, "from");

                    if (fromIndex == -1) {
                        addItem(sentence);
                    } else {
                        string item = stripFirstWord(words, fromIndex);
                        string itemFrom = stripSecondWord(words, fromIndex);
                        if (itemFrom == "") {
                            cout << "Where would you like to take the item from?" << endl;
                        } else {
                            addItem(item, itemFrom);
                        }
                    }
                } else if (words[0] == "remove") {
                    removeItem(sentence);
                } else if (words[0] == "open") {
                    int withIndex = indexOf(words, "with");

                    if (withIndex == -1) {
                        commands.at(1)->execute(1, sentence);
                    } else {
                        string container = stripFirstWord(words, withIndex);
                        string containerKey = stripSecondWord(words, withIndex);
                        if (containerKey == "") {
                            cout << "\nWhat would you like to open with?" << endl;
                        } else {
                            InventoryItem tempItem = commands.at(0)->execute("search", containerKey);

                            if (tempItem.getName() != "fail") {
                                commands.at(1)->execute("open", container, containerKey);
                            } else {
                                cout << "\nPlayer inventory does not contain " + containerKey << endl;
                            }
                        }
                    }
                } else if (words[0] == "put") {
                    int inIndex = indexOf(words, "in");

                    if (inIndex == -1) {
                        commands.at(1)->execute(1, sentence);
                    } else {
                        string item = stripFirstWord(words, inIndex);
                        string itemContainer = stripSecondWord(words, inIndex);
                        if (itemContainer == "") {
                            cout << "\nWhere would you like to put the " + item + "?" << endl;
                        } else {
                            removeItem(item, itemContainer);
                        }
                    }
                } else {
                    commands.at(1)->execute(0, sentence);
                }
            }

        } else {
            cout << "\n" + userInput + " is an invalid command!" << endl;
        }

    }

    return true;
}

void CommandManager::addItem(string item) {
    InventoryItem tempItem = commands.at(1)->execute("take", item);

    if (tempItem.getName() != "fail") {
        commands.at(1)->execute("remove", "", tempItem);
        commands.at(0)->execute("add", "", tempItem);
        cout << "\nItem added to the player inventory" << endl;
    } else {
        cout << "\nThis item can not be added to the player inventory" << endl;
    }
}

void CommandManager::addItem(string itemToTake, string itemToTakeFrom) {
    InventoryItem tempItem = commands.at(1)->execute(itemToTake, itemToTakeFrom);

    if (tempItem.getName() != "fail") {
        commands.at(1)->execute("removeFromContainer", itemToTakeFrom, tempItem);
        commands.at(0)->execute("add", "", tempItem);
        cout << "\nItem added to the player inventory" << endl;
    } else {
        cout << "\nThis item can not be added to the player inventory" << endl;
    }
}

void CommandManager::removeItem(string item) {
    InventoryItem tempItem = commands.at(0)->execute("search", item);

    if (tempItem.getName() != "fail") {
        string itemKey = tempItem.getKey();
        commands.at(0)->execute("remove", itemKey, tempItem);
        commands.at(1)->execute("add", "", tempItem);
        cout << "\nItem removed from the player inventory" << endl;
    } else {
        cout << "\nThis item can not be removed from the player inventory" << endl;
    }
}

void CommandManager::removeItem(string item, string itemContainer) {
    InventoryItem tempItem = commands.at(0)->execute("search", item);

    if (tempItem.getName() != "fail") {
        if (commands.at(1)->execute(itemContainer)) {
            string itemKey = tempItem.getKey();
            commands.at(0)->execute("remove", itemKey, tempItem);
            commands.at(1)->execute("addToContainer", "", tempItem);
            cout << "\nItem removed from the player inventory" << endl;
        } else {
            cout << "\n" + itemContainer + " can not be added to" << endl;
        }
    } else {
        cout << "\nPlayer inventory does not contain " + item << endl;
    }
}

int CommandManager::indexOf(vector<string> words, string word) {
    for (int i = 0; i < words.size(); i++){
        if (words[i] == word) {
            return i;
        }
    }
    return -1;
}

string CommandManager::stripFirstWord(vector<string> words, int index) {
    string tempString = "";

    for (int i = 1; i < index; i++) {
        if (i == index - 1) {
            tempString += words[i];
        } else {
            tempString += words[i] + " ";
        }
    }

    return tempString;
}

string CommandManager::stripSecondWord(vector<string> words, int index) {
    string tempString = "";

    for (int i = index + 1; i < words.size(); i++) {
        if (i == words.size() - 1) {
            tempString += words[i];
        } else {
            tempString += words[i] + " ";
        }
    }

    return tempString;
}
