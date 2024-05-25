#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"
class Classic : public Movie {
public:
	explicit Classic(int classicStock = 0, string classicDirector = "", string classicTitle = "", string classicActor = "", int classicMonth = 0, int classicYear = 0); //constructor

	string toMediaString() const; //returns a string formatted as a classic

private:
	void readObjFromStream(istream& stream); // read a classic from the stream

	string actor;
	int month;
};
#endif