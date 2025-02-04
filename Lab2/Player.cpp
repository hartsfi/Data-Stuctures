#include "Player.h"
using namespace std;

//Constructors
Player::Player(string playerName) : name(playerName), hasPossession(false), shotsTaken(0), shotsMade(0), passesAttempted(0), passesMade(0) {}

Player::Player() : name("None"), hasPossession(false), shotsTaken(0), shotsMade(0), passesAttempted(0), passesMade(0) {}

bool Player::PassBall() {

	double passingPercentage;
	srand(time(0));

	if (passesAttempted == 0 || passesMade == 0) {
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

	static bool seeded = false;
	if (!seeded) {
		srand(time(0));
		seeded = true;
	}

	bool retainBallPossession = true;

	while (retainBallPossession) {
		
		int randomNumber;
		double defaultShotPercent;

		switch (point) {
			case 1: randomNumber = rand() % 70 + 1; defaultShotPercent = 35.0; break;
			case 2: randomNumber = rand() % 100 + 1; defaultShotPercent = 50.0; break;
			case 3: randomNumber = rand() % 125 + 1; defaultShotPercent = 62.5; break;
		default: return 0;
		}

		double shootingPercentage;
		if (shotsTaken == 0 || shotsMade == 0) {
			shootingPercentage = defaultShotPercent;
		}
		else {
			shootingPercentage = (static_cast<double>(shotsMade) / shotsTaken) * 100;
		}

		shotsTaken++;

		if (randomNumber <= shootingPercentage) {
			shotsMade++;
			cout << point << "points!" << endl; 
			return point; 
		}
		else if (!retainPossession()) {
			retainBallPossession = false;
			cout << "Shot Missed and Possession Lost!" << endl;
		}
		else { cout << "Shot Missed and Possession Won Back!" << endl; }
	}

	return 0;
}

//Returns true if player maintains possesion after missed shot
bool retainPossession() {

	int randomNumber = (rand() % 100) + 1;

	cout << randomNumber << endl;

	if (randomNumber > 50) {
		return true;
	}

	return false;
}

void setTeamNames(Player Team_One[]) {

	cout << "Enter the names for Team One: " << endl;
	string playerName;

	for (int i = 0; i < 5; i++) {
		cin >> playerName;
		Team_One[i].setName(playerName);
	}
}

void Player::printStats() const{
	cout << "Name: " << name << "\n"
		<< "Has Possession? " << hasPossession << "\n"
		<< "Shots Taken: " << shotsTaken << "\n"
		<< "Shots Made: " << shotsMade << "\n"
		<< "Passes Attempted: " << passesAttempted << "\n"
		<< "Passes Made: " << passesMade << "\n"
		<< "Shooting Percentage: " << (shotsTaken == 0 ? 0 : (static_cast<double>(shotsMade) / shotsTaken) * 100) << "%\n"
		<< "Passing Percentage: " << (passesAttempted == 0 ? 0 : (static_cast<double>(passesMade) / passesAttempted) * 100) << "%\n";
}

int chooseRandomPlayer() {
	static bool seeded = false;
	if (!seeded) {
		srand(time(0)); 
		seeded = true;
	}
	
	int number = rand() % 5;  

	return number;
}

Player& findPlayerWithPossession(Player Team[]) {

	for (int i = 0; i < 5; i++) {
		if (Team[i].getPossessionStatus()) {
			return Team[i];
		}
	}
}

int Player::playOpposingTeamPossession() {

	static bool seeded = false;
	if (!seeded) {
		srand(time(0));
		seeded = true;
	}

	bool retainBallPossession = true;

	while (retainBallPossession) {

		int randomPoint = rand() % 3 + 1;
		int randomNumber = rand() % 100 + 1;
		double defaultShotPercent;

		double shootingPercentage = 60.0;

		cout << randomNumber << endl;

		if (randomNumber <= shootingPercentage) {

			cout << "Opposing Team Scored " << randomPoint << " Points!" << endl;
			return randomPoint;
		}
		else if (!retainPossession()) {
			retainBallPossession = false;
			cout << "Opposing Team Shot Missed and Possession Lost!" << endl;
		}
		else { cout << "Opposing Team Shot Missed and Possession Won Back!" << endl; }
	}

	return 0;
}

void printWholeTeamStats(Player Team[]) {

	for (int i = 0; i < 5; i++) {
		Team[i].printStats();
		cout << "\n";
	}
}

void assignNewPossession(Player Team[]) {

	resetAllPossessions(Team);

	Team[chooseRandomPlayer()].setHasPossession();

	Player newPlayer = findPlayerWithPossession(Team);

	cout << "Player Now Has Possession: " << newPlayer.getName() << endl;
}

void resetAllPossessions(Player Team[]) {
	for (int i = 0; i < 5; i++) {
		Team[i].removeHasPossession(); 
	}
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
