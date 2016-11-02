#ifndef ZORKISH_MAINMENU_H
#define ZORKISH_MAINMENU_H

#include <iostream>
#include "../State/State.h"

using namespace std;

class MainMenu : public State {
    public:
        MainMenu();
        ~MainMenu();
        int executeMenu();

    protected:
        void printContent();
};


#endif //ZORKISH_MAINMENU_H
