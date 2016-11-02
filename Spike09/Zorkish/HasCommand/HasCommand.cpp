#include "HasCommand.h"

void HasCommand::execute() {
}

InventoryItem HasCommand::execute(string key, string value) {
    return InventoryItem("base", "base");
}

void HasCommand::execute(int i, string value) {
}

bool HasCommand::execute(string value) {
}

void HasCommand::execute(string key, string itemKey, InventoryItem item) {

}

void HasCommand::execute(string key, string item, string itemKey) {

}
