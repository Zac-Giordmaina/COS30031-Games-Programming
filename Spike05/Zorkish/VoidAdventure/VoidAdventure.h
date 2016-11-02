#ifndef ZORKISH_VOIDADVENTURE_H
#define ZORKISH_VOIDADVENTURE_H

#include "../AdventureState/AdventureState.h"

class VoidAdventure : public AdventureState {
    public:
        VoidAdventure();
        ~VoidAdventure();
        void execute();

    protected:
        void initialiseAdventure();

};


#endif //ZORKISH_VOIDADVENTURE_H
