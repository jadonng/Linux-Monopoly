//main.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "printBoard.h"
#include "action.h"
#include "wincheck.h"
#include "checkstatus.h"
#include "structures.h"
using namespace std;

void roll_dice(int &dice);

void actionBeforeRoll(Player cur_player, Cell Board[], int &dice);
void actionAfterRoll(Player cur_player, Cell Board[], int type);

int main() {
    // Variables
    int cur_round;
    Player cur_player;

    int rounds;
    double initial_cash;
    string p1_name, p2_name;
    const int startpoint_cash = 200;

    // Load Board
    const int board_size = 40;
    Cell Board[board_size];
    loadBoard(Board);

    // Configurations
    cout << "*************************************" << endl;
    cout << "* Welcome to Monopoly (HKU Edition) *" << endl;
    cout << "*************************************" << endl;
    cout << "\nPlease fill in the following configurations to start the game." << endl;
    // add some defensive programming later
    cout << "\nNumber of rounds (must be an integer >= 20): ";
    cin >> rounds;
    cout << "\nInitial Cash (must be positive): ";
    cin >> initial_cash;
    cout << "\nFirst player's name: (between 2-20 characters): ";
    getline(cin, p1_name);
    cout << "\nSecond player's name: (between 2-20 characters): ";
    getline(cin, p2_name);

    // Can consider allow user to input how many players are there
    // Load players
    int num_player = 2;
    vector<int> vec1, vec2;
    Player p1 = { 0, p1_name, &Board[0], initial_cash, vec1};
    Player p2 = { 1, p2_name, &Board[0], initial_cash, vec2};
    Player player_array[] = { p1, p2 };

    //printboard()
    
    for (cur_round = 0; cur_round < rounds; cur_round++) {
        if (cur_round % 2 == 0) {
            // Player A turn
            cur_player = p1;
        }
        else {
            // Player B turn
            cur_player = p2;
        }
        cout << "Player " << cur_player.name << "'s turn!" << endl;
        // Player first action
        int dice;
        actionBeforeRoll(cur_player, Board, dice);

        // Move the player
        if (cur_player.pos->ID + dice < board_size) {
            cur_player.pos = &Board[cur_player.pos->ID + dice];
        }
        else {
            cur_player.pos = &Board[cur_player.pos->ID + dice - board_size];
            cur_player.money += startpoint_cash;
            cout << cur_player.name << " passed starting point, recieved $200." << endl;
        }
        
        cur_player.pos->TriggerEvent(cur_player, Board);

        actionAfterRoll(cur_player, Board, cur_player.pos->type);

        wincheck(p1, p2);

    }


    
}

// Player first round of action
void actionBeforeRoll(Player cur_player, Cell Board[], int &dice) {
    string choice;
    cout << "Press the respective hotkey to choose your next action." << endl;
    cout << "1: Roll dice" << endl;
    cout << "2: Check game status" << endl;
    getline(cin, choice);

    while (choice != "1" || choice != "2") {
        cout << "Invalid choice, please choose again." << endl;
        actionBeforeRoll(cur_player, Board, dice);
    }

    switch (stoi(choice)) {
        case 1: // Roll dice
            srand(time(NULL));
            dice = rand() % 6 + 1;
            cout << "You rolled " << dice << "!" << endl;
            break;

        case 2: // Check Status
            checkstatus(cur_player,Board);
            actionBeforeRoll(cur_player, Board, dice);
            break;
    }   
}

// Player second round of action
void actionAfterRoll(Player cur_player, Cell Board[], int type) {
    string choice;
    cout << "Press the respective hotkey to choose your next action." << endl;
    // Land
    if (type == 0) {
        cout << "1: Buy land" << endl;
        cout << "2: Build property" << endl;
        cout << "3: Check game status" << endl;
        cout << "4: End Round" << endl;
        getline(cin, choice);
        while (choice != "1" || choice != "2" || choice != "3" || choice != "4") {
            cout << "Invalid choice, please choose again." << endl;
            actionAfterRoll(cur_player, Board, type);
        }
        // Handle user valid choice
        switch (stoi(choice)) {
            case 1: 
                buy(Board, cur_player);
                actionAfterRoll(cur_player, Board, type);
            case 2:   
                buildproperty();
                actionAfterRoll(cur_player, Board, type);
            case 3:
                checkstatus(cur_player, Board);
                actionAfterRoll(cur_player, Board, type);
            case 4:
                cout << cur_player.name << "'s round ended." << endl;
                break;
        }
    }
    // To jail
    else if (type == 5) { 
        cout << "1: Use get out of jail card" << endl;
        cout << "2: Check game status" << endl;
        cout << "3: End Round" << endl;
        getline(cin, choice);
        while (choice != "1" || choice != "2" || choice != "3") {
            cout << "Invalid choice, please choose again." << endl;
            actionAfterRoll(cur_player, Board, type);
        }
        // Handle user valid choice
        switch (stoi(choice)) {
            case 1:
                if (cur_player.has_card) {
                    cout << "You have used one get out of jail card." << endl;
                }
                else {
                    cout << "You do not own any jail card." << endl;
                }
                actionAfterRoll(cur_player, Board, 10); //so do not reloop back to 'to jail' choices
            case 2:
                checkstatus(cur_player, Board);
                actionAfterRoll(cur_player, Board, type);
            case 3:
                cout << cur_player.name << "'s round ended." << endl;
                break;
        }   
    }
    // Chance, Punishment and Jail <- these will be handled by TriggerEvent()
    else {
        cout << "1: Check game status" << endl;
        cout << "2: End Round" << endl;
        getline(cin, choice);
        while (choice != "1" || choice != "2") {
            cout << "Invalid choice, please choose again." << endl;
            actionAfterRoll(cur_player, Board, type);
        }
        // Handle user valid choice
        switch (stoi(choice)) {
            case 1:
                checkstatus(cur_player, Board);
                actionAfterRoll(cur_player, Board, type);
                
            case 2:
                cout << cur_player.name << "'s round ended." << endl;
                break;
        }   
    }
    
}
