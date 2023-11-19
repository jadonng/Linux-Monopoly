//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "structures.h"
using namespace std;

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

#endif
