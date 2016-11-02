#include "Elixir.h"

Elixir::Elixir() {
    elixirName = "null";
}

Elixir::Elixir(string type, string name, string description) {
    elixirType = type;
    elixirName = name;
    elixirDescription = description;
}

Elixir::~Elixir() {

}

void Elixir::executePower(string item) {
    cout << "The " + item + " was destroyed!" << endl;
}

int Elixir::consumePower() {
    int energy;

    energy = rand() % 50 + 20;

    return energy;
}

string Elixir::getType() {
    return elixirType;
}

string Elixir::getName() {
    return elixirName;
}

string Elixir::getDescription(){
    return elixirDescription;
}

void Elixir::printPower() {
    if (elixirType == "destroy") {
        cout << "\nYou can now destroy items; destroy (item)" << endl;
    }
}
