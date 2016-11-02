#ifndef ZORKISH_GAMEMANAGER_H
#define ZORKISH_GAMEMANAGER_H


class GameManager {
    public:
        GameManager();
        ~GameManager();
        bool playGame();
        void quitGame();

    private:
        bool play;

};


#endif //ZORKISH_GAMEMANAGER_H
