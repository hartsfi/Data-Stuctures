#include "Movie.h"

//Default and overloaded constructor implementations
Movie::Movie() : title(""), description(""), rating(0) {}

Movie::Movie(string title, string description, int rating) :
	title(title), description(description), rating(rating) {}


