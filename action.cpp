//action.cpp
#include <iostream>
#include <string>
#include "structures.h"
#include "action.h"
#include <cmath>

using namespace std;
void buy(Cell Board[40], Player player){
    int position = player.pos->ID;
    if (Board[position].type == 0){
        if (Board[position].owner == "Bank"){
            if (player.money >= Board[position].price){
                player.money -= Board[position].price;
                Board[position].owner = player.name;
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
}

void payrent(Cell Board[40], Player playerstep, Player playerown){
    int position = playerstep.pos->ID;
    playerstep.money -= Board[position].rent * pow(2,Board[position].property);
    playerown.money += Board[position].rent* pow(2,Board[position].property);
    cout << ">> You have pay " << Board[position].rent*pow(2,Board[position].property) << " to " << playerown.number << endl;
    cout << ">> Your remaining balance is " << playerstep.money << endl;
}

void buildproperty(Cell Board[40], Player playerstep){
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
        cout << ">> " << Board[position].name << "currently have " << Board[position].property << " houses." << endl;
    }
    else{
        cout << ">> You don't have enough cash for this action!" << endl;
    }
};
