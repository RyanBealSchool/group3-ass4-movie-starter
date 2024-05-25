#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
class Drama : public Movie {
public:
	explicit Drama(int dramaStock = 0, string dramaDirector = "", string dramaTitle = "", int dramaYear = 0); //constructor

	string toMediaString() const; //returns a string formatted as a drama

	bool operator<(const Drama& compDrama) const; //compare if this Drama is less than the passed in
	bool operator==(const Drama& compDrama) const; //compare if this Drama is greater than the passed in
private:
	void readObjFromStream(istream& stream); // read a drama from the stream
};

#endif