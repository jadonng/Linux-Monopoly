// printBoard.cpp
#include <iostream>
#include "structures.h"
#include "printBoard.h"
#include "board.h"

using namespace std;

void printBoard(Cell Board[], int size) {
    int side = sqrt(size);

    // Print top border
    for (int i = 0; i < side; i++) {
        cout << "+-----";
    }
    cout << "+" << endl;

    // Print cells from the top row
    for (int i = 0; i < side; i++) {
        cout << "| " << Board[i].name;
        if (Board[i].type == 0) {  // If the cell is a Land
            cout << " ($" << Board[i].price << ")";
        }
    }
    cout << "|" << endl;

    // Print cells from the left and right columns
    for (int i = 1; i < side - 1; i++) {
        cout << "| " << Board[size - i].name;
        if (Board[size - i].type == 0) {  // If the cell is a Land
            cout << " ($" << Board[size - i].price << ")";
        }
        for (int j = 0; j < side - 2; j++) {
            cout << "|     ";
        }
        cout << "| " << Board[side + i].name;
        if (Board[side + i].type == 0) {  // If the cell is a Land
            cout << " ($" << Board[side + i].price << ")";
        }
        cout << "|" << endl;
    }

    // Print cells from the bottom row
    for (int i = 0; i < side; i++) {
        cout << "| " << Board[side * 3 - 1 - i].name;
        if (Board[side * 3 - 1 - i].type == 0) {  // If the cell is a Land
            cout << " ($" << Board[side * 3 - 1 - i].price << ")";
        }
    }
    cout << "|" << endl;

    // Print bottom border
    for (int i = 0; i < side; i++) {
        cout << "+-----";
    }
    cout << "+" << endl;
}
