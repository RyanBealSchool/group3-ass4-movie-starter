#include "drama.h"

Drama::Drama(int dramaStock, string dramaDirector, string dramaTitle, int dramaYear)
{
	initalizeMovie(dramaStock, dramaDirector, dramaTitle, dramaYear); // initalize movie vars
}
string Drama::toMediaString() const {
	string result = "D, " + Movie::toMediaString() + ", " + to_string(this->year); //format the drama as a string
	return result;
}

void Drama::readObjFromStream(istream& stream)
{
	Movie::readObjFromStream(stream); //read in the stock, director, and title
	stream >> year;//read in the year
}

