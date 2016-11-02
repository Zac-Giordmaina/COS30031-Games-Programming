#include "State.h"

State::State() {
}

State::~State() {
}

void State::execute() {
}

int State::executeMenu() {
    return 0;
}

void State::printContent() {
    cout << "base" << endl;
}

void State::printConsoleBuffer(){
    cout << "" << endl;
    cout << "" << endl;
}

void State::printLine() {
    cout << "" << endl;
}

void State::waitForExit(){
    bool doNotEscape = true;
    string input;

    int whileCount = 0;

    while (doNotEscape) {
        getline(cin, input);

        if (whileCount == 0) {
            input = "skip";
        }

        if (input == "") {
            doNotEscape = false;
        } else if (input == "skip") {
            whileCount++;
            printLine();
            cout << "Press Enter to return to the Main Menu";
        } else {
            printLine();
            cout << "Press Enter to return to the Main Menu";
        }
    }
}

bool State::validInput(int min, int max, int value) {
    if(value >= min && value <= max) {
        return true;
    } else {
        cout << "Enter a value between " + to_string(min) + " and " + to_string(max) << endl;
        return false;
    }
}
