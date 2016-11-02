#include "Messaging.h"

Messaging::Messaging() {

}

Messaging::Messaging(HasMessaging *player, HasMessaging *locationGraph) {
    messageObjects.push_back(player);
    messageObjects.push_back(locationGraph);
}

Messaging::~Messaging() {

}

void Messaging::reducePlayerEnergy(int value) {
    messageObjects.at(0)->reducePlayerEnergy(value);
}
