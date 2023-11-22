//wincheck.cpp
#include <iostream>
#include <string>
#include <vector>
#include "structures.h"
#include "wincheck.h"
using namespace std;

//A function to check which player in arr is a win after specific rounds
//print the name(s) of the winner(s)


void outloop_wincheck(Player *arr, int num_of_player, Cell board[]){
    //const int money_to_win=1000;
    int max_amount = 0;
    vector<string> winner;
    
    for(int i = 0; i < num_of_player; i++){
        arr[i].properties += arr[i].money;
        if(arr[i].land_list.size()!=0){
            for(int j = 0; j < arr[i].land_list.size(); j++){
                arr[i].properties += board[arr[i].land_list[j]].price + 50 * board[arr[i].land_list[j]].property;
            }
            cout<< arr[i].properties<<endl;
        }

        if(arr[i].properties >= max_amount){
            max_amount = arr[i].properties;
        } 
    }
    for(int i = 0; i < num_of_player; i++){
        if(arr[i].properties == max_amount){
            winner.push_back(arr[i].name);
        }
    }
    if(winner.size()>1){
        cout << ">> The winners are ";
        for(int i = 0; i < winner.size(); i++){
            cout << winner[i]<< " ";
        }
        cout << endl;
    }
    else{
        cout << ">> The winner is "<< winner[0]<< endl;
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
        //cout << ">> Player " << p.name << " is broke." << endl;
        return true;
    }
return false;
}



