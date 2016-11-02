#include "Messaging.h"

Messaging::Messaging() {

}

Messaging::Messaging(HasMessaging *player, HasMessaging *locationGraph, HasMessaging *score) {
    messageObjects.push_back(player);
    messageObjects.push_back(locationGraph);

    moveAnnouncementObjects.push_back(player);
    moveAnnouncementObjects.push_back(score);
}

Messaging::~Messaging() {

}

void Messaging::reducePlayerEnergy(int value) {
    messageObjects.at(0)->reducePlayerEnergy(value);
}

void Messaging::announceMove(int value) {
    for (int i = 0; i < moveAnnouncementObjects.size(); i++) {
        moveAnnouncementObjects.at(i)->moveAnnouncement(value);
    }
}

void Messaging::addToTakeBlackboard() {
    takeBlackboard++;
}

int Messaging::viewTakeBlackboard() {
    int tempTakeBlackboard = takeBlackboard;
    takeBlackboard = 0;
    return tempTakeBlackboard;
}
