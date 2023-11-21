//board.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "structures.h"
#include "board.h"
using namespace std;

void loadBoard(Cell Board[40]){

    //This function intakes board.txt
    //This function set the fundamental board for the game to take place

    ifstream fin;
    fin.open("board.txt");
    if ( fin.fail() ){
        cout << ">>Error in file opening!" << endl;
        exit(1);
    }
    for (int i=0; i<40; i++){
        fin >> Board[i].type >> Board[i].name >> Board[i].price >> Board[i].rent;
        Board[i].owner = "Bank";
        Board[i].ID=i;
        Board[i].property=0;
    }
    fin.close();

    //This function returns no output

}
