//
// Created by Zachary Giordmaina on 7/10/2016.
//

#ifndef ZORKISH_SCORE_H
#define ZORKISH_SCORE_H


#include "../HasMessaging/HasMessaging.h"
#include "../Messaging/Messaging.h"

class Score : public HasMessaging {
    public:
        int getScore();
        int getMoves();
        int getTakes();

        void setScore(int value);
        void setMoves(int value);
        void setTakes(int value);

        void moveAnnouncement(int value);
        void addMessenger(Messaging &messenger);
    private:
        int score, moves, takes;
        Messaging * scoreMessenger;
};


#endif //ZORKISH_SCORE_H
