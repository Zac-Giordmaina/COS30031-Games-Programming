#ifndef ZORKISH_ABOUT_H
#define ZORKISH_ABOUT_H


#include "../State/State.h"
#include <iostream>

using namespace std;

class About : public State {
    public:
        About();
        ~About();
        void execute();

    protected:
        void printContent();
};


#endif //ZORKISH_ABOUT_H
