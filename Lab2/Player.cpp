#include "Player.h"
using namespace std;

//Constructors
Player::Player(string playerName) : name(playerName), shotsTaken(0), shotsMade(0), passesAttempted(0), passesMade(0) {}

Player::Player() : name("None"), shotsTaken(0), shotsMade(0), passesAttempted(0), passesMade(0) {}

bool Player::PassBall() {

	double passingPercentage;
	srand(time(0));

	if (passesAttempted == 0) {
		passingPercentage = 50;
	}
	else {
		passingPercentage = (passesMade / passesAttempted) * 100;
	}
	
	int randomNumber = (rand() % 100) + 1;

	if (randomNumber <= passingPercentage) {

		passesMade++;
		passesAttempted++;

		cout << "Pass Successful" << endl;

		return true;
	}
	else {

		passesAttempted++;

		cout << "Pass Unsuccessful" << endl;

		return false;
	}
}

int Player::TakeShot(int point) {

	double shootingPercentage;
	bool reatinBallPossesion = true;
	srand(time(0));

	while (reatinBallPossesion) {

		if (shotsTaken == 0 || shotsMade == 0) {
			shootingPercentage = 50;
		}
		else {
			shootingPercentage = (shotsMade / shotsTaken) * 100;
		}

		if (point == 1) {

			int randomNumberOne = (rand() % 70) + 1;

			if (randomNumberOne <= shootingPercentage) {
				shotsMade++;
				shotsTaken++;
				cout << "One Point Scored!" << endl;
				return 1;
			}

			shotsTaken++;

		}
		else if (point == 2) {

			int randomNumberTwo = (rand() % 100) + 1;

			if (randomNumberTwo <= shootingPercentage) {
				shotsMade++;
				shotsTaken++;
				cout << "Two Point Scored!" << endl;
				return 2;
			}

			shotsTaken++;

		}
		else if (point == 3) {

			int randomNumberThree = (rand() % 125) + 1;

			if (randomNumberThree <= shootingPercentage) {
				shotsMade++;
				shotsTaken++;
				cout << "Three Point Scored!" << endl;
				return 3;
			}

			shotsTaken++;

		}

		if (!retainPossesion()) { 
			reatinBallPossesion = false;
			cout << "Possesion Lost!" << endl;
		}
		else { cout << "Possesion Won Back!" << endl; }

	}

	return 0;
}

void Player::addShotTaken() {
	shotsTaken++;
}

void Player::addShotMade() {
	shotsMade++;
}

void Player::addPassAttempted() {
	passesAttempted++;
}

void Player::addPassMade() {
	passesMade++;
}

//Returns true if player maintains possesion after missed shot
bool retainPossesion() {

	srand(time(0));
	int randomNumber = (rand() % 100) + 1;

	if (randomNumber > 50) {
		return true;
	}

	return false;
}