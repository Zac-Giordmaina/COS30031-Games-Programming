#include "About.h"

About::About() {

}

About::~About() {

}

void About::execute() {
    printContent();
    waitForExit();
}

void About::printContent() {
    cout << "ZorkishApp :: About" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Written by: Zachary Giordmaina" << endl;
}