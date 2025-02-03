#include "Player.h"
using namespace std;

//Constructors
Player::Player(string playerName) : name(playerName), shotsTaken(0), shotsMade(0), passesAttempted(0), passesMade(0) {}

bool Player::PassBall() {

	double passingPercentage;

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
		return true;
	}
	else {
		passesAttempted;
		return false;
	}
}

int Player::TakeShot(int point) {

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