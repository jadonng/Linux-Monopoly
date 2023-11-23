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
    int max_amount = 0;
    vector<string> winner;
    //calculate the properties of the player
    for(int i = 0; i < num_of_player; i++){
        //add the money of player
        arr[i].properties += arr[i].money;
        if(arr[i].land_list.size()!=0){
            //add all the lands and properties on these lands
            for(int j = 0; j < arr[i].land_list.size(); j++){
                arr[i].properties += board[arr[i].land_list[j]].price + 50 * board[arr[i].land_list[j]].property;
            }
        }
        //get highest money
        if(arr[i].properties >= max_amount){
            max_amount = arr[i].properties;
        } 
    }
    //push winner(s) to the vector
    for(int i = 0; i < num_of_player; i++){
        if(arr[i].properties == max_amount){
            winner.push_back(arr[i].name);
        }
    }
    //declare the winner(s)
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


//A function to check if player p is broke
//if so return true to eliminate player p
bool brokecheck(Player p){
    if(p.money < 0){
        return true;
    }
return false;
}



