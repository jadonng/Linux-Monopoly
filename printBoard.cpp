//printBoard.cpp

#include <iostream>
#include "printBoard.h"

using namespace std;

void Board::printBoard() {
    int size = cells.size();
    int side = size / 4;

    // Print the top row
    for (int i = 0; i < side; i++) {
        cout << "-------------------------\n";
        cout << "Name: " << cells[i].name << "\n";
        cout << "Price: " << cells[i].price << "\n";
    }
    cout << "-------------------------\n";

    // Print the middle rows
    for (int i = 1; i < side - 1; i++) {
        cout << "-------------------------\n";
        cout << "Name: " << cells[size - i].name << "\n";
        cout << "Price: " << cells[size - i].price << "\n";
        for (int j = 0; j < side - 2; j++) {
            cout << "                         \n";
        }
        cout << "-------------------------\n";
        cout << "Name: " << cells[i + side].name << "\n";
        cout << "Price: " << cells[i + side].price << "\n";
        cout << "-------------------------\n";
    }

    // Print the bottom row
    for (int i = 3 * side; i < size; i++) {
        cout << "-------------------------\n";
        cout << "Name: " << cells[i].name << "\n";
        cout << "Price: " << cells[i].price << "\n";
    }
    cout << "-------------------------\n";
}
