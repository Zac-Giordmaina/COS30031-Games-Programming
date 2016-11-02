//
// Created by Zachary Giordmaina on 7/10/2016.
//

#include "Score.h"

int Score::getScore() {
    return score;
}

int Score::getMoves() {
    return moves;
}

int Score::getTakes() {
    setTakes(scoreMessenger->viewTakeBlackboard());
    return takes;
}

void Score::setScore(int value) {
    score += value;
}

void Score::setMoves(int value) {
    moves += value;
}

void Score::setTakes(int value) {
    takes += value;
}

void Score::moveAnnouncement(int value) {
    setMoves(-value / 20);
    setScore(-value * 25);
}

void Score::addMessenger(Messaging &messenger) {
    scoreMessenger = &messenger;
}
