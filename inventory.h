#ifndef INVENTORY_H
#define INVENTORY_H
#include "hash_table.h"
#include "movie.h"
#include <iostream>
#include <queue>
#include <string>

class Inventory {
private:
  priority_queue<Movie> sortedMovies;
  HashTable hashTable;

public:
  void addMovie(Movie *m);
  Movie *findMovie(std::string title);
};
#endif
