//checkstatus.cpp
#include <iostream>
#include <string>
#include <vector>
#include "structures.h"
#include "checkstatus.h"
using namespace std;

// A function to check the player's status,
// print out player's name, position, money, and lands
void checkstatus(Player p, Cell board[]){
    cout<<"Player: "<<p.name<<"\n"<<"Your Position: "<<p.pos -> ID<<"\n"<<"Your Money: "<<p.money<<"\n";
    cout<<"Your Land: ";
    for(int i : p.land_list) {
        cout<<board[i].name;
        cout<<" ";
    }
    cout<<"\n";
}


