//wincheck.cpp
#include <iostream>
#include <string>
#include "structures.h"
#include "wincheck.h"
using namespace std;

//A function to check if p1 or p2 wins
//if one of them wins, return true,
//else return false

bool wincheck(Player p1, Player p2){
    const int money_to_win=1000;
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
