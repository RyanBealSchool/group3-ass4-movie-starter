#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
class Comedy : public Movie {
public:
	explicit Comedy(int comedyStock = 0, string comedyDirector = "", string comedyTitle = "", int comedyYear = 0); //constructor

	string toMediaString() const; //returns a string formatted as a comedy

private:
	void readObjFromStream(istream& stream); // read a comedy from the stream
};

#endif