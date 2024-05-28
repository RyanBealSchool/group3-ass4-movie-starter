#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
class Comedy : public Movie {
private:
	void readObjFromStream(istream& stream); // read a comedy from the stream
public:
	explicit Comedy(int comedyStock = 0, string comedyDirector = "", string comedyTitle = "", int comedyYear = 0); //constructor

	string toMediaString() const; //returns a string formatted as a comedy

	bool operator<(const Comedy& compCom) const; //compare if this comedy is less than the passed in
	bool operator==(const Comedy& compCom) const; //compare if this comedy is greater than the passed in
};

#endif