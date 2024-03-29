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
    cout<<">> Player: "<<p.name<<"\n"<<">> Your Position: "<<p.pos -> ID<<" "<<p.pos->name<<"\n"<<">> Your Money: "<<p.money<<"\n";
    cout<<">> Jail card: "<<p.num_card<<endl;
    if(p.land_list.size()==0){
        cout<<">> You have no land yet."<<endl;
    }
    else{
        cout<<">> Your Land(properties): ";
        for(int i : p.land_list) {
            cout<<board[i].name<< "("<<board[i].property<<")";
            cout<<" ";
        }
        cout<<"\n";
    }
}


