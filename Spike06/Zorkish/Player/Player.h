#ifndef ZORKISH_PLAYER_H
#define ZORKISH_PLAYER_H


#include "../Inventory/Inventory.h"

class Player {
    public:
        Player();
        ~Player();

        Inventory * getInventory();
        void setInventory(Inventory *inventory);

    private:
        Inventory * playerInventory;
};


#endif //ZORKISH_PLAYER_H
