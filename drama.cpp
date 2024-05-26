#include "drama.h"

Drama::Drama(int dramaStock, string dramaDirector, string dramaTitle, int dramaYear)
{
	initalizeMovie('D', dramaStock, dramaDirector, dramaTitle, dramaYear); // initalize movie vars
}
string Drama::toMediaString() const {
	string result = Movie::toMediaString() + ", " + to_string(this->year); //format the drama as a string
	return result;
}

bool Drama::operator<(const Drama& compDrama) const{
	if (this->director.compare(compDrama.director) < 0) {
		return true;
	}
	else if ((this->director.compare(compDrama.director) == 0) && (this->title.compare(compDrama.title) < 0)) {
		return true;
	}
	else {
		return false;
	}
}
	
bool Drama::operator==(const Drama& compDrama) const{
	if ((this->director.compare(compDrama.director) == 0) && (this->title.compare(compDrama.title) == 0)) {
		return true;
	}
	else{
		return false;
	}
}

void Drama::readObjFromStream(istream& stream)
{
	Movie::readObjFromStream(stream); //read in the stock, director, and title
	stream >> year;//read in the year
}

