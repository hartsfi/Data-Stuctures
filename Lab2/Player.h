#pragma once
#include <string>
#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

class Player {

	private:

		string name;
		bool hasPossession;
		int shotsTaken;
		int shotsMade;
		int passesAttempted;
		int passesMade;

	public:

		Player(string name);

		Player();

		bool PassBall();

		int TakeShot(int point);

		void addShotTaken();

		void addShotMade();

		void addPassAttempted();

		void addPassMade();
		
		void printStats() const;

		void setName(string newName) {
			name = newName;
		}

		void setHasPossession() {
			hasPossession = true;
		}

		void removeHasPossession() {
			hasPossession = false;
		}

		string getName() {
			return name;
		}

		int getShotsTaken() {
			return shotsTaken;
		}

		int getShotMade() {
			return shotsMade;
		}

		int getPassAttempted() {
			return passesAttempted;
		}

		int getPassMade() {
			return passesMade;
		}

		bool getPossessionStatus() {
			return hasPossession;
		}

		int playOpposingTeamPossession();

};

bool retainPossession();

void setTeamNames(Player Team_One[]);

int chooseRandomPlayer();

Player& findPlayerWithPossession(Player Team[]);

void printWholeTeamStats(Player Team[]);

void assignNewPossession(Player Team[]);

void resetAllPossessions(Player Team[]);

