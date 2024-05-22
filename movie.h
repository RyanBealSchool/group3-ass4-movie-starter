#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
using namespace std;

class Movie {

private:
  string title;
  int stock;
  bool borrowed;

public:
  Movie(string t, int s);
  string getTitle();
  int getStock();
  int getBorrowed();
  void setStock(int s);
  void setBorrowed(int b);
};
#endif
