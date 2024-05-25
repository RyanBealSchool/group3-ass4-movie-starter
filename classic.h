#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"
class Classic : public Movie {
public:
	explicit Classic(int classicStock = 0, string classicDirector = "", string classicTitle = "", string classicActor = "", int classicMonth = 0, int classicYear = 0); //constructor

	string toMediaString() const; //returns a string formatted as a classic

	bool operator<(const Classic& compClassic) const; //compare if this Classic is less than the passed in
	bool operator==(const Classic& compClassic) const; //compare if this Classic is greater than the passed in

private:
	void readObjFromStream(istream& stream); // read a classic from the stream

	string actor;
	int month;
};
#endif