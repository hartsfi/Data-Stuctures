#include "Player.h"
#include "Game.h"
using namespace std;

int main() {
	
	Game Current_Game;

	Player Team_One[5];
	Player Opposing_Team("Team Two");

	setTeamNames(Team_One);

	Team_One[chooseRandomPlayer()].setHasPossession();

	cout << "\nPlayer with Possession: " << findPlayerWithPossession(Team_One).getName() << "\n" << endl;

	while (Current_Game.getNumPossessions() > 0) {
		
		cout << "Choose an action:\n"
			<< "1. Shoot\n"
			<< "2. Pass\n"
			<< "3. See Player Stats\n"
			<< "4. See Score\n";

		int choice;
		cin >> choice;
		cout << "\n";

		switch (choice) {

			case 1: {

				int shotValue;
				cout << "Enter Shot Value (1, 2, or 3): ";
				
				cin >> shotValue;
				cout << "\n" << endl;
				
				Current_Game.addToTeamOne(findPlayerWithPossession(Team_One).TakeShot(shotValue));

				Current_Game.endOfPossession();

				Current_Game.addToTeamTwo(Opposing_Team.playOpposingTeamPossession());

				Current_Game.endOfPossession();

				assignNewPossession(Team_One);

				break;
			}
			case 2: {

				for (int i = 0; i < 5; i++) {
					cout << i + 1 << ". " << Team_One[i].getName() << endl;
				}

				int playerToPass;
				cin >> playerToPass;

				if (findPlayerWithPossession(Team_One).PassBall()) {

					resetAllPossessions(Team_One);

					Team_One[playerToPass - 1].setHasPossession();

					cout << findPlayerWithPossession(Team_One).getName() << " now has possession!\n" << endl;
				}
				else {

					Current_Game.addToTeamTwo(Opposing_Team.playOpposingTeamPossession());

					Current_Game.endOfPossession();

					Current_Game.endOfPossession();

					assignNewPossession(Team_One);

				}
				break;
			}
			case 3: {

				printWholeTeamStats(Team_One);

				break;

			}
			case 4: {

				Current_Game.printScores();

				break;
			}
			default: {

				cout << "Invalid Choice\n" << endl;
				break;

			}
		}

	}

	int teamOneFinalScore = Current_Game.getTeamOneScore();

	int teamTwoFinalScore = Current_Game.getTeamTwoScore();

	cout << "\n---GAME OVER---!\n" << endl;

	cout << "Final Score: " << teamOneFinalScore << " - " << teamTwoFinalScore << "\n" << endl;

	if (teamOneFinalScore > teamTwoFinalScore) {
		cout << "Team One Wins!" << endl;
	}
	else if (teamOneFinalScore == teamTwoFinalScore) {
		cout << "Both Teams Tied!" << endl;
	}
	else {
		cout << "Team Two Wins!" << endl;
	}

	return 0;
}
