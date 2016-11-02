#include "MainMenu.h"

MainMenu::MainMenu() {

}

MainMenu::~MainMenu() {

}

int MainMenu::executeMenu() {
    int min = 1;
    int max = 5;
    int stateIndex;

    do {
    printConsoleBuffer();
    printContent();
    cin >> stateIndex;
    printConsoleBuffer();
    } while (!validInput(min, max, stateIndex));

    return stateIndex;
}

void MainMenu::printContent() {
    cout << "ZorkishApp :: Main Menu" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Welcome to ZorkishApp Adventures" << endl;
    cout << "1. Select Adventure and Play" << endl;
    cout << "2. Hall Of Fame" << endl;
    cout << "3. Help" << endl;
    cout << "4. About" << endl;
    cout << "5. Quit" << endl;
    cout << "Select 1-5:> ";
}


