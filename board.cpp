//board.cpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Cell{
    int type; //(0 = Land, 1 = Starting Point, 2 = Punishment, 3 = Chance, 4 = Jail, 5 = Go to Jail, 6 = NULL)
    string name; 
    int price; // -1 if not Land
    int rent; // -1 if not land
    string owner; // Normalized to Bank Owned
};

Cell Board[40];

void loadBoard(){
    ifstream fin;
    fin.open("board.txt");
    for (int i=0; i<40; i++){
        fin >> Board[i].type >> Board[i].name >> Board[i].price >> Board[i].rent;
        Board[i].owner = "Bank";
    }
    fin.close();
}