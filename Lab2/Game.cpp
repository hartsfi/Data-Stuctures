#include "Game.h"
using namespace std;

Game::Game() : teamOneScore(0), teamTwoScore(0), numPossessions(60) {}

void Game::printScores() {

	cout << "+-------+ Current Scores +-------+\n\n"
		<< "Team One: " << teamOneScore << "points\n"
		<< "Team Two: " << teamTwoScore << "points\n"
		<< "Possesions Left: " << numPossessions << "\n"
		<< "\n+-------+ +------------+ +-------+\n";
}
