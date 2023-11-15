//action.cpp
#include <iostream>
#include <string>
#include "board.h"
#include "players.h"

void buy(Cell Board[40], Player player){
    int position = player.pos->ID;
    if (Board[position].type == 0){
        if (Board[position].owner == "Bank"){
            if (player.money >= Board[position].price){
                player.money -= Board[position].price;
                Board[position].owner = player.number;
                cout << "You have bought " << Board[position].name << " for " << Board[position].price << endl;
            }
            else{
                cout << "You do not have enough money to buy " << Board[position].name << endl;
            }
        }
        else{
            cout << Board[position].name << " is already owned by " << Board[position].owner << endl;
        }
    }
    else{
        cout << Board[position].name << " is not a land, you cannot buy it" << endl;
    }
}