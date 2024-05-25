#include "comedy.h"

Comedy::Comedy(int comedyStock, string comedyDirector, string comedyTitle, int comedyYear)
{
	 // initalize movie vars
	initalizeMovie(comedyStock, comedyDirector, comedyTitle, comedyYear);
}
string Comedy::toMediaString() const {
	//format the comedy as a string
	string result = "F, " + Movie::toMediaString() + ", " + to_string(this->year); 
	return result;
}

void Comedy::readObjFromStream(istream& stream)
{
	//read in the stock, director, and title
	Movie::readObjFromStream(stream); 
	//read in the year
	stream >> year;
}

