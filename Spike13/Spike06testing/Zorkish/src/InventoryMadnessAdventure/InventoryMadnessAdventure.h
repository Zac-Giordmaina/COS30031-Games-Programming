#ifndef ZORKISH_INVENTORYMADNESSADVENTURE_H
#define ZORKISH_INVENTORYMADNESSADVENTURE_H

#include <vector>
#include <sstream>

#include "../AdventureState/AdventureState.h"
#include "../Inventory/Inventory.h"
#include "../Gem/Gem.h"
#include "../Player/Player.h"

class InventoryMadnessAdventure : public AdventureState {
    public:
        InventoryMadnessAdventure();
        ~InventoryMadnessAdventure();
        void execute();

    protected:
        void initialiseAdventure();
        void printContent();
        void printCommands();
        void listenForInput();
        void addItem(string item);
        void removeItem(string item);

    private:
        Player * player;
        Inventory * worldInventory;
        Gem * sapphire;
        Gem * ruby;
        Gem * emerald;

        enum commands {
            add,
            remove,
            list,
            quit,
            invalid
        };

        commands validateCommand(string userInput);
        vector<string> splitSentence(string userInput);
};


#endif //ZORKISH_INVENTORYMADNESSADVENTURE_H
