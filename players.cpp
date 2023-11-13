//players.cpp
#include <vector>
#include "players.h"
#include "board.h"

struct player {
  /* Explanation:
     number:      player number, e.g. number = 1 for player 1
     *pos:	      position, e.g. pos = &board[10] if the player is at cell 10
     money:	      amount of money that the player has
     land_list:	  vector listing the index of land that the player owns,
		              (e.g., if the player purchased land at cell c3 and c19, then land_list = {3, 19})
  */
	char number;
	cell *pos;
	int money;
	std::vector<int> land_list;
};
