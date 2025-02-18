#pragma once

#include "Show.h"
#include <string>
#include <iostream>

class Movie : public Show {

	protected:

		double Rating;

	public:

		//Constructors
		Movie();
		Movie(string title, string description, double rating);

		//Overriden Play function
		void Play() override;

		//Member Getters and Setters
		double getRating() { return Rating; }
		void setRating(double newRating) { Rating = newRating; }


};
