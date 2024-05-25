#include "comedy.h"

Comedy::Comedy(int comedyStock, string comedyDirector, string comedyTitle, int comedyYear)
{
	initalizeMovie(comedyStock, comedyDirector, comedyTitle, comedyYear); // initalize movie vars
}
string Comedy::toMediaString() const {
	string result = "F, " + Movie::toMediaString() + ", " + to_string(this->year); //format the comedy as a string
	return result;
}

void Comedy::readObjFromStream(istream& stream)
{
	Movie::readObjFromStream(stream); //read in the stock, director, and title
	stream >> year;//read in the year
}

