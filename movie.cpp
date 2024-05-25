#include "movie.h"

Movie::Movie()
{
	this->director = "";
	this->year = 0;
}

string Movie::toMediaString() const {
	string result = to_string(this->stock) + ", " + this->director + ", " + this->title; //add the stoc, director, and title to the string
	return result;
}

void Movie::initalizeMovie(const int& movieStock, const string movieDirector, const string& movieTitle, const int movieYear)
{
	initalizeMedia(movieStock, movieTitle); // inialize media vars
	this->director = movieDirector;
	this->year = movieYear;
}

void Movie::readObjFromStream(istream& stream)
{
	char skip; //to skip space while reading in
	stream >> stock; //read in the stock
	stream >> skip;
	stream >> skip;
	std::getline(stream, director, ','); //read in the director
	stream >> skip;
	stream >> skip;
	std::getline(stream, title, ','); //read in the title
}
