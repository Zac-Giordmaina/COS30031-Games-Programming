#ifndef ZORKISH_STATE_H
#define ZORKISH_STATE_H

#include <iostream>

using namespace std;

class State {
    public:
        State();
        ~State();
        virtual void execute();
        virtual int executeMenu();

    protected:
        virtual void printContent();
        virtual bool validInput(int min, int max, int value);
        void waitForExit();
        void printConsoleBuffer();

    private:
        void printLine();
};


#endif //ZORKISH_STATE_H
