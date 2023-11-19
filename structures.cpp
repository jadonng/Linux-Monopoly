//structures.cpp
using namespace std;

void TriggerEvent(Player &player, Cell board[], Player player_array[]) {
        switch (type) {
	        case 0:
            	// event to be triggered if player land on land
		//if the land is owned by player
		if(player.pos -> owner == player.name){
			cout << "You have arrived " << player.pos -> name << " which is owned by you with the rent of " << player.pos -> rent <<endl;
			player.can_buy_land_or_properties = true;
		}
		//if the land is owned by bank
		else if(player.pos -> owner == "bank"){
			cout << "You have arrived " << player.pos -> name << " which has no owner with the price of " << player.pos -> price << endl; 
			player.can_buy_land_or_properties = true;
		}
		//if the land is owned by other player
		else{
			cout << "You have arrived " << player.pos -> name << " which is owned by " << player.pos -> owner << " with the rent of " << player.pos -> rent <<endl;
			player.can_buy_land_or_properties = false;
			cout << "You have to pay " << player.pos -> rent << " to " << player.pos -> name << endl;
			for(Player &p : player_array){
				if(p.name == player.pos -> owner){
					payrent(board, player, p);
				}
			}
		}
		break;
            case 1: 
	        // event to be triggered if player land on starting
		cout << "You have arrived the starting point; welcome back!" << endl;
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
		cout << "You need to pay " << tax << " for the " << player.pos -> name << endl;
		player.money -= tax;


           case 4:
          	        // event to be triggered if player land on jail
          		//if the player was sent to jail last time and skipped a rolling dice
          		if(player.in_jail){
          			cout << "Now you are released, you can move next turn!" << endl;
          			player.in_jail = false;
          		}
          		//move to the jail with rolling dice
          		else{
          			cout << "You arrive on jail. Nothing happens." << endl;
          		}
          		break;
                      case 5:
          	        // event to be triggered if player land on go to jail
          		cout << "You have encountered legal cases, now it's time to go to the jail." << endl;
          		//if has card could choose to use or not
          		if(player.num_card){
          			cout << "You have got " << player.num_card << " jail card(s)." << endl;
          		}
          		//if no card, just arrested
          		else{
          			cout << "You are in jail now, rest for one turn." << endl;
          			player.pos = &board[20];//send to jail
          			player.in_jail = true;
          		}
          		break;
                  }
              }
