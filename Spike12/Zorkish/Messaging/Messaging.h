#ifndef ZORKISH_MESSAGING_H
#define ZORKISH_MESSAGING_H

#include <vector>
#include <iostream>
#include "../HasMessaging/HasMessaging.h"

using namespace std;

class Messaging {
    public:
        Messaging();
        Messaging(HasMessaging *player, HasMessaging *locationGraph, HasMessaging *score);
        ~Messaging();

        void reducePlayerEnergy(int value);
        void announceMove(int value);
        void addToTakeBlackboard();
        int viewTakeBlackboard();

    private:
        vector<HasMessaging*> messageObjects;
        vector<HasMessaging*> moveAnnouncementObjects;
        int takeBlackboard = 0;
};


#endif //ZORKISH_MESSAGING_H
