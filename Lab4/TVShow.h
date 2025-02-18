#pragma once

#include "Show.h"
#include <string>
#include <iostream>

//Episode Struct - Each carries a description of the episode
struct Episode {

	string summary;

	Episode() : summary("") {}

	Episode(string sum) : summary(sum) {}

};

class TVShow : public Show {

	protected:

		//Members to create a dynamic 2D array
		int seasonCount;
		int episodeCount;
		Episode** seasons;

	public:

		//Constructor and destructor
		TVShow(string title, string description, int seasonCount, int episodeCount);
		~TVShow();

		//Overriden Play function
		void Play() override;
	
		void Details() const;

		void addEpisode(int season, int episode, string summary);


};

