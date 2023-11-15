//printBoard.h

#include <vector>
#include <string>

using namespace std;

struct Cell {
    string name;
    int price;
};

class Board {
public:
    vector<Cell> cells;

    // Constructor
    Board(vector<Cell> cells) : cells(cells) {}

    // Method to print the board
    void printBoard();
};
