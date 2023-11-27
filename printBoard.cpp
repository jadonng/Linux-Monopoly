#include <iostream>
#include <sstream>
#include <iomanip>
#include "structures.h"
#include "board.h"

const int BOARD_SIZE = 40;
const int CELL_WIDTH = 25;  // Define a constant for cell width
const std::string LINE = std::string(CELL_WIDTH + 2, '-');
const std::string SPACE = std::string(CELL_WIDTH, ' ');

std::string repeatString(const std::string& str, int times) {
    std::ostringstream os;
    for(int i = 0; i <= times; i++)
        os << str;
    return os.str();
}


void printBoard(Cell Board[]) {
    int side = BOARD_SIZE / 4;

    // Print top row
    for (int i = 0; i <= side; i++) {
        std::cout << LINE;
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "| " << std::setw(CELL_WIDTH - 1) << std::left << Board[i].name << "|";
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "|" << SPACE << "|";
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        if (Board[i].type == 0) {  // If the cell is a Land
            std::cout << "| $" << std::setw(CELL_WIDTH - 2) << Board[i].price << "|";
        } else {
            std::cout << "|" << SPACE << "|";
        }
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << LINE;
    }
    std::cout << std::endl;

    // Print cells from the left and right columns
    for (int i = 1; i < side; i++) {
        // Left column
        std::cout << "| " << std::setw(CELL_WIDTH - 1) << std::left << Board[4*side - i].name << "|" << repeatString(SPACE, 9).substr(0, repeatString(SPACE, 9).size()-7);
        // Right column
        std::cout << "| " << std::setw(CELL_WIDTH - 1) << std::left << Board[side + i].name << "|";
        std::cout << std::endl;
        std::cout << "|" << SPACE << "|" << repeatString(SPACE, 9).substr(0, repeatString(SPACE, 9).size()-7) << "|" << SPACE << "|";
        std::cout << std::endl;
        // Left column
        if (Board[4*side - i].type == 0) {  // If the cell is a Land
            std::cout << "| $" << std::setw(CELL_WIDTH - 2) << Board[4*side - i].price << "|" << repeatString(SPACE, 9).substr(0, repeatString(SPACE, 9).size()-7);
        } else {
            std::cout << "|" << SPACE << "|" << repeatString(SPACE, 9).substr(0, repeatString(SPACE, 9).size()-7);
        }
        // Right column
        if (Board[side + i].type == 0) {  // If the cell is a Land
            std::cout << "| $" << std::setw(CELL_WIDTH - 2) << Board[side + i].price << "|";
        } else {
            std::cout << "|" << SPACE << "|" << SPACE;
        }
        std::cout << std::endl;
        std::cout << LINE << repeatString(SPACE, 9).substr(0, repeatString(SPACE, 9).size()-7) << LINE;
        std::cout << std::endl;
    }

    // Print bottom row
    for (int i = 0; i <= side; i++) {
        std::cout << LINE;
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "| " << std::setw(CELL_WIDTH - 1) << std::left << Board[3*side - i].name << "|";
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << "|" << SPACE << "|";
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        if (Board[3*side - i].type == 0) {  // If the cell is a Land
            std::cout << "| $" << std::setw(CELL_WIDTH - 2) << Board[3*side - i].price << "|";
        } else {
            std::cout << "|" << SPACE << "|";
        }
    }
    std::cout << std::endl;
    for (int i = 0; i <= side; i++) {
        std::cout << LINE;
    }
    std::cout << std::endl;
}
