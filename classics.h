#pragma once
#include "movie.h"
class Classics : public Movie {
private:
  string director;
  int year;
  string majorActorFirstName;
  string majorActorLastName;
  int releaseMonth;

public:
  Classics(string t, int s, string d, int m, int y, string fn, string ln);
  string getDirector();
  int getYear();
  string getMajorActorFirstName();
  string getMajorActorLastName();
  int getReleaseMonth();
};
