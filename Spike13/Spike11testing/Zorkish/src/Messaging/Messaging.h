#ifndef ZORKISH_MESSAGING_H
#define ZORKISH_MESSAGING_H

#include <vector>
#include <iostream>
#include "../HasMessaging/HasMessaging.h"

using namespace std;

class Messaging {
    public:
        Messaging();
        Messaging(HasMessaging *player, HasMessaging *locationGraph);
        ~Messaging();

        void reducePlayerEnergy(int value);

    private:
        vector<HasMessaging*> messageObjects;
};


#endif //ZORKISH_MESSAGING_H
