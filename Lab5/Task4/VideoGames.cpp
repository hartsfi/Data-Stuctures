#include "VideoGames.h"

//Constructor implementations
VideoGames::VideoGames() : rating(0) {} 

VideoGames::VideoGames(string title, string description, int rating) :
	title(title), description(description), rating(rating) {}

