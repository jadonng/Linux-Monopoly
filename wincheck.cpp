//wincheck.cpp
#include <iostream>
#include <string>
#include "structures.h"
#include "wincheck.h"
using namespace std;

//A function to check if player p in arr is win.
//if one of them wins, return true,
//else return false

void outloop_wincheck(Player *arr, int num_of_player){
    //const int money_to_win=1000;
    int max_amount = 0;
    vector<string> winner;
    
    for(int i = 0; i < num_of_player; i++){
        if(arr[i].money >= max_amount){
            max_amount = arr[i].money;
        } 
    }
    for(int i = 0; i < num_of_player; i++){
        if(arr[i].money == max_amount){
            winner.push_back(arr[i].name);
        }
    }
    if(winner.size()>1){
        cout << "The winners are ";
        for(int i = 0; i < winner.size(); i++){
            cout << winner[i]<< " ";
        }
        cout << endl;
    }
    else{
        cout << "The winner is "<< winner[0]<< endl;
    }
}
/*if(p1.money >= money_to_win || p2.money <= 0){
        cout<<"Player 1 wins!"<<endl;
        return true;
    }
    else if(p2.money >= money_to_win || p1.money <= 0){
        cout<<"Player 2 wins!"<<endl;
        return true;
    }
    return false;
}*/

//A function to check if player p is broke
//if so return true to eliminate player p
bool brokecheck(Player p){
    if(p.money < 0){
        cout << "Player " << p.name << " is broke." << endl;
        return true;
    }
return false;
}



