//structures.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "structures.h"
#include "action.h"

using namespace std;

void TriggerEvent(Player &player, Cell board[], Player player_array[], int num_of_player) {
        switch (player.pos -> type) {
	case 0:
            	// event to be triggered if player land on land
		//if the land is owned by player
		if(player.pos -> owner == player.name){
			cout << ">> You have arrived " << player.pos -> name << " which is owned by you with the rent of " << board[player.pos->ID].rent*pow(2,board[player.pos->ID].property) <<endl;
			player.can_buy_land_or_properties = true;
		}
		//if the land is owned by bank
		else if(player.pos -> owner == "Bank"){
			cout << ">> You have arrived " << player.pos -> name << " which has no owner with the price of " << player.pos -> price << endl; 
			player.can_buy_land_or_properties = true;
		}
		//if the land is owned by other player
		else{
			cout << ">> You have arrived " << player.pos -> name << " which is owned by " << player.pos -> owner << " with the rent of " << board[player.pos->ID].rent*pow(2,board[player.pos->ID].property) <<endl;
			player.can_buy_land_or_properties = false;
			//cout << ">> You have to pay " << player.pos -> rent << " to " << player.pos -> owner << endl;
			for(int i=0; i<num_of_player; i++){
    				Player& p = player_array[i];
    				if(p.name == player.pos->owner){
      					payrent(board, player, p);
      				}
			}
		}
		break;
        case 1: 
	        // event to be triggered if player land on starting
		cout << ">> You have arrived the starting point; welcome back!" << endl;
		break;
        case 2: 
	        // event to be triggered if player land on punishment
		int tax;
		//if income_tax
		if(player.pos -> name == "Income_Tax"){
			int income_tax = 20;
			tax = income_tax;
		}
		//if luxury_tax
		else if(player.pos -> name == "Luxury_Tax"){
			int luxury_tax = 25;
			tax = luxury_tax;
		}	
		cout << ">> You need to pay " << tax << " for the " << player.pos -> name << endl;
		player.money -= tax;
		break;
	case 3: {
	        // event to be triggered if player land on chance
	        srand(time(NULL));
	        int chance_no = rand()%6+1;
	        switch (chance_no) {
		        case 0: // advance_to_go
			        cout << ">> Chance: Advance to Go" << endl;
			        cout << ">> Move to Go and collect $200" << endl;
			        player.pos = board;
			        player.money += 200;
			        break;
		        case 1: // bank dividend
			        cout << ">> Chance: Bank Dividend" << endl;
			        cout << ">> Collect $50 as bank dividend" << endl;
			        player.money += 50;
			        break;
		        case 2: // go back 3 spaces
			        cout << ">> Chance: Go Back 3 Spaces" << endl;
			        cout << ">> Move backward by 3 cells" << endl;
			        player.pos -= 3;
				TriggerEvent(player, board, player_array, num_of_player);
			        break;
		        case 3: // tax
			        cout << ">> Chance: Tax" << endl;
			        cout << ">> Pay $15 as tax" << endl;
			        player.money -= 15;
			        break;
		        case 4: // loan matures
			        cout << ">> Chance: Loan Matures" << endl;
			        cout << ">> Your bank loan matures, and collect $150" << endl;
			        player.money += 150;
			        break;
		        case 5: // Release From Jail
			        cout << ">> Chance: Release From Jail" << endl;
			        cout << ">> You get a jail card to have a chance to be released from the jail!" << endl;
			        player.num_card++;
			        break;
      		        case 6: // advance to MTR Exit B
	                	cout << ">> Chance: Advance to MTR Exit B" << endl;
	        	        cout << ">> Move to MTR Exit B, collect $200 if pass through GO" << endl;
                    		if (player.pos > &board[25]) { // pass through GO
                        		player.money += 200;
                    		}
                    		player.pos = &board[25];
				TriggerEvent(player, board, player_array, num_of_player);
                    		break;
	            }
		    break;
	}
        case 4:
		// event to be triggered if player land on jail
		//if the player was sent to jail last time and skipped a rolling dice
		if(player.in_jail){
			player.in_jail = false;
		}
		//move to the jail with rolling dice
		else{
			cout << ">> You arrive in jail. Nothing happens." << endl;
		}
		break;
        case 5:
		// event to be triggered if player land on go to jail
		cout << ">> You have encountered legal cases. Now it's time to go to the jail." << endl;
		//if has card could choose to use or not
		if(player.num_card){
			cout << ">> You have got " << player.num_card << " jail card(s)." << endl;
		}
		//if no card, just arrested
		else{
			cout << ">> You are in jail now, rest for one turn." << endl;
			player.pos = &board[10];//send to jail
			player.in_jail = true;
		}
		break;
        }
}
