#include "Player.h"

int Player::getCurrentYPosition() {
    return playerCurrentPosition[0];
}

int Player::getCurrentXPosition() {
    return playerCurrentPosition[1];
}

int Player::getPreviousYPosition() {
    return playerPreviousPosition[0];
}

int Player::getPreviousXPosition() {
    return playerPreviousPosition[1];
}

void Player::setCurrentYPosition(int positionValue) {
    playerCurrentPosition[0] = playerCurrentPosition[0] + positionValue;
}

void Player::setCurrentXPosition(int positionValue) {
    playerCurrentPosition[1] = playerCurrentPosition[1] + positionValue;
}

void Player::setPlayerCurrentPosition(int y, int x) {
    playerCurrentPosition[0] = y;
    playerCurrentPosition[1] = x;
}

void Player::setPlayerPreviousPosition() {
    playerPreviousPosition[0] = playerCurrentPosition[0];
    playerPreviousPosition[1] = playerCurrentPosition[1];
}