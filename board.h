// board.h
#ifndef BOARD_H
#define BOARD_H

#include <string>

using namespace std;

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
	        int chance_no = rand()%7
	        switch (chance_no) {
		        case 0: // advance_to_go
			        std::cout << “Chance: Advance to Go” << std::endl;
			        std::cout << “Move to Go and collect $200” << std::endl;
			        player.pos = board;
			        player.money += 200;
			        break;
		        case 1: // bank dividend
			        std::cout << “Chance: Bank Dividend” << std::endl;
			        std::cout << “Collect $50 as bank dividend” << std::endl;
			        player.money += 50;
			        break;
		        case 2: // go back 3 spaces
			        std::cout << “Chance: Go Back 3 Spaces” << std::endl;
			        std::cout << “Move backward by 3 cells” << std::endl;
			        player.pos -= 3;
			        break;
		        case 3: // tax
			        std::cout << “Chance: Tax” << std::endl;
			        std::cout << “Pay $15 as tax” << std::endl;
			        player.money -= 15
			        break;
		        case 4: // loan matures
			        std::cout << “Chance: Loan Matures” << std::endl;
			        std::cout << “Your bank loan matures, and collect $150” << std::endl;
			        player.money += 150
			        break;
		        case 5: // Release From Jail
			        std::cout << “Chance: Release From Jail” << std::endl;
			        std::cout << “Move out of jail” << std::endl;
			        if (player.pos->type == 4) {
				        player.pos++;
			        } else {
				        std::cout << “You are currently not in jail. No action is done.” << std::endl;
			        }
			        break;
                case 6: // advance to MTR Exit B
	                std::cout << “Chance: Advance to MTR Exit B” << std::endl;
	                std::cout << “Move to MTR Exit B, collect $200 if pass through GO” << std::endl;
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
