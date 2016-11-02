#ifndef ZORKISH_FAMEHALL_H
#define ZORKISH_FAMEHALL_H


#include "../State/State.h"
#include <iostream>

using namespace std;

class FameHall : public State {
public:
    FameHall();
    ~FameHall();
    void execute();
};

#endif //ZORKISH_FAMEHALL_H
