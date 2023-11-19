// printBoard.cpp
#include <iostream>
#include "structures.h"
#include "printBoard.h"

using namespace std;

void loadBoard(Cell Board[40]) {
    // Initialize each cell in the board
    for (int i = 0; i < 40; i++) {
        Board[i].ID = i;
        Board[i].name = "Cell " + to_string(i);
        Board[i].price = -1;
        Board[i].rent = -1;
        Board[i].owner = "Bank";

        // Set the type of each cell
        if (i == 0) {
            Board[i].type = 1;  // Starting Point
        } else if (i == 10 || i == 30) {
            Board[i].type = 4;  // Jail/Go to Jail
        } else if (i % 5 == 0) {
            Board[i].type = 2;  // Punishment
        } else if (i % 3 == 0) {
            Board[i].type = 3;  // Chance
        } else {
            Board[i].type = 0;  // Land
            Board[i].price = i * 10;  // Set a random price for the land
            Board[i].rent = i;  // Set a random rent for the land
        }
    }
}

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

int main() {
    Cell Board[40];
    loadBoard(Board);
    printBoard(Board, 40);
    return 0;
}
