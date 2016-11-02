#include "FameHall.h"

FameHall::FameHall() {

}

FameHall::~FameHall() {

}

void FameHall::execute() {
    cout << "Zorkish :: Hall Of Fame" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Top 10 Zorkish Adventure Champions" << endl;
    cout << "1. Fred, Mountain World, 5000" << endl;
    cout << "2. Mary, Mountain World, 4000" << endl;
    cout << "3. Joe, Water World, 3000" << endl;
    cout << "4. Henry, Mountain World, 2000" << endl;
    cout << "5. Susan, Mountain World, 1000" << endl;
    cout << "6. Alfred, Water World, 900" << endl;
    cout << "7. Clark, Mountain World, 800" << endl;
    cout << "8. Harold, Mountain World, 500" << endl;
    cout << "9. Julie, Water World, 3" << endl;

    waitForExit();
}