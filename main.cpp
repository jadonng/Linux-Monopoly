//main.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "printBoard.h"
#include "board.h"
#include "checkstatus.h"
#include "wincheck.h"
#include "structures.h"
#include "action.h"
using namespace std;

void actionBeforeRoll(Player cur_player, Cell Board[], int &dice1, int &dice2);
void actionAfterRoll(Player &cur_player, Cell Board[], int type);

int main() {
    // Variables
    int cur_round;
    Player cur_player;
    int num_player;
    int rounds;
    double initial_cash;
    const int startpoint_cash = 200;
    bool game_end = false;
    
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
    cout << "\nNumber of rounds for each player(must be an integer): ";
    cin >> rounds;
    cout << "\nInitial Cash (must be positive): ";
    cin >> initial_cash;
    cout << "\nNumber of Players (2-4): ";
    cin >> num_player;
    cin.ignore();


    // Load players

    //char number, string name, Cell *pos, int money, vector<int> land_list, int num_card, bool in_jail = false, bool can_buy_land_or_properties
    // Dynamic Memory Management
    Player * player_array = new Player [num_player];
    for (int i = 0; i < num_player; i++) {
        // ask user to enter their names
        string name;
        cout << "\nPlayer " << i << " name: (between 2-20 characters): ";
        getline(cin, name);

        vector<int> * land_vec = new vector<int>;
        Player * new_player = new Player { i, name, &Board[0], initial_cash, *land_vec, 0, false, false};
        player_array[i] = *new_player;
        delete land_vec;
        delete new_player;
    }
    cout << "\n";

    // Main Loop
    for (cur_round = 0; cur_round < rounds * num_player; cur_round++) {


        // printBoard(Board);

        // Lock in current player
        cur_player = player_array[cur_round%num_player];

        // if current player is in jail, skip his round and change in_jail to false so he can move next round
        if (cur_player.in_jail == true) {
            cout << ">> Player " << cur_player.name << " is currently in jail, round skipped." << endl;
            TriggerEvent(cur_player, Board, player_array, num_player);
            actionAfterRoll(cur_player, Board, cur_player.pos->type);
            player_array[cur_round%num_player] = cur_player;
            continue;
        }
        // skip player round if they are broke
        if (brokecheck(cur_player)) {
            cout << ">> Player " << cur_player.name << " is already broke." << endl;
            continue;
        }

        cout << ">> Player " << cur_player.name << "'s turn!" << endl;

        // Player first action
        int dice1, dice2;
        actionBeforeRoll(cur_player, Board, dice1, dice2);

        // Move the player
        if (cur_player.pos->ID + dice1 + dice2 < board_size) {
            cur_player.pos = &Board[cur_player.pos->ID + dice1 + dice2];
        }
        else {
            cur_player.pos = &Board[cur_player.pos->ID + dice1 + dice2 - board_size];
            cur_player.money += startpoint_cash;
            cout << ">> " << cur_player.name << " passed starting point, recieved $200." << endl;
        }
        
        // Triggerevent in structures.h
        TriggerEvent(cur_player, Board, player_array, num_player);

        // After correspinding events are triggered, allow user to pick their actions
        actionAfterRoll(cur_player, Board, cur_player.pos->type);

        // Check if anyone is broke or satistfy winning conditions
        int broke_count = 0;
        for (int i = 0; i < num_player; i++) {
            if (player_array[i].money < 0) {
                broke_count++;
            }
        }
        if (broke_count == num_player - 1) {
            for (int i = 0; i < num_player; i++) {
                if (player_array[i].money > 0) {
                    cout << ">> Everyone else is broke, " << player_array[i].name << " has won!" << endl;
                    game_end = true;
                    break;
                }
            }
        }

        if (game_end) {
            break;
        }

        player_array[cur_round%num_player] = cur_player;
        
    }
    outloop_wincheck(player_array, num_player);
    // Delete array memory 
    delete [] player_array;

}



// Functions

// Player first round of action - basically allow player to roll dice
void actionBeforeRoll(Player cur_player, Cell Board[], int &dice1, int &dice2) {
    string choice;
    cout << "Press the respective hotkey to choose your next action." << endl;
    cout << "1: Roll dice" << endl;
    cout << "2: Check game status" << endl;
    getline(cin, choice);

    while (!(choice == "1" || choice == "2")) {
        cout << ">> Invalid choice, please choose again." << endl;
        return actionBeforeRoll(cur_player, Board, dice1, dice2);
    }

    switch (stoi(choice)) {
        case 1: // Roll dice
            srand(time(NULL));
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            cout << ">> You rolled " << dice1 + dice2 << "!" << endl;
            break;

        case 2: // Check Status
            checkstatus(cur_player,Board);
            return actionBeforeRoll(cur_player, Board, dice1, dice2);
            break;
    }   
}

// Player second round of action - the function will perform different things based on the type of cell player landed on
void actionAfterRoll(Player &cur_player, Cell Board[], int type) {

    if (type == 0 && cur_player.can_buy_land_or_properties == false) {
        return actionAfterRoll(cur_player, Board, 10); // simply end round
    }

    string choice;

    cout << "\nPress the respective hotkey to choose your next action." << endl;
    // Land
    if (type == 0) {
        // Land on land that no one owns
        if (cur_player.pos->owner == "Bank") {
            cout << "1: Buy land" << endl;
            cout << "2: Check game status" << endl;
            cout << "3: End Round" << endl;
            getline(cin, choice);
            while (!(choice == "1" || choice == "2" || choice == "3")) {
                cout << ">> Invalid choice, please choose again." << endl;
                return actionAfterRoll(cur_player, Board, type);
            }
            // Handle user valid choice
            switch (stoi(choice)) {
                case 1: 
                    buy(Board, cur_player);
                    return actionAfterRoll(cur_player, Board, type);
                    break;
                case 2:
                    checkstatus(cur_player, Board);
                    return actionAfterRoll(cur_player, Board, type);
                    break;
                case 3:
                    cout << ">> " << cur_player.name << "'s round ended." << endl;
                    break;
            }
        }
        // Land on own land
        else if (cur_player.pos->owner == cur_player.name) {
            cout << "1: Build property" << endl;
            cout << "2: Check game status" << endl;
            cout << "3: End Round" << endl;
            getline(cin, choice);
            while (!(choice == "1" || choice == "2" || choice == "3")) {
                cout << ">> Invalid choice, please choose again." << endl;
                return actionAfterRoll(cur_player, Board, type);
            }
            // Handle user valid choice
            switch (stoi(choice)) {
                case 1:   
                    buildproperty(Board,cur_player);
                    return actionAfterRoll(cur_player, Board, type);
                    break;
                case 2:
                    checkstatus(cur_player, Board);
                    return actionAfterRoll(cur_player, Board, type);
                    break;
                case 3:
                    cout << ">> " << cur_player.name << "'s round ended." << endl;
                    break;
            }
        }
        
        // Turn the bool off
        cur_player.can_buy_land_or_properties = false;
        
    }
    // To jail
    else if (type == 5) { 
        cout << "1: Use get out of jail card" << endl;
        cout << "2: Go to jail" << endl;
        getline(cin, choice);
        while (!(choice == "1" || choice == "2")) {
            cout << ">> Invalid choice, please choose again." << endl;
            return actionAfterRoll(cur_player, Board, type);
        }
        // Handle user valid choice
        switch (stoi(choice)) {
            case 1:
                cout << ">> You have used one get out of jail card." << endl;
                cur_player.num_card -= 1;
                break;
            case 2:
                cout << ">> You are in jail now, rest for one turn." << endl;
                cur_player.pos = &Board[20];
                break;
        }   
    }
    // Chance, Punishment and Jail <- these will be handled by TriggerEvent()
    else {
        // if they are in jail already, skip action 2
        if (cur_player.in_jail == false) {
            cout << "1: Check game status" << endl;
            cout << "2: End Round" << endl;
            getline(cin, choice);
            while (!(choice == "1" || choice == "2")) {
                cout << ">> Invalid choice, please choose again." << endl;
                return actionAfterRoll(cur_player, Board, type);
            }
            // Handle user valid choice
            switch (stoi(choice)) {
                case 1:
                    checkstatus(cur_player, Board);
                    return actionAfterRoll(cur_player, Board, type);
                    break;
                    
                case 2:
                    cout << ">> " << cur_player.name << "'s round ended." << endl;
                    break;
            }   
        }
        
    }
}
