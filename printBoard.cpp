#include <iostream>
#include <cmath>
#include "printBoard.h"
#include "structures.h"
#include "board.h"

const int BOARD_SIZE = 40;

void printBoard(Cell Board[]) {
    int side = BOARD_SIZE / 4;

    // Print top row
    for (int i = 0; i < side; i++) {
        std::cout << "| " << Board[i].name;
        if (Board[i].type == 0) {  // If the cell is a Land
            std::cout << " ($" << Board[i].price << ")";
        }
    }
    std::cout << "|" << std::endl;

    // Print cells from the left and right columns
    for (int i = 1; i < side - 1; i++) {
        std::cout << "| " << Board[BOARD_SIZE - i].name;
        if (Board[BOARD_SIZE - i].type == 0) {  // If the cell is a Land
            std::cout << " ($" << Board[BOARD_SIZE - i].price << ")";
        }
        for (int j = 0; j < side - 2; j++) {
            std::cout << "|     ";
        }
        std::cout << "| " << Board[side + i].name;
        if (Board[side + i].type == 0) {  // If the cell is a Land
            std::cout << " ($" << Board[side + i].price << ")";
        }
        std::cout << "|" << std::endl;
    }

    // Print bottom row
    for (int i = 0; i < side; i++) {
        std::cout << "| " << Board[2*side + i].name;
        if (Board[2*side + i].type == 0) {  // If the cell is a Land
            std::cout << " ($" << Board[2*side + i].price << ")";
        }
    }
    std::cout << "|" << std::endl;
}
