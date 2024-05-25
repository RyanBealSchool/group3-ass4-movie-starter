#include "classic.h"

Classic::Classic(int classicStock, string classicDirector, string classicTitle, string classicActor, int classicMonth, int classicYear)
{
	initalizeMovie(classicStock, classicDirector, classicTitle, classicYear); // initalize movie vars
	this->actor = classicActor;
	this->month = classicMonth;
}
string Classic::toMediaString() const {
	string result = "C, " + Movie::toMediaString() + ", " + this->actor +" " + to_string(this->month) + " " + to_string(this->year); //format the classic as a string
	return result;
}

void Classic::readObjFromStream(istream& stream)
{
	char skip; //to skip space while reading in
	string actorLastName;
	Movie::readObjFromStream(stream); //read in the stock, director, and title
	stream >> skip;
	stream >> skip;
	std::getline(stream, this->actor, ' '); //read in the actor first name
	stream >> skip;
	std::getline(stream, actorLastName, ' '); //read in the actor last name
	this->actor += " " + actorLastName;
	stream >> month; //read in the month
	stream >> year; // read in the year
}

