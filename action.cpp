//action.cpp
#include <iostream>
#include <string>
#include "board.h"
#include "player.h"

void buy(Cell Board[40], string Player){
    if (Board[Player.location].type == 0){
        if (Board[Player.location].owner == "Bank"){
            if (Player.money >= Board[Player.location].price){
                Player.money -= Board[Player.location].price;
                Board[Player.location].owner = Player.name;
                cout << "You have bought " << Board[Player.location].name << " for " << Board[Player.location].price << endl;
            }
            else{
                cout << "You do not have enough money to buy " << Board[Player.location].name << endl;
            }
        }
        else{
            cout << Board[Player.location].name << " is already owned by " << Board[Player.location].owner << endl;
        }
    }
    else{
        cout << Board[Player.location].name << " is not a land, you cannot buy it" << endl;
    }
}