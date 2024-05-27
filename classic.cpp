#include "classic.h"

Classic::Classic(int classicStock, string classicDirector, string classicTitle,
                 string classicActor, int classicMonth, int classicYear) {
  initalizeMovie('C', classicStock, classicDirector, classicTitle,
                 classicYear); // initalize movie vars
  this->actor = classicActor;
  this->month = classicMonth;
}
string Classic::toMediaString() const {
  string result = Movie::toMediaString() + ", " + this->actor + " " +
                  to_string(this->month) + " " +
                  to_string(this->year); // format the classic as a string
  return result;
}

bool Classic::operator<(const Classic &compClassic) const {
  if (this->month < compClassic.month) {
    return true;
  } else if ((this->month == compClassic.month) &&
             (this->year < compClassic.year)) {
    return true;
  } else if ((this->month == compClassic.month) &&
             (this->year == compClassic.year) &&
             (this->actor.compare(compClassic.actor) < 0)) {
    return true;
  } else {
    return false;
  }
}
bool Classic::operator==(const Classic &compClassic) const {
  if ((this->month == compClassic.month) && (this->year == compClassic.year) &&
      (this->actor.compare(compClassic.actor) == 0)) {
    return true;
  } else {
    return false;
  }
}

void Classic::readObjFromStream(istream &stream) {
  Movie::readObjFromStream(stream); // read in the stock, director, and title
  string actorFirstName, actorLastName;
  stream >> actorFirstName >>
      actorLastName; // read in the actor's first and last name
  this->actor =
      actorFirstName + " " + actorLastName; // combine first and last names
  stream >> month >> year;                  // read in the month and year
}