#include <iostream>
#include <cmath>
#include "printBoard.h"
#include "structures.h"
#include "board.h"

const int BOARD_SIZE = 40;

void loadBoard(Cell Board[BOARD_SIZE]) {
    srand(time(0));  // Initialize random seed

    // Array of cell names
    std::string cellNames[BOARD_SIZE] = {
        "Go", "Graduate_House", "Chance", "KK_Leung", "Income_Tax", "MTR_Exit_A1", "Meng_Wah_Complex", "Chance", "Hawking_Wong_Building", "Run_Run_Shaw_Building",
        "Jail", "Main_Library", "Swire_Canteen", "Knowles_Building", "Library_Extension", "MTR_Exit_A2", "Chong_Yuet_Ming", "Chance", "T.T.Tsui_Building", "Kadoorie_Building",
        "Jail", "Main_Building", "Chance", "Composite_Building", "Run_Run_Shaw_Tower", "MTR_EXIT_B", "The_Jockey_Club_Tower", "Cheng_Yu_Tung_Building", "SU_Canteen", "Eilot Hall",
        "Go_To_Jail", "Libaray_Extension", "May_Hall", "Chance", "Central_Podium_Levels", "MTR_Exit_C", "Chance", "Med_Campus", "Luxury_Tax", "Dental_Campus"
    };

    for (int i = 0; i < BOARD_SIZE; i++) {
        Board[i].ID = i;
        Board[i].name = cellNames[i];  // Set the name from the cellNames array
    }
}
void printBoard(Cell Board[BOARD_SIZE]) {
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
