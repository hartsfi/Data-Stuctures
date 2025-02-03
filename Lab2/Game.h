#pragma once
#include <string>
#include <iostream>
#include "Player.h"
using namespace std;

class Game {

	private:

		int teamOneScore;
		int teamTwoScore;
		Player Team_One[5];
		Player Team_Two[5];
		string possesion;

	public:

		Game();

		int getTeamOneScore() {
			return teamOneScore;
		}

		int getTeamTwoScore() {
			return teamTwoScore;
		}

		string getPossesion() {
			return possesion;
		}

		void setTeamNames();

};