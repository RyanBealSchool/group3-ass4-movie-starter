#pragma once
#include "movie.h"
class Drama : public Movie {
private:
  string director;
  int year;

public:
  Drama(string title, int stock, string director, int year);
  string getDirector();
  int getYear();
};
