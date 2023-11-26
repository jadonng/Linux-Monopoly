//action.cpp
#include <iostream>
#include <string>
#include "structures.h"
#include "action.h"
#include <cmath>

using namespace std;
void buy(Cell Board[], Player &player){

    //The buy function intakes the Board of the game of the Player
    //When being called, the ownership status of the cell will be changed
    //The player's vector of ownership will also expand by the cell the player bought

    int position = player.pos->ID;
    if (Board[position].type == 0){
        if (Board[position].owner == "Bank"){
            if (player.money >= Board[position].price){
                player.money -= Board[position].price;
                Board[position].owner = player.name;
                (player.land_list).push_back(position);
                cout << ">> You have bought " << Board[position].name << " for " << Board[position].price << endl;
            }
            else{
                cout << ">> You do not have enough money to buy " << Board[position].name << endl;
            }
        }
        else{
            cout << ">>" <<Board[position].name << " is already owned by " << Board[position].owner << endl;
        }
    }
    else{
        cout << ">>" << Board[position].name << " is not a land, you cannot buy it" << endl;
    }

    //The function returns no output
}

void payrent(Cell Board[], Player &playerstep, Player &playerown){
    
    //This function intakes the board, the player that step on the cell, the player that own that cell
    //Will deduct the rent of the land from the player that step on the cell, and transfer the amount to the player who own it

    int position = playerstep.pos->ID;
    playerstep.money -= Board[position].rent * pow(2,Board[position].property);
    playerown.money += Board[position].rent* pow(2,Board[position].property);
    cout << ">> You have pay " << Board[position].rent*pow(2,Board[position].property) << " to " << playerown.name << endl;
    cout << ">> Your remaining balance is " << playerstep.money << endl;

    //The function returns no output

}

void buildproperty(Cell Board[], Player &playerstep){
    
    //This function intakes the Player and the Cell
    //Will set the price for the property, then build +1 property on the Cell

    int position = playerstep.pos->ID;
    int price;
    if(position<10){
        price = 50;
    }
    else if(position<20){
        price =100;
    }
    else if(position<30){
        price = 150;
    }
    else{
        price = 200;
    }
    if (playerstep.money>price){
        playerstep.money-=price;
        Board[position].property+=1;
        cout << ">> You have build a house on " << Board[position].name <<"!"<< endl;
        cout << ">> " << Board[position].name << " currently have " << Board[position].property << " houses." << endl;
    }
    else{
        cout << ">> You don't have enough cash for this action!" << endl;
    }

    //The function returns no output

}
