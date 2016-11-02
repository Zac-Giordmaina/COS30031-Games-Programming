#include "InventoryMadnessAdventure.h"

InventoryMadnessAdventure::InventoryMadnessAdventure(){
    adventureName = "Inventory Madness";
    adventureScore = 6000;
    adventureMoves = 34;

    sapphire = new Gem("Sapphire", "Noice");
    ruby = new Gem("Ruby", "Not Bad");
    emerald = new Gem("Emerald", "Green As");

    player = new Player();
    worldInventory = new Inventory("world");

    worldInventory->add(sapphire);
    worldInventory->add(ruby);
    worldInventory->add(emerald);
}

InventoryMadnessAdventure::~InventoryMadnessAdventure() {
}

void InventoryMadnessAdventure::execute() {
    initialiseAdventure();
}

void InventoryMadnessAdventure::initialiseAdventure() {
    listenForInput();
}

void InventoryMadnessAdventure::printContent() {
    printBuffer();

    cout << "ZorkishApp :: Inventory Madness \n"
    "--------------------------------------------------------" << endl;
    worldInventory->itemCount("gem");
    worldInventory->printInventory();
}

void InventoryMadnessAdventure::listenForInput() {
    bool continueAdventure = true;
    string userInput;

    while (continueAdventure) {
        getline(cin, userInput);
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        vector<string> words = splitSentence(userInput);

        if (words.size() > 0) {

            switch (validateCommand(words[0])) {
                case add:
                    if (words.size() > 1) {
                        addItem(words[1]);
                    } else {
                        cout << "What item would you like to add?" << endl;
                    }
                    break;
                case remove:
                    if (words.size() > 1) {
                        removeItem(words[1]);
                    } else {
                        cout << "What item would you like to remove?" << endl;
                    }
                    break;
                case list:
                    printLine();
                    cout << "Player Inventory:" << endl;
                    player->getInventory()->printInventory();
                    break;
                case quit:
                    printLine();
                    cout << "Your adventure has ended without fame or fortune." << endl;
                    continueAdventure = false;
                    break;
                default:
                    break;
            }

            if (continueAdventure) {
                printContent();
                printCommands();
            }

        } else {
            printContent();
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

InventoryMadnessAdventure::commands InventoryMadnessAdventure::validateCommand(string userInput) {
    if (userInput == "add") return add;
    if (userInput == "remove") return remove;
    if (userInput == "list") return list;
    if (userInput == "quit") return quit;
    return invalid;
}

vector<string> InventoryMadnessAdventure::splitSentence(string userInput) {
    vector<string> words;

    stringstream ss(userInput); // Turn the string into a stream.
    string word;

    while(getline(ss, word, ' ')) {
        words.push_back(word);
    }

    return words;
}

void InventoryMadnessAdventure::printCommands() {
    printLine();
    cout << "Enter command: add (item); remove (item); list; quit :> ";
}

void InventoryMadnessAdventure::addItem(string item) {
    InventoryItem * tempItem;
    string itemKey = "gem";

    if (item == "sapphire") {
        tempItem = sapphire;
    } else if (item == "ruby") {
        tempItem = ruby;
    } else if (item == "emerald") {
        tempItem = emerald;
    } else {
        tempItem = NULL;
    }

    if (tempItem != NULL && worldInventory->itemIsInInventory(tempItem, itemKey)) {
        worldInventory->remove(tempItem, itemKey);
        player->getInventory()->add(tempItem);
        cout << "\nItem added to the player inventory" << endl;
    } else {
        cout << "\nThis item can not be added to the player inventory" << endl;
    }
}

void InventoryMadnessAdventure::removeItem(string item) {
    InventoryItem * tempItem;
    string itemKey = "gem";

    if (item == "sapphire") {
        tempItem = sapphire;
    } else if (item == "ruby") {
        tempItem = ruby;
    } else if (item == "emerald") {
        tempItem = emerald;
    } else {
        tempItem = NULL;
    }

    if (tempItem != NULL && player->getInventory()->itemIsInInventory(tempItem, itemKey)) {
        player->getInventory()->remove(tempItem, itemKey);
        worldInventory->add(tempItem);
        cout << "\nItem removed from the player inventory" << endl;
    } else {
        cout << "\nThis item can not be removed from the player inventory" << endl;
    }
}

