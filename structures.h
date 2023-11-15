// structures.h
#ifndef STRUCT_H
#define STRUCT_H

#include <string>
#include <vector>

using namespace std;

struct Player{
  /* Explanation:
     number:    player number, e.g. number = 1 for player 1
     *pos:      position, e.g. pos = &board[10] if the player is at cell 10
     money:     amount of money that the player has
     land_list: vector listing the index of land that the player owns,
                (e.g., if the player purchased land at cell c3 and c19, then land_list = {3, 19})
  */
	char number;
	string name;
	Cell *pos;
	int money;
	vector<int> land_list;
	bool has_card;
};

struct Cell{
    int ID;         //Location(0-39)
    int type;       //(0 = Land, 1 = Starting Point, 2 = Punishment, 3 = Chance, 4 = Jail, 5 = Go to Jail, 6 = NULL)
    string name; 
    int price;      // -1 if not Land
    int rent;       // -1 if not land
    string owner;   // Normalized to Bank Owned
    void TriggerEvent(Player &player, Cell board[]) {
        switch (type) {
	        case 0:
            // event to be triggered if player land on land
            case 1: 
	        // event to be triggered if player land on starting
            case 2: 
	        // event to be triggered if player land on punishment
            case 3: 
	        // event to be triggered if player land on chance
	        srand(time(NULL));
	        int chance_no = rand()%6+1;
	        switch (chance_no) {
		        case 0: // advance_to_go
			        cout << "Chance: Advance to Go" << endl;
			        cout << "Move to Go and collect $200" << endl;
			        player.pos = board;
			        player.money += 200;
			        break;
		        case 1: // bank dividend
			        cout << "Chance: Bank Dividend" << endl;
			        cout << "Collect $50 as bank dividend" << endl;
			        player.money += 50;
			        break;
		        case 2: // go back 3 spaces
			        cout << "Chance: Go Back 3 Spaces" << endl;
			        cout << "Move backward by 3 cells" << endl;
			        player.pos -= 3;
			        break;
		        case 3: // tax
			        cout << "Chance: Tax" << endl;
			        cout << "Pay $15 as tax" << endl;
			        player.money -= 15;
			        break;
		        case 4: // loan matures
			        cout << "Chance: Loan Matures" << endl;
			        cout << "Your bank loan matures, and collect $150" << endl;
			        player.money += 150;
			        break;
		        case 5: // Release From Jail
			        cout << "Chance: Release From Jail" << endl;
			        cout << "Move out of jail" << endl;
			        if (player.pos->type == 4) {
				        player.pos++;
			        } else {
				        cout << "You are currently not in jail. No action is done." << endl;
			        }
			        break;
      		          case 6: // advance to MTR Exit B
	                	cout << "Chance: Advance to MTR Exit B" << endl;
	        	        cout << "Move to MTR Exit B, collect $200 if pass through GO" << endl;
                    		if (player.pos > &board[26]) { // pass through GO
                        		player.money += 200;
                    		}
                    		player.pos = &board[26];
                    		break;
	            }
            case 4:
	        // event to be triggered if player land on jail
            case 5:
	        // event to be triggered if player land on go to jail
        }
    }
};

void loadBoard(Cell Board[40]);

#endif
