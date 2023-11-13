// board.h
#ifndef BOARD_H
#define BOARD_H

#include <string>

using namespace std;

struct Cell{
    int ID;         //Location(0-39)
    int type;       //(0 = Land, 1 = Starting Point, 2 = Punishment, 3 = Chance, 4 = Jail, 5 = Go to Jail, 6 = NULL)
    string name; 
    int price;      // -1 if not Land
    int rent;       // -1 if not land
    string owner;   // Normalized to Bank Owned
};

void loadBoard(Cell Board[40]);

#endif
