//wincheck.cpp
#include <iostream>
#include <string>
#include "structures.h"
#include "wincheck.h"
using namespace std;

//A function to check if p1 or p2 wins
//if one of them wins, return true,
//else return false

bool wincheck(Player arr[]){
    const int money_to_win=1000;
    bool if_game_ends = false;
    
    for(Player p : arr){
        if(p.money >= money_to_win){
        cout<<"Player " << p.name << " wins!"<<endl;
        return true;
    }
    }
    if(p1.money >= money_to_win || p2.money <= 0){
        cout<<"Player 1 wins!"<<endl;
        return true;
    }
    else if(p2.money >= money_to_win || p1.money <= 0){
        cout<<"Player 2 wins!"<<endl;
        return true;
    }
    return false;
}
