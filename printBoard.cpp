#include <iostream>
#include <cmath>
#include <iomanip>
#include "printtBoard.h"
#include "structures.h"
#include "board.h"

const int BOARD_SIZE = 40;
const int CELL_WIDTH = 25;  // Define a constant for cell width

void printBoard(Cell Board[]) {
    int side = BOARD_SIZE / 4;

    // Print top row
    for (int i = 0; i <= side; i++) {
        std::cout << "--------------------------";
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "| " << std::setw(CELL_WIDTH) << std::left << Board[i].name;
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "|                         ";
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i <= side; i++) {
        if (Board[i].type == 0) {  // If the cell is a Land
            std::cout << "| $" << std::setw(CELL_WIDTH) << Board[i].price;
        } else {
            std::cout << "|                         ";
        }
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "--------------------------";
    }
    std::cout << std::endl;

    // Print cells from the left and right columns
    for (int i = 1; i <= side; i++) {
    // Left column
    	std::cout << "| " << std::setw(CELL_WIDTH) << std::left << Board[3*side - i].name;
    	for (int j = 0; j < side - 2; j++) {
        	std::cout << std::setw(CELL_WIDTH) << " ";	
    }
    	std::cout << "| " << std::setw(CELL_WIDTH) << std::left << Board[side + i].name;

    	std::cout << "|" << std::endl;
    	std::cout << "|                         ";
    	std::cout << "|" << std::endl;
    	if (Board[3*side - i].type == 0) {  // If the cell is a Land
        	std::cout << "| $" << std::setw(CELL_WIDTH) << Board[3*side - i].price;
    } else {
        std::cout << "|                         ";
    }
	for (int j = 0; j < side - 2; j++) {
        	std::cout << std::setw(CELL_WIDTH) << " ";	
    }
    	// std::cout << "|" << std::endl;
    	if (Board[side + i].type == 0) {  // If the cell is a Land
        	std::cout << "| $" << std::setw(CELL_WIDTH) << Board[side + i].price;
    } else {
        std::cout << "|                         ";
    }
    std::cout << "|" << std::endl;
}

        
    // Print bottom row
    for (int i = 0; i <= side; i++) {
        std::cout << "--------------------------";
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "| " << std::setw(CELL_WIDTH) << std::left << Board[2*side + i].name;
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "|                         ";
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i <= side; i++) {
        if (Board[2*side + i].type == 0) {  // If the cell is a Land
            std::cout << "| $" << std::setw(CELL_WIDTH) << Board[2*side + i].price;
        } else {
            std::cout << "|                         ";
        }
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "--------------------------";
    }
    std::cout << std::endl;
}
