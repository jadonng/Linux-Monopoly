// printBoard.cpp
#include <iostream>
#include "structures.h"

using namespace std;

void loadBoard(Cell board[40]) {
    // Initialize each cell in the board
    for (int i = 0; i < 40; i++) {
        board[i].ID = i;
        board[i].name = "Cell " + to_string(i);
        board[i].price = -1;
        board[i].rent = -1;
        board[i].owner = "Bank";

        // Set the type of each cell
        if (i == 0) {
            board[i].type = 1;  // Starting Point
        } else if (i == 10 || i == 30) {
            board[i].type = 4;  // Jail/Go to Jail
        } else if (i % 5 == 0) {
            board[i].type = 2;  // Punishment
        } else if (i % 3 == 0) {
            board[i].type = 3;  // Chance
        } else {
            board[i].type = 0;  // Land
            board[i].price = i * 10;  // Set a random price for the land
            board[i].rent = i;  // Set a random rent for the land
        }
    }
}

void printBoard(Cell board[], int size) {
    int side = sqrt(size);

    // Print top border
    for (int i = 0; i < side; i++) {
        cout << "+-----";
    }
    cout << "+" << endl;

    // Print cells from the top row
    for (int i = 0; i < side; i++) {
        cout << "| " << board[i].name;
        if (board[i].type == 0) {  // If the cell is a Land
            cout << " ($" << board[i].price << ")";
        }
    }
    cout << "|" << endl;

    // Print cells from the left and right columns
    for (int i = 1; i < side - 1; i++) {
        cout << "| " << board[size - i].name;
        if (board[size - i].type == 0) {  // If the cell is a Land
            cout << " ($" << board[size - i].price << ")";
        }
        for (int j = 0; j < side - 2; j++) {
            cout << "|     ";
        }
        cout << "| " << board[side + i].name;
        if (board[side + i].type == 0) {  // If the cell is a Land
            cout << " ($" << board[side + i].price << ")";
        }
        cout << "|" << endl;
    }

    // Print cells from the bottom row
    for (int i = 0; i < side; i++) {
        cout << "| " << board[side * 3 - 1 - i].name;
        if (board[side * 3 - 1 - i].type == 0) {  // If the cell is a Land
            cout << " ($" << board[side * 3 - 1 - i].price << ")";
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
    Cell board[40];
    loadBoard(board);
    printBoard(board, 40);
    return 0;
}
