#include "GameManager.h"

GameManager::GameManager() {
    play = true;
}

GameManager::~GameManager() {
}

bool GameManager::playGame() {
    return play;
}

void GameManager::quitGame() {
    play = false;
}
