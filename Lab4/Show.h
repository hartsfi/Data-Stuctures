#pragma once

#include <string>
#include <iostream>

using namespace std;

class Show {


	//Protected because our derived classes need direct access
	protected:

		string title;
		string description;

	public:

		//Constructor Declarations
		Show();
		Show(string title, string description);

		//Member Getters and Setters
		string getTitle() { return title; }
		string getDescription() { return description; }

		void setTitle(string newTitle) { title = newTitle; }
		void setDescription(string newDescription) { description = newDescription; }

		//Pure virtual function
		virtual void Play() = 0;

		void Details() const;

};
