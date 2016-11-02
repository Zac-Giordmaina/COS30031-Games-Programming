#include "Help.h"

Help::Help() {

}

Help::~Help() {

}

void Help::execute() {
    printContent();
    waitForExit();
}

void Help::printContent() {
    cout << "Zorkish :: Help" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "The following commands are supported:"<< endl;
    cout << "quit,"<< endl;
    cout << "hiscore (for testing)"<< endl;
}