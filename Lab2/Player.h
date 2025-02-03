#pragma once
#include <string>
#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

class Player {

	private:

		string name;
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

		void setName(string newName) {
			name = newName;
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


};

bool retainPossesion();
