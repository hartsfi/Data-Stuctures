#pragma once
#include <string>
#include <iostream>
#include "Player.h"
using namespace std;

class Game {

	private:

		int teamOneScore;
		int teamTwoScore;
		int numPossessions;
		string possession;

	public:

		Game();

		int getTeamOneScore() {
			return teamOneScore;
		}

		int getTeamTwoScore() {
			return teamTwoScore;
		}

		int getNumPossessions() {
			return numPossessions;
		}

		string getPossession() {
			return possession;
		}

		void endOfPossession() {
			numPossessions--;
		}

		void addToTeamOne(int point) {
			teamOneScore += point;
		}

		void addToTeamTwo(int point) {
			teamTwoScore += point;
		}

		void printScores();

};

