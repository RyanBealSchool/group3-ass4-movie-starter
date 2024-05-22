#pragma once
#include "movie.h"
class Comedy : public Movie {
private:
  string director;
  int year;

public:
  Comedy(string title, int stock, string director, int year);
  string getDirector();
  int getYear();


};
