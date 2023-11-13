//board.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "board.h"
using namespace std;

void loadBoard(Cell Board[40]){
    ifstream fin;
    fin.open("board.txt");
    if ( fin.fail() ){
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    for (int i=0; i<40; i++){
        fin >> Board[i].type >> Board[i].name >> Board[i].price >> Board[i].rent;
        Board[i].owner = "Bank";
    }
    fin.close();
}