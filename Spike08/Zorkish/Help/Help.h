#ifndef ZORKISH_HELP_H
#define ZORKISH_HELP_H


#include "../State/State.h"
#include <iostream>

using namespace std;

class Help : public State {
    public:
        Help();
        ~Help();
        void execute();

    protected:
        void printContent();
};


#endif //ZORKISH_HELP_H
