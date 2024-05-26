#include "movie.h"

Movie::Movie()
{
	this->director = "";
	this->year = 0;
}

string Movie::toMediaString() const {
	string result = type + ", " + to_string(this->stock) + ", " + this->director + ", " + this->title; //add the stoc, director, and title to the string
	return result;
}

bool Movie::operator<(const Movie& compMovie) const{
	if (this->type == 'F') {
		return false;
	}
	else if (compMovie.type == 'F'){
		return true;
	}
	else if (this->type == 'D') {
		return false;
	}
	else if (compMovie.type == 'D'){
		return true;
	}
	else {
		return false;
	}

}
bool Movie::operator==(const Movie& compMovie) const{
	if (this->type == compMovie.type){
		return true;
	}
	else{
		return false;
	}
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
	stream >> type; // read in the movie type
	stream >> stock; //read in the stock
	stream >> skip;
	stream >> skip;
	std::getline(stream, director, ','); //read in the director
	stream >> skip;
	stream >> skip;
	std::getline(stream, title, ','); //read in the title
}
