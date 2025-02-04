#include "Player.h"
#include "Game.h"
using namespace std;

int main() {
	
	Game Current_Game;

	Player Team_One[5];
	Player Opposing_Team("Team Two");

	setTeamNames(Team_One);

	Team_One[chooseRandomPlayer()].setHasPossession();

	Player& current_player = findPlayerWithPossession(Team_One);

	cout << "\nPlayer with Possession: " << current_player.getName() << endl;

	while (Current_Game.getNumPossessions() != 0) {
		
		cout << "Choose an action:\n"
			<< "1. Shoot\n"
			<< "2. Pass\n"
			<< "3. See Player Stats\n"
			<< "4. See Score\n";

		int choice;
		cin >> choice;

		switch (choice) {

			case 1: {

				int shotValue;
				cout << "Enter Shot Value (1, 2, or 3): ";
				
				cin >> shotValue;
				
				Current_Game.addToTeamOne(current_player.TakeShot(shotValue));

				Current_Game.endOfPossession();

				Current_Game.addToTeamTwo(Opposing_Team.playOpposingTeamPossession());

				Current_Game.endOfPossession();

				assignNewPossession(Team_One);

				Current_Game.printScores();

				break;
			}
			case 2: {

				//choose player to pass

				for (int i = 0; i < 5; i++) {
					cout << i + 1 << ". " << Team_One[i].getName() << endl;;
					cout << "\n";
				}

				int playerToPass;
				cin >> playerToPass;

				if (current_player.PassBall()) {

					resetAllPossessions(Team_One);

					current_player.removeHasPossession();

					Team_One[playerToPass - 1].setHasPossession();

					current_player = Team_One[playerToPass - 1];

					cout << current_player.getName() << " now has possession!" << endl;
				}
				else {

					Current_Game.addToTeamTwo(Opposing_Team.playOpposingTeamPossession());

					Current_Game.endOfPossession();

					Current_Game.endOfPossession();

					assignNewPossession(Team_One);

					Current_Game.printScores();
				}
				break;
			}
			case 3: {

				printWholeTeamStats(Team_One);

				break;

			}
			case 4: {

			}
			default: {

			}
		}

		

	}
	

	return 0;
}
