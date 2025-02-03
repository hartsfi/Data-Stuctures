#pragma once
#include <string>
#include <iostream>
#include "Player.h"
using namespace std;

class Game {

	private:

		int teamOneScore;
		int teamTwoScore;
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


};