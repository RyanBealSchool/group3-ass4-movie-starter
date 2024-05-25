#ifndef INVENTORY_H
#define INVENTORY_H
#include "hash_table.h"
#include "movie.h"
#include "media.h"
#include <iostream>
#include <queue>
#include <string>

class Inventory {
private:
  //priority_queue<Media> sortedMovies;
  HashTable hashTable;

public:
  void addMovie(Media *m);
  Media *findMovie(string title);
};
#endif
