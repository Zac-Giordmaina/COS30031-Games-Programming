#ifndef GRIDWORLDEXTENSION_PLAYER_H
#define GRIDWORLDEXTENSION_PLAYER_H

#include <iostream>

using namespace std;

class Player {
    public:
        int getCurrentYPosition();
        int getCurrentXPosition();
        int getPreviousYPosition();
        int getPreviousXPosition();
        void setCurrentYPosition(int positionValue);
        void setCurrentXPosition(int positionValue);
        void setPlayerCurrentPosition(int y, int x);
        void setPlayerPreviousPosition();

    private:
        int playerPreviousPosition[2];
        int playerCurrentPosition[2];
};


#endif //GRIDWORLDEXTENSION_PLAYER_H
