// structures.h
#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
struct Player;
struct Cell;

struct Player{
  /* Explanation:
     number:    player number, e.g. number = 1 for player 1
     *pos:      position, e.g. pos = &board[10] if the player is at cell 10
     money:     amount of money that the player has
     land_list: vector listing the index of land that the player owns,
                (e.g., if the player purchased land at cell c3 and c19, then land_list = {3, 19})
  */
	int number;
	string name;
	Cell *pos;
	double money;
	vector<int> land_list;
	int num_card;           //number of card the player got
	bool in_jail = false;   //if the player is in jail now
	bool can_buy_land_or_properties;
};

struct Cell{
    int ID;         //Location(0-39)
    int type;       //(0 = Land, 1 = Starting Point, 2 = Punishment, 3 = Chance, 4 = Jail, 5 = Go to Jail, 6 = NULL)
    string name; 
    int price;      // -1 if not Land
    int rent;       // -1 if not land
	int property;
    string owner;   // Normalized to Bank Owned
};

void TriggerEvent(Player &player, Cell board[], Player player_array[])

#endif
