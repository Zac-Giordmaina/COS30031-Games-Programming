#include "Adventure.h"

Adventure::Adventure(string adventureDetails, vector<string> adventureLocations) :
        AdventureState(adventureDetails, adventureLocations) {
    AdventureState::AdventureState(adventureDetails, adventureLocations);
}

Adventure::~Adventure() {
}

void Adventure::execute() {
    initialiseAdventure();
}

void Adventure::initialiseAdventure() {
    AdventureState::initialiseAdventure();

    listenForInput();
}

void Adventure::listenForInput() {
    bool continueAdventure = true;
    string userInput;

    while (continueAdventure) {
        getline(cin, userInput);
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        vector<string> words = commandProcessor.splitSentence(userInput);

        if (words.size() > 0) {
            words = commandProcessor.checkIfPrefix(words);

            if (words[0] != "" && words.size() == 1) {
                words[0] = commandProcessor.checkIfAcronym(words[0]);
                locationGraph.attemptMove(words[0]);
            } else if (words.size() > 1) {
                string sentence;
                int wordsSize = words.size();

                for (int i = 0; i < wordsSize; i++) {
                    if (i == wordsSize - 1) {
                        sentence += words[i];
                    } else {
                        sentence += words[i] + " ";
                    }
                }

                locationGraph.attemptMove(sentence);
            }

            continueAdventure = commandProcessor.checkIfQuit(userInput);

            if (continueAdventure) {
                printAdventureLocationDetails();
                printCommands();
            }

        } else {
            printAdventureLocationDetails();
            printCommands();
        }

//        Implement hiscore when required
//        else if (userInput == "hiscore") {
//            cout << "You have entered the magic word and will now see the “New High Score” screen." << endl;
//            continueAdventure = false;
//            displayHiscore(adventureName, adventureScore, adventureMoves);
//        }
    }
}

void Adventure::printCommands() {
    printLine();
    cout << "Enter movement: go north; north; n :> ";
}

