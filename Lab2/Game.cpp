#include "Game.h"
using namespace std;

Game::Game() : teamOneScore(0), teamTwoScore(0), possesion("Unknown") {}


void Game::setTeamNames() {

	cout << "Enter the names for Team One: " << endl;
	string playerName;

	for (int i = 0; i < 5; i++) {
		cin >> playerName;
		Team_One[i].setName(playerName);
	}

	cout << "Enter the names for Team Two: " << endl;

	for (int i = 0; i < 5; i++) {
		cin >> playerName;
		Team_Two[i].setName(playerName);
	}

}