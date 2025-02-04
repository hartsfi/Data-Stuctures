#include "Game.h"
using namespace std;

Game::Game() : teamOneScore(0), teamTwoScore(0), numPossessions(60), possession("Unknown") {}

void Game::printScores() {

	cout << "Current Scores: \n"
		<< "Team One: " << teamOneScore << "points\n"
		<< "Team Two: " << teamTwoScore << "points\n\n"
		<< "Possesions Left: " << numPossessions << endl;
}
