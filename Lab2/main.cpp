#include "Player.h"
#include "Game.h"
using namespace std;

int main() {
	
	Game Current_Game;

	Player Team_One[5];
	Player Opposing_Team("Team Two");

	cout << "+-------+ Welcome to the Basketball Game! +-------+\n" << endl;

	setTeamNames(Team_One);

	cout << "\n+-------+ Game Started! +-------+\n" << endl;

	Team_One[chooseRandomPlayer()].setHasPossession();

	cout << "Player with Possession: " << findPlayerWithPossession(Team_One).getName() << endl;

	while (Current_Game.getNumPossessions() > 0) {
		
		cout << "\nChoose an action:\n"
			<< "1. Shoot\n"
			<< "2. Pass\n"
			<< "3. See Player Stats\n"
			<< "4. See Score\n";

		int choice;
		cout << "\nOption: ";
		cin >> choice;
		cout << "\n";

		switch (choice) {

			case 1: {

				int shotValue;
				cout << "Enter Shot Value (1, 2, or 3): ";
				
				cin >> shotValue;
				
				Current_Game.addToTeamOne(findPlayerWithPossession(Team_One).TakeShot(shotValue));

				Current_Game.endOfPossession();

				Current_Game.addToTeamTwo(Opposing_Team.playOpposingTeamPossession());

				Current_Game.endOfPossession();

				assignNewPossession(Team_One);

				break;
			}
			case 2: {

				cout << "Choose a Player to pass too!\n" << endl;

				for (int i = 0; i < 5; i++) {
					cout << i + 1 << ". " << Team_One[i].getName() << endl;
				}

				int playerToPass;
				cout << "\nOption: ";
				cin >> playerToPass;

				if (findPlayerWithPossession(Team_One).PassBall()) {

					resetAllPossessions(Team_One);

					Team_One[playerToPass - 1].setHasPossession();

					cout << findPlayerWithPossession(Team_One).getName() << " now has possession!" << endl;
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
				cout << "+-------+ Current Player Stats +-------+ \n\n";

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
