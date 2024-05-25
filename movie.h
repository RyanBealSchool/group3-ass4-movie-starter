#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "media.h"
using namespace std;

class Movie : public Media{
public:
	explicit Movie(); //default constructor
	virtual string toMediaString() const; //format the movie string shared by all children (year is different for classics)
	bool operator<(const Movie& other) const; // < operator to compare movies with a priority queue

protected:
	void initalizeMovie(const int& movieStock, const string movieDirector, const string& movieTitle, const int movieYear); //used for constuctor var assignment of children classes
	virtual void readObjFromStream(istream& stream); //virtual function used in operator>> to make reading in objects virtual

	string director;
	int year;
};
#endif