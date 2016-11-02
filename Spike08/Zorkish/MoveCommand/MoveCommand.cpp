#include "MoveCommand.h"

void MoveCommand::execute(string userInput, LocationGraph * locationGraph) {
    locationGraph->attemptMove(userInput);
}