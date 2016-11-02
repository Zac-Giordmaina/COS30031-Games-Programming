#ifndef ZORKISH_HASCOMMAND_H
#define ZORKISH_HASCOMMAND_H

#include <iostream>
#include "../InventoryItem/InventoryItem.h"
#include "../Elixir/Elixir.h"

using namespace std;

class HasCommand {
    public:
        virtual void execute();
        virtual InventoryItem execute(string key, string value);
        virtual void execute(int i, string value);
        virtual bool execute(string value);
        virtual Elixir executeConsume(string value);
        virtual void executeConsume(Elixir elixir);
        virtual void execute(string key, string itemKey, InventoryItem item);
        virtual void execute(string key, string item, string itemKey);
};


#endif //ZORKISH_HASCOMMAND_H
