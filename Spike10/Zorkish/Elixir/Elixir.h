#ifndef ZORKISH_ELIXIR_H
#define ZORKISH_ELIXIR_H

#include <iostream>

using namespace std;

class Elixir {
    private:
        string elixirType;
        string elixirName;
        string elixirDescription;

    public:
        Elixir();
        Elixir(string type, string name, string description);
        ~Elixir();

        void executePower(string item);
        int consumePower();

        string getType();
        string getName();
        string getDescription();
        void printPower();
};


#endif //ZORKISH_ELIXIR_H
